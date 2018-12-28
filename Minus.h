#include "BinaryExpression.h"
#include <string>
#pragma once
using namespace std;

class Minus:public BinaryExpression{
public:
    Minus(Expression *left, Expression *right);
    virtual double calculate();
    virtual std::string toString(){return this->left->toString()+"-"+this->right->toString() ;};
    ~Minus();
};