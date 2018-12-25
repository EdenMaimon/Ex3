
#include "Mul.h"

Mul::Mul(Expression *left, Expression *right) : BinaryExpression(left,right) {

}

double Mul::calculate(){
    return this->left->calculate() * this->right->calculate();
}

Mul::~Mul() {
    delete left;
    delete right;
}
