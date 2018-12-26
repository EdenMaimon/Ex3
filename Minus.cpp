
#include "Minus.h"

Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left,right) {

}

double Minus::calculate(){
    return this->left->calculate() - this->right->calculate();
}

Minus::~Minus() {
    if(left!=nullptr) delete left;
    if(right!= nullptr) delete right;
}
