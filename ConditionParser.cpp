//
// Created by eden on 12/27/18.
//

#include "ConditionParser.h"
#include <string>
std::string ConditionParser::toString() {
return "ConditionParser";
}

double ConditionParser::calculate(std::vector<Expression *>::iterator &it) {
    if((*(it))->toString() == ">")
        return (*(it+1))->calculate(it) > (*(it+2))->calculate(it);
    if((*(it))->toString() == ">=")
        return (*(it+1))->calculate(it) >= (*(it+2))->calculate(it);
    if((*(it))->toString() == "<")
        return (*(it+1))->calculate(it) < (*(it+2))->calculate(it);
    if((*(it))->toString() == "<=")
        return (*(it+1))->calculate(it) <= (*(it+2))->calculate(it);
    if((*(it))->toString() == "==") {
        return (*(it + 1))->calculate(it) == (*(it + 2))->calculate(it);
    }
    if((*(it))->toString() == "!=")
        return (*(it+1))->calculate(it) != (*(it+2))->calculate(it);
}

