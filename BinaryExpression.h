
#include "Expression.h"
#include "Number.h"
#include <string>
class BinaryExpression : public Expression{
public:
    BinaryExpression(Expression *left, Expression *right);
    virtual double calculate()=0;
    ~BinaryExpression();
protected:
    Expression *left;
    Expression *right;
};