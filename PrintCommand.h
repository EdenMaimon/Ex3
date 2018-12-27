//
// Created by eden on 12/27/18.
//

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H
#include <vector>
#include "Command.h"
#include "ClientSendingData.h"
#include "Expression.h"
#include "iostream"

class PrintCommand: public Command{
public:
    void doCommand(std::vector<Expression*>::iterator it){
        std::cout<<((*(it+1))->toString())<<std::endl;
    };
    std::string toString(){return "PrintCommand";};
};
#endif //EX3_PRINTCOMMAND_H
