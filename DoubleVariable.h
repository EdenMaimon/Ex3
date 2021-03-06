//
// Created by eden on 12/20/18.
//

#ifndef EX3_DOUBLEVARIABLE_H
#define EX3_DOUBLEVARIABLE_H

#include "Variable.h"

class DoubleVariable : public Variable  {
public:
    DoubleVariable(){};
    DoubleVariable(double value){this->value=value;}
    virtual double calculate(){return this->value;};
    virtual void setValue(double value){this->value=value;};
    virtual std::string toString(){return std::to_string(this->value);};

private:
    double value;

};

#endif //EX3_DOUBLEVARIABLE_H
