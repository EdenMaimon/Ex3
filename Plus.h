
#include "BinaryExpression.h"
#include <string>

using namespace std;

class Plus:public BinaryExpression{
public:
  Plus(Expression *left, Expression *right);
  virtual double calculate();
  ~Plus();
};