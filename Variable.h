//
// Created by eden on 12/20/18.
//

#ifndef EX3_VARIABLE_H
#define EX3_VARIABLE_H

#include "Expression.h"

class Variable: public Expression{
public:
    virtual double calculate()=0;
    virtual void setValue(double value)=0;
    virtual std::string toString()=0;

};
#endif //EX3_VARIABLE_H
