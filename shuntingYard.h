
#include <queue>
#include <stack>
#include "Expression.h"
#include "Minus.h"
#include "Plus.h"
#include "Div.h"
#include "Mul.h"
#include "map"
using  namespace std;



Expression *toExp(stack<string> &stack_str) {
    if(stack_str.empty()){
        throw "input error";
    }
    if (stack_str.top() == "+") {
        return new Plus(toExp(stack_str), toExp(stack_str));
    } else if (stack_str.top() == "-") {
        return new Minus(toExp(stack_str), toExp(stack_str));
    } else if (stack_str.top() == "*") {
        return new Mul(toExp(stack_str), toExp(stack_str));
    } else if (stack_str.top() == "/") {
        return new Div(toExp(stack_str), toExp(stack_str));
    } else if((stack_str.top() != "/") || (stack_str.top() != "*") || (stack_str.top() != "+") || (stack_str.top() != "-")){
        return new Number(atof(stack_str.top().c_str()));
    }
    stack_str.pop();
}
string getNUm(){

}
//Shunting_yard
Expression* Shunting_yard(string str) {
    string sofi = "";
    queue<string> q;
    stack<string> s;
    stack<string> sFinal;
    map<string, int> op_precedence;
    op_precedence["+"] = 10;
    op_precedence["-"] = 10;
    op_precedence["*"] = 20;
    op_precedence["/"] = 20;
    op_precedence["("] = 1;
    op_precedence[")"] = 1;

    for (int i = 0; i < str.length(); i++) {
        string num = "";
        string opr = "";
        opr.push_back(str[i]);
        if (str[i] == '(') {
            //s.push(str[i]);
            s.push("(");
        }
        else if (str[i] == ')') {
            do {
                q.push(s.top());
                s.pop();
            } while (s.top() != "(");
            s.pop();
        }
        else if (op_precedence[opr] == 20 || op_precedence[opr] == 10) {
            if (s.size() > 0) {
                if ((op_precedence[s.top()] >= op_precedence[opr])) {
                    q.push(s.top());
                    s.pop();
                }
            }
            s.push(opr);
        }
        else if((str[i] >= 65 && str[i] <= 90) ||
                (str[i] >= 97 && str[i] <= 122) || str[i] == 95){
            while (isdigit(str[i]) || (str[i] >= 65 && str[i] <= 90) ||
                   (str[i] >= 97 && str[i] <= 122) || str[i] == 95) {
                num.push_back(str[i]);
                int j = i;
                j++;
                if (isdigit(str[j]) || (str[j] >= 65 && str[j] <= 90) ||
                    (str[j] >= 97 && str[j] <= 122) || str[j] == 95) {
                    i = j;
                }
                else {
                    break;
                }
            }
            //getNum(num);
        }
        else while (isdigit(str[i])) {
                num.push_back(str[i]);
                int j = i;
                j++;
                if (isdigit(str[j])) {
                    i = j;
                }
                else {
                    break;
                }
            }
        q.push(num);
    }
    while (s.size() > 0) {
        q.push(s.top());
        s.pop();
    }

    while (!q.empty()) {
        sFinal.push(q.front());
        q.pop();
    }

    return toExp(sFinal);
}

