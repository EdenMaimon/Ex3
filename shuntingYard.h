

#include <string>
#include "Expression.h"
#include "Number.h"
#include "Plus.h"
#include "stack"
#include "DataManager.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"

#pragma once
class shuntingYard {

public:

   shuntingYard(DataManager* dataManager) { this->data_manager = dataManager; }
    bool isPrior(const char stack, const char token);
    bool isOperator(const char c);
    bool isOperator(const std::string str);
    Expression* string_to_expression(std::string str);
    Expression * createExpressions(std::stack<std::string> &prefix);
    std::string check_minuses(std::string str);

private:
 DataManager* data_manager;

};