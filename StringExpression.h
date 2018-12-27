//
// Created by eden on 12/26/18.
//

#ifndef EX3_STRINGEXPRESSION_H
#define EX3_STRINGEXPRESSION_H

#include "Expression.h"
#include "Number.h"

class StringExpression: public Expression{
public:
    StringExpression(std::string &s){this->value=s;};
    virtual double calculate(std::vector<Expression *>::iterator &it) {this->calculate();};
    virtual double calculate(){return -1;}
    virtual std::string toString(){return this->value;};

private:
    std::string value;
};
#endif //EX3_STRINGEXPRESSION_H
