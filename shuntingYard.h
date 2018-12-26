//
// Created by eden on 12/26/18.
//
#include <string>
#include "Expression.h"

#include "Div.h"
#include "Minus.h"
#include "Mul.h"

#include "Plus.h"
#include <stack>
#ifndef EX3_SHUNTINGYARD_H
#define EX3_SHUNTINGYARD_H

class ShuntingYard{
public:
    std::string check_minuses(std::string str);
    Expression * string_to_expression(std::string str);
    Expression * createExpressions(std::stack<std::string> &prefix);


};
#endif //EX3_SHUNTINGYARD_H
