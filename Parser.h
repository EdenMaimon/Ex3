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

class Parser {
public:
    Parser(DataServerReader* server,DataManager* data ,ClientSendingData* cl){
        this->command_map["openDataServer"]=new CommandExpression(new OpenDataServerCommand(server));
        this->command_map["connect"]=new CommandExpression(new ConnectCommand(cl));
        this->command_map["var"]=new new CommandExpression(new VarCommand());
        
        
    }
    void parser(std::vector<std::string> &string_line);
    void openDataServertoExpression (std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void connecttoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);
    void vartoExpression(std::vector<std::string> &string_line, std::vector<Expression*> &exp_vector);

private:
    std::map<std::string,Expression*> command_map;
};
#endif //EX3_PARSER_H
