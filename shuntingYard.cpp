

#include "shuntingYard.h"

using namespace std;


bool shuntingYard::isPrior(const char stack, const char token) { //asking if stack prior to token.
    if (stack == '+' || stack == '-' || stack == '(' || stack == ')') { //no way that stack is prior.
        return false;
    }
    //stack = * , /
    if (token == '+' || token == '-') {
        return true;
    }
    //token also * /
    return false;
}

bool shuntingYard::isOperator(const char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool shuntingYard::isOperator(const std::string str) {
    return (str == "+" || str == "-" || str == "/" || str == "*");
}

std::string shuntingYard::check_minuses(std::string str) {
    bool wasOperator = false;
    int len = str.length();
    for (int i = 0; i < str.length(); i++) {
        if (isOperator(str.at(i))) {
            if (str.at(i) == '-') {
                if (wasOperator || i == 0) {
                    string temp1 = str.substr(0, i);
                    string temp2 = str.substr(i, str.length() - i);
                    str = temp1 + "(0" + temp2;
                    if (str.at(i + 3) == '(') { // i points on (.
                        int counter = 1;
                        int j = i + 3;
                        while (counter != 0) {
                            j++;
                            if (str.at(j) == '(') { counter++; }
                            else if (str.at(j) == ')') { counter--; }
                        }
                        string s1 = str.substr(0, j + 1);
                        string s2 = str.substr(j + 1, str.length() - (j + 1));
                        str = s1 + ")" + s2;
                    } else {
                        int j = i + 3;
                        while (j < str.length() && !isOperator(str.at(j)) && str.at(j) != ')' && str.at(j) != '(') {
                            j++;
                        }
                        string temp3 = str.substr(0, j);
                        string temp4 = str.substr(j, str.length() - j);
                        str = temp3 + ")" + temp4;
                    }

                }
            }
            wasOperator = true;
        } else if (str.at(i) != '(' && str.at(i) != ')') {
            wasOperator = false;
        }
    }
    return str;
}

Expression *shuntingYard::string_to_expression(std::string str) {
    str = this->check_minuses(str);
    std::stack<std::string> final_stack = std::stack<std::string>(); //queu
    final_stack.push("$");
    std::stack<char> operators = std::stack<char>(); //stack
    operators.push('$');
    int i = 0;
    while (i < str.length()) {
        if (isdigit(str.at(i))) {
            std::string s = "";
            //bool flag = false;
            while (i < str.length() && (isdigit(str.at(i)) || str.at(i) == '.')) {
                s = s + str.at(i);
                i++;
                //flag = true;
            }
            if (s != "") {
                final_stack.push(s);
            }
            //if (!flag) { i++; }
        } else if (isOperator(str.at(i))) {
            while (isPrior(operators.top(), str.at(i))) {
                char temp = operators.top();
                string st = "" + temp;
                operators.pop();
                final_stack.push(st);
            }
            operators.push(str.at(i));
            i++;
        } else if (str.at(i) == '(') {
            operators.push('(');
            i++;
        } else if (str.at(i) == ')') {
            while (operators.top() != '(') {
                if (operators.top() == '$') { throw "input error"; }
                char temp = operators.top();
                string st = "";
                st = st + temp;
                operators.pop();
                final_stack.push(st);
            }
            operators.pop();
            i++;
        }
    }

    while (operators.top() != '$') {
        char temp = operators.top();
        string st = "";
        st = st + temp;
        operators.pop();
        final_stack.push(st);
    }
    Expression *e = createExpressions(final_stack);
    return e;
}


Expression *shuntingYard::createExpressions(std::stack<std::string> &prefix) {
    string top = prefix.top();
    prefix.pop();
    //stop condition:
    if (top == "$") { return NULL; }
    if (!isOperator(top)) {
        return new Number(std::stod(top));
    }
    // else it is an operator.
    if (top == "+") {
        return new Plus(createExpressions(prefix), createExpressions(prefix));
    } else if (top == "-") {
        return new Minus(createExpressions(prefix), createExpressions(prefix));
    } else if (top == "/") {
        return new Div(createExpressions(prefix), createExpressions(prefix));
    } else if (top == "*") {
        return new Mul(createExpressions(prefix), createExpressions(prefix));
    } else {
        throw "input error";
    }
}

