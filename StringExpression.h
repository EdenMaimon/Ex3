//
// Created by eden on 12/26/18.
//

#ifndef EX3_STRINGEXPRESSION_H
#define EX3_STRINGEXPRESSION_H

#include "Expression.h"
#include "Number.h"

class StringExpression: public Expression{
public:
    virtual double calculate(std::vector<Expression *>::iterator &it) {return -111;};
    virtual std::string toString(){return this->value;};

private:
    std::string value;
};
#endif //EX3_STRINGEXPRESSION_H
