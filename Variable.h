//
// Created by eden on 12/20/18.
//

#ifndef EX3_VARIABLE_H
#define EX3_VARIABLE_H

#include "Expression.h"

class Variable: Expression{
public:
    double calculate()=0;
    virtual void setValue(double value)=0;
    virtual double  getValue()=0;


};
#endif //EX3_VARIABLE_H
