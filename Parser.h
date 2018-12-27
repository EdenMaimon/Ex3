//
// Created by eden on 12/27/18.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H

#include <string>
#include "vector"
#include "Expression.h"
#include "Command.h"
#include "map"
#include "CommandExpression.h"
class Parser {
public:
    Parser(){
        this->command_map["openDataServer"]=new CommandExpression(new openDataServerCommand());
        this->command_map["connect"]=new CommandExpression(new connectCommand());
    }
    void parser(std::vector<std::string> &string_line);
    void openDataServertoExpression (std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void connecttoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void vartoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);

private:
    std::map<std::string,Command*> command_map;
};
#endif //EX3_PARSER_H
