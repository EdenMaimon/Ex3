#include "BinaryExpression.h"
#include <string>

using namespace std;

class Minus:public BinaryExpression{
public:
    Minus(Expression *left, Expression *right);
    virtual double calculate();
    virtual std::string toString(){return this->left->toString()+"-"+this->right->toString() ;};
    ~Minus();
};