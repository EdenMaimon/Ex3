//
// Created by eden on 12/27/18.
//
#include "Parser.h"

Parser::Parser(DataServerReader *server, DataManager *data, ClientSendingData *cl) {
    this->command_map["openDataServer"] = new CommandExpression(new OpenDataServerCommand(server));
    this->command_map["connect"] = new CommandExpression(new ConnectCommand(cl));
    this->command_map["var"] = new CommandExpression(new VarCommand(data));
    this->command_map["while"] = new CommandExpression(new WhileCommand());
    this->command_map["="] = new CommandExpression(new EqualityCommand(data));
    this->command_map["sleep"] = new CommandExpression(new SleepComand());
    this->command_map["print"] = new CommandExpression(new PrintCommand());
    this->command_map["if"] = new CommandExpression(new IfCommand());
    this->shunting = new shuntingYard(data);
}

void Parser::parser(std::vector<std::string> &string_line) {

    std::vector<Expression *> exp_vector;
    this->toExpression(string_line,exp_vector);

    std::vector<Expression*>::iterator it=exp_vector.begin();
string temp;
    while(it!=exp_vector.end()){
        temp=(*it)->toString();
        this->command_map[(*(it))->toString()]->calculate(it);
        ++it;
    }

    //if string_line[lenfth()-1=="}"})

}

void Parser::openDataServertoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    exp_vector.push_back(this->command_map["openDataServer"]);
    exp_vector.push_back(this->shunting->string_to_expression(string_line[0]));
    exp_vector.push_back(this->shunting->string_to_expression(string_line[1]));
}


void Parser::connecttoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    exp_vector.push_back(this->command_map["connect"]);
    exp_vector.push_back(new StringExpression(string_line[1]));
    exp_vector.push_back(new StringExpression(string_line[2]));
}

void Parser::vartoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    exp_vector.push_back(this->command_map["var"]);
    exp_vector.push_back((new StringExpression(string_line[1])));
    if (string_line.size() == 5) {
        if (string_line[2] == "=") {
            exp_vector.push_back(this->command_map["="]);
            exp_vector.push_back(new StringExpression(string_line[3]));
            exp_vector.push_back(this->shunting->string_to_expression(string_line[4]));
            return;
        }
        if (string_line[2] == "bind") {
            string s = "bind";
            exp_vector.push_back(new StringExpression(s));
            exp_vector.push_back(new StringExpression(string_line[3]));
            exp_vector.push_back(new StringExpression(string_line[4]));
        }

    } else {
        if (string_line.size() == 2) {
            string s = "#";
            exp_vector.push_back(new StringExpression(s));
        }
    }
}

void Parser::printtoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    exp_vector.push_back(this->command_map["print"]);
    if (string_line[1].at(0)=='"') {
        string_line[1] = string_line[1].substr(1, string_line[1].length() - 2);
        exp_vector.push_back(new StringExpression(string_line[1]));
        return;
    }
    exp_vector.push_back(this->shunting->string_to_expression(string_line[1]));
}

void Parser::sleeptoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    exp_vector.push_back(this->command_map["sleep"]);
    exp_vector.push_back(this->shunting->string_to_expression(string_line[1]));
}

void Parser::equalitytoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    exp_vector.push_back(this->command_map["="]);
    int var_position;
    int right_epression;
    if (string_line.size() == 3) {
        var_position = 1;
        right_epression = 2;
    } else {
        if (string_line.size() == 5) {
            var_position = 3;
            right_epression = 4;
        }
    }
    exp_vector.push_back(new StringExpression(string_line[var_position]));
    exp_vector.push_back(this->shunting->string_to_expression(string_line[right_epression]));
}



void Parser::noScopedCommandstoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    if (string_line[0] == "openDataServer")
        this->openDataServertoExpression(string_line, exp_vector);
    if (string_line[0] == "connect")
        this->connecttoExpression(string_line, exp_vector);
    if (string_line[0] == "var")
        this->vartoExpression(string_line, exp_vector);
    if (string_line[0] == "=")
        this->equalitytoExpression(string_line, exp_vector);
    if (string_line[0] == "sleep")
        this->sleeptoExpression(string_line, exp_vector);
    if (string_line[0] == "print")
        this->printtoExpression(string_line, exp_vector);

}

void Parser::ScopedtoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    vector<std::string> temp_line;
    int j = 4;
    exp_vector.push_back(new StringExpression(string_line[1]));
    exp_vector.push_back(this->shunting->string_to_expression(string_line[2]));
    exp_vector.push_back(this->shunting->string_to_expression(string_line[3]));

    for (int i = 4; i < string_line.size(); ++i) {
        temp_line.clear();
        while (string_line[j] != "@" && string_line[j] != "}") {
            temp_line.push_back(string_line[j]);
            ++j;
        }
        noScopedCommandstoExpression(temp_line, exp_vector);
        ++j;
        i = j;
    }
    string s="}";
    exp_vector.push_back(new StringExpression(s));
}

void Parser::toExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    if(string_line[0]=="while"){
        exp_vector.push_back(this->command_map["while"]);
        this->ScopedtoExpression(string_line,exp_vector);
        return;
    }
    if(string_line[0]=="if"){
        exp_vector.push_back(this->command_map["if"]);
        this->ScopedtoExpression(string_line,exp_vector);
        return;
    }
    this->noScopedCommandstoExpression(string_line,exp_vector);

}



