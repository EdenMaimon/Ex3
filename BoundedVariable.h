//
// Created by eden on 12/20/18.
//

#ifndef EX3_STRINGVARIABLE_H
#define EX3_STRINGVARIABLE_H

#include "Variable.h"
#include "ThreadSafeMap.h"
#include "ClientSendingData.h"
#include "DataManager.h"

class BoundedVariable :public Variable {
public:
    BoundedVariable(std::string value,ClientSendingData* cl ,ThreadSafeMap<std::string,double>* path_value_table);
    virtual double calculate();
    virtual void setValue(double value);
    virtual std::string toString(){return this->path;};

private:
    ThreadSafeMap<std::string,double>* path_value_table;
    ClientSendingData* client;
    std::string path; //the path

};


#endif //EX3_STRINGVARIABLE_H
