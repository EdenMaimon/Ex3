
#include "BinaryExpression.h"
#include <string>

using namespace std;

class Plus:public BinaryExpression{
public:
  Plus(Expression *left, Expression *right);
  virtual double calculate();
    virtual std::string toString(){return this->left->toString()+"+"+this->right->toString() ;};
  ~Plus();
};