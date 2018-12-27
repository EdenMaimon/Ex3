#include "Lexer.h"

using namespace std;

bool Lexer::isDigit(char c) { return (c <= 59 && c >= 48); }

bool Lexer::endWithDigit(string &s) { return isDigit(s.at(s.length() - 1)); }

bool Lexer::startWithDigit(string &s) { return (isDigit(s.at(0))); }

bool Lexer::endWithChar(string &s, char c) { return c == s.at(s.length() - 1); }

bool Lexer::startsWithChar(string &s, char c) { return c == s.at(0); }

//used to split the lines by space delimiter
void Lexer::splitStrlingByDelimerer(std::string s, std::vector<std::string> &elems) {
    char delim = ' ';
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
    }
}

/**
 * THis function gets a line representing a command and sets the para vector into holding all the parameters in it
 * @param it the begining of the seperated line array
 * @param end theend of the seperatedline array
 * @param para the vectpr to hold the parameters
 * @param spliter the spliter by which we devide the parameters
 */
void Lexer::prepareParameters(std::vector<string>::iterator it, std::vector<std::string>::iterator end,
                              std::vector<string> &para, const string &spliter) {

    string temp ="";
    int spliter_pos;
    //iterate over the vector of the seperated line
    while ((it + 1) != end) {

        //if from some reason we have a space value in the aray- skip and ignore
        if ((*it) == "") {
            ++it;
            continue;
        }
        //remove any space found in the string currently handled
        (*it).erase(remove((*it).begin(), (*it).end(), ' '), (*it).end());
        //if the specific value represents the last part of a parameters
        if (endWithDigit((*it)) && startWithDigit(*(it + 1)) ||
            endWithChar((*it), ')') && startsWithChar(*(it + 1), '(')
            || endWithDigit(*it) && startsWithChar(*(it + 1), '(')
            || endWithChar((*it), ')') && startWithDigit(*(it + 1))) {
            //add it to the expression
            temp += *it;
            //push the whole expression to the parameters vector
            para.push_back(temp);
            //initialize the temp for the next expression
            temp = "";
            //move to the next cell
            ++it;

        }
            //if there is no unexplicit end to the parameters, look for the spliter
        else {
            //look for spliter in the current string
            spliter_pos = (*it).find(spliter);
            //if you found a spliter
            if (spliter_pos != string::npos) {
                //if the spliter is alone at the string (means it was seperated by spaces in the original line
                if ((*it).length() == spliter.length()) {
                    //split the parameters while ignoring the spliter
                    para.push_back(temp);
                    ++it;
                    temp = "";
                    continue;
                }
                //add the part of the string untill the spliter to the last parameter
                temp += (*it).substr(0, spliter_pos);
                para.push_back(temp);

                //initialze the temp to be a new parameter that starts with the second part of the string after spliter
                temp = (*it).substr(spliter_pos + spliter.length(), (*it).length() - spliter_pos - spliter.length());
            }
                //if we are still in the same expression
            else {
                temp += *it;
            }
            ++it;
        }
    }

    //look for spliter in the current string
    spliter_pos = (*it).find(spliter);
    if (spliter_pos != string::npos) {
        //add the part of the string untill the spliter to the last parameter
        temp += (*it).substr(0, spliter_pos);
        para.push_back(temp);
        para.push_back((*it).substr(spliter_pos + spliter.length(), (*it).length() - spliter_pos - spliter.length()));
        return;
    }
    temp += *it;
    para.push_back(temp);

}

//used to delete '{' from the scopes
void Lexer::deleteCharFromString(string &str, char c) {
    str.erase(remove(str.begin(), str.end(), c), str.end());
}

//returns the first word in line,ignoring spaces
void Lexer::firstWord(string &line, string &first_word) {
    first_word = "";
    //set first_word to be the first word in the line
    for (int i = 0; i < line.length(); ++i) {
        if (' ' != line.at(i) && '\t' != line.at(i)) {
            first_word += line.at(i);
        } else {
            return;
        }
    }
}
//used to strip the line string from all spaces at the beginning. In addition sets first_word to the first
//word of the line
void Lexer::stripFromStart(string &line) {

    //strip the line string
    for (int i = 0; i < line.length(); i++) {

        if (' ' != line.at(i) && '\t' != line.at(i)) {
            line.erase(0, i);
            break;
        }
    }

}
void Lexer::stripFromEnd(string &line) {

    //strip the line string
    for (int i = line.length() - 1; i >= 0; i--) {

        if (' ' != line.at(i) && '\t' != line.at(i)) {
            line.erase(i+1,line.length()-i-1);
            break;
        }
    }
}
//add fileCreator*cl
//get the para with pushed "while" of "if"
void Lexer::scopedLexer(string &line, vector<string> &para) {

    string first;
    int open_suger = 1, closed_suger = 0, close_pos;
    deleteCharFromString(line, '{');
    conditionLexer(line, para);

    bool flag, isCloseSuger;
    while (open_suger > closed_suger) {

        isCloseSuger=false;
        flag = false;

        this->fIleCreator->readLine(line);

        //if there is a }, make it with a space before so it will be seperated into a new cell
        close_pos = line.find('}');

        if (close_pos != -1) {
            ++closed_suger;
            line = line.replace(close_pos, 1, " } ");
            isCloseSuger=true;
        }


        stripFromStart(line);
        firstWord(line, first);


        if ("if" == first) {
            //get the para with pushed "while" of "if"
            para.push_back("if");
            stripFromStart(line);
            scopedLexer(line, para);
            ++open_suger;
            flag = true;
        }
        if ("while" == first) {
            //get the para with pushed "while" of "if"
            para.push_back("while");
            stripFromStart(line);
            scopedLexer(line, para);
            ++open_suger;
            flag = true;
        }
        if ("var" == first) {
            stripFromStart(line);
            varLexer(line, para);
            flag = true;
        }
        if ("openDataServer" == first) {
            stripFromStart(line);
            openDataServerLexer(line, para);
            flag = true;
        }
        if ("connect" == first) {
            stripFromStart(line);
            connectLexer(line, para);
            flag = true;
        }
        if ("print" == first) {
            stripFromStart(line);
            printLexer(line, para);
            flag = true;
        }
        if ("sleep" == first) {
            stripFromStart(line);
            sleepLexer(line, para);
            flag = true;
        }
        if (!flag && line.find("=") != -1) {
            stripFromStart(line);
            equalityLexer(line, para);
        }

        if(isCloseSuger){
            para.push_back("}");
        }
    }
}

void Lexer::conditionLexer(string &line, vector<string> &para) {
    vector<string> seperated_line;
    if (line.find(">=") != -1) {
        para.push_back(">=");
        splitStrlingByDelimerer(line, seperated_line);
        prepareParameters(seperated_line.begin(), seperated_line.end(), para, ">=");
    }

    if (line.find("<=") != -1) {
        para.push_back("<=");
        splitStrlingByDelimerer(line, seperated_line);
        prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, "<=");
    }
    if (line.find("==") != -1) {
        para.push_back("==");
        splitStrlingByDelimerer(line, seperated_line);
        prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, "==");
    }

    if (line.find("!=") != -1) {
        para.push_back("!=");
        splitStrlingByDelimerer(line, seperated_line);
        prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, "!=");
    }

    if (line.find(">") != -1) {
        para.push_back(">");
        splitStrlingByDelimerer(line, seperated_line);
        prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, ">");
    }

    if (line.find("<") != -1) {
        para.push_back("<");
        splitStrlingByDelimerer(line, seperated_line);
        prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, "<");
    }
}

void Lexer::varLexer(string &line, vector<string> &para) {
    vector<string> seperated_line;
    vector<string> temp_para;

    para.push_back("var");
    //if this is only a decleration line
    if (line.find("=") == -1) {
        //var|x
        splitStrlingByDelimerer(line, seperated_line);
        para.push_back(seperated_line[1]);
        return;
    }
    //if there is "=" in the string, check for bind command
    int bind_pos1 = (line.find(" bind "));
    int bind_pos2 = line.find("=bind ");
    //if there is no bind but there is "="
    if (bind_pos1 == -1 && bind_pos2 == -1) {
        //var x = bla
        splitStrlingByDelimerer(line, seperated_line);
        //x|bla
        prepareParameters(seperated_line.begin() + 1, seperated_line.end(), temp_para, "=");
        //x|=|x|bla
        para.push_back(temp_para[0]);
        para.push_back("=");
        para.push_back(temp_para[0]);
        para.push_back(temp_para[1]);
        //var|x|=|x|bla
        return;
    }
    //both "=" and "bind"
    //first, delete the bind from the string so we can seperate it by "="

    //_bind_
    if (bind_pos1 != -1) {
        line.erase(bind_pos1, 6);
    } else {
        //=bind_
        if (bind_pos2 != -1) {
            line.erase(bind_pos2 + 1, 5);
        }
    }
    splitStrlingByDelimerer(line, seperated_line);
    prepareParameters(seperated_line.begin() + 1, seperated_line.end(), temp_para, "=");
    para.push_back(temp_para[0]);
    para.push_back("bind");
    para.push_back(temp_para[0]);
    para.push_back(temp_para[1]);
    //var|x|bind|x|bla
}

void Lexer::equalityLexer(string &line, vector<string> &para) {
    vector<string> seperated_line;
    para.push_back("=");
    splitStrlingByDelimerer(line, seperated_line);
    prepareParameters((seperated_line.begin()), seperated_line.end(), para, "=");
}

void Lexer::printLexer(string &line, vector<string> &para) {
    vector<string> seperated_line;
    para.push_back("print");
    string print_para;
    //get the print parameter
    line = line.substr(5, line.length());
    stripFromStart(line);
    para.push_back(line);
}

void Lexer::connectLexer(string &line, vector<string> &para) {
    vector<string> seperated_line;
    para.push_back("connect");
    splitStrlingByDelimerer(line, seperated_line);
    prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, ",");
}

void Lexer::sleepLexer(string &line, vector<string> &para) {
    vector<string> seperated_line;
    para.push_back("sleep");
    splitStrlingByDelimerer(line, seperated_line);
    //parameter spliter is $ in one parametered commands
    prepareParameters(seperated_line.begin() + 1, seperated_line.end(), para, "$");
}

void Lexer::openDataServerLexer(string &line, vector<string> &para) {
    vector<string> seperated_line;
    para.push_back("openDataServer");
    splitStrlingByDelimerer(line, seperated_line);
    prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, ",");
}

void Lexer::mainLexer() {
    string line,first_word;
    vector<string> parameters;
    bool flag=false;

    this->fIleCreator->readLine(line);
    if(this->fIleCreator->wasEndOfFileReached())
        return;

    stripFromStart(line);
    stripFromEnd(line);

    firstWord(line, first_word);

    if(first_word == "if") {
        parameters.push_back("if");
        scopedLexer(line,parameters);
        flag= true;
    }

    if(first_word == "while"){
        parameters.push_back("while");
        scopedLexer(line,parameters);
        flag= true;
    }

    if(first_word == "var") {
        varLexer(line, parameters);
        flag= true;
    }

    if(first_word == "openDataServer"){
        openDataServerLexer(line,parameters);
        flag= true;
    }

    if(first_word == "connect"){
        connectLexer(line,parameters);
        flag= true;
    }
    if(first_word == "sleep"){
        sleepLexer(line,parameters);
        flag= true;
    }
    if(first_word == "print"){
        printLexer(line,parameters);
        flag= true;
    }

    if(!flag){
        equalityLexer(line,parameters);
    }

    //*************DELETE***********************
     for(int i=0; i < parameters.size();++i){
         cout<<parameters[i]<<"|";
     }
     cout<<endl;
}

void Lexer::lexer() {
    while(!this->fIleCreator->wasEndOfFileReached()){
        this->mainLexer();
    }
}

