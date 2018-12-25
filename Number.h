
#include "Expression.h"
class Number : public Expression{
public:
    Number(double value);
    virtual double calculate();
    ~Number();
private:
    double value;

};