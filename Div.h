#include "BinaryExpression.h"
#include <string>

using namespace std;

class Div:public BinaryExpression{
public:
    Div(Expression *left, Expression *right);
    virtual double calculate();
    virtual std::string toString(){return this->left->toString()+"/"+this->right->toString() ;};
    ~Div();
};