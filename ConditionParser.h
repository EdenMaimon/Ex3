//
// Created by eden on 12/27/18.
//

#ifndef EX3_CONDITIONCOMMAND_H
#define EX3_CONDITIONCOMMAND_H

#include <vector>
#include "Command.h"
#include "Expression.h"

class ConditionParser : public Expression{
public:
    virtual double calculate(std::vector<Expression *>::iterator &it);
    virtual double calculate(){return -1;};
    virtual std::string toString();

};


#endif //EX3_CONDITIONCOMMAND_H
