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
    virtual int doCommand(std::vector<Expression*>::iterator &it){
        this->dataServerReader->createServerAndThread((int)(*(it+1))->calculate(it),(int)(*(it+1))->calculate(it));
        it+=2;
    }
    virtual std::string toString(){return "OpenServerCommand";};

private:
    DataServerReader* dataServerReader;
};
#endif //EX3_OPENDATASERVERCOMMAND_H
