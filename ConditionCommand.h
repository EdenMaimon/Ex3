//
// Created by eden on 12/27/18.
//

#ifndef EX3_CONDITIONCOMMAND_H
#define EX3_CONDITIONCOMMAND_H

#include <vector>
#include "Command.h"
#include "Expression.h"

class ConditionParser: Expression{
public:
    double calculate(std::vector<Expression *>::iterator it){

        if((*(it))->toString() == ">")
            return (*(it+1))->calculate() > (*(it+2))->calculate();
    }

   // std::string toString(){return (*(it+1))->calculate() > (*(it+2))->to()}

private:

};


#endif //EX3_CONDITIONCOMMAND_H
