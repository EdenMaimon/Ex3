//
// Created by eden on 12/26/18.
//

#ifndef EX3_NUMBER_H
#define EX3_NUMBER_H
#include "Expression.h"

class Number : public Expression{
public:
    Number(double value) {this->value=value;};
    virtual double calculate() {return this->value;};
    virtual std::string toString(){return std::to_string(this->value);};
    ~Number();
private:
    double value;

};

#endif //EX3_NUMBER_H
