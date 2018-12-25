#include "BinaryExpression.h"
#include <string>

using namespace std;

class Minus:public BinaryExpression{
public:
    Minus(Expression *left, Expression *right);
    virtual double calculate();
    ~Minus();
};