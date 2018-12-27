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
    virtual int doCommand(std::vector<Expression*>::iterator &it){
        std::cout<<((*(it+1))->toString())<<std::endl;
    };
    virtual std::string toString(){return "print";};
};
#endif //EX3_PRINTCOMMAND_H
