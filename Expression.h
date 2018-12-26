//
// Created by eden on 12/12/18.
//

#ifndef EX3_EXPRESSION_H
#define EX3_EXPRESSION_H

#include <string>

class Expression {
public:
    virtual double calculate() = 0;
    virtual std::string toString()=0;
};


#endif //EX3_EXPRESSION_H
