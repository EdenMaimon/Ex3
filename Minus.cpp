
#include "Minus.h"

Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left,right) {

}

double Minus::calculate(){
    return this->left->calculate() - this->right->calculate();
}

Minus::~Minus() {
    delete left;
    delete right;
}
