//
// Created by eden on 12/26/18.
//

#ifndef EX3_BINARYEXPRESSION_H
#define EX3_BINARYEXPRESSION_H

#pragma once
#include "Expression.h"
#include "Number.h"
#include <string>

class BinaryExpression : public Expression{
public:
    BinaryExpression(Expression *left, Expression *right) {this->left=left, this->right=right;};
    virtual double calculate(std::vector<Expression *>::iterator &it){return this->calculate();};
    virtual double calculate()=0;
    virtual std::string toString()=0;
    ~BinaryExpression(){if(left!=nullptr) delete left; if(right!= nullptr) delete right;};
protected:
    Expression *left;
    Expression *right;
};
#endif //EX3_BINARYEXPRESSION_H
