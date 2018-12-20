//
// Created by eden on 12/20/18.
//

#ifndef EX3_STRINGVARIABLE_H
#define EX3_STRINGVARIABLE_H

#include "Variable.h"
#include "ThreadSafeMap.h"
#include "ClientSendingData.h"

class BoundedVariable : Variable {
public:
    BoundedVariable(ThreadSafeMap <std::string,double> safe_map, std::string value,ClientSendingData* cl);
    virtual double calculate();
    virtual void setValue(double value);
    virtual double  getValue();

private:
    ThreadSafeMap<std::string, double> path_value_table;
    ClientSendingData* client;
    std::string value;

};


#endif //EX3_STRINGVARIABLE_H
