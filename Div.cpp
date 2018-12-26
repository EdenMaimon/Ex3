
#include "Div.h"
Div::Div(Expression *left, Expression *right) : BinaryExpression(left,right) {

}

double Div::calculate(){
    return this->left->calculate() / this->right->calculate();
}

Div::~Div() {
    if(left!=nullptr) delete left; if(right!= nullptr) delete right;}
