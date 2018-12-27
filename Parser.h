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
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"
#include "VarCommand.h"
#include "WhileCommand.h"
#include "EqualityCommand.h"
#include "SleepComand.h"
#include "PrintCommand.h"
#include "StringExpression.h"
#include "IfCommand.h"
#include "shuntingYard.h"
class Parser {
public:
    Parser(DataServerReader* server,DataManager* data ,ClientSendingData* cl);
    void parser(std::vector<std::string> &string_line);
    void openDataServertoExpression (std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void connecttoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void vartoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void printtoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void sleeptoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void equalitytoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);

    ~Parser(){if(this->shunting!= nullptr)delete shunting;};
private:
    std::map<std::string,Expression*> command_map;
    shuntingYard* shunting;
};
#endif //EX3_PARSER_H
