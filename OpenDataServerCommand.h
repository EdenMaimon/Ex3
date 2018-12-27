//
// Created by eden on 12/27/18.
//
#include <vector>
#include "Command.h"
#include "Expression.h"
#include <iterator>
#include "DataServerReader.h"
#include "Expression.h"
#ifndef EX3_OPENDATASERVERCOMMAND_H
#define EX3_OPENDATASERVERCOMMAND_H

class OpenDataServerCommand : public Command{
public:
    OpenDataServerCommand(DataServerReader* server){this->dataServerReader=server;};
    void doCommand(std::vector<Expression*>::iterator it){
        this->dataServerReader->createServerAndThread((int)(*(it+1))->calculate(),(int)(*(it+1))->calculate());
        it+=2;
    }
    std::string toString(){return "OpenServerCommand";};

private:
    DataServerReader* dataServerReader;
};
#endif //EX3_OPENDATASERVERCOMMAND_H
