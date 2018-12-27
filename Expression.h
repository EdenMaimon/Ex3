//
// Created by eden on 12/12/18.
//

#ifndef EX3_EXPRESSION_H
#define EX3_EXPRESSION_H

#include <string>
#include <vector>

class Expression {
public:
    virtual double calculate (std::vector<Expression *>::iterator &it) = 0;
    virtual double calculate()=0;
    virtual std::string toString()=0;
};


#endif //EX3_EXPRESSION_H
