//
// Created by eden on 12/27/18.
//

#include "WhileCommand.h"

int WhileCommand::doCommand(std::vector<Expression *>::iterator &it) {

    ++it;
    std::vector<Expression *>::iterator loop_it = it + 3;
    std::string s = (*(loop_it))->toString();
    double a = (this->condition->calculate(it));

    while (this->condition->calculate(it)) {
        while ((*(loop_it))->toString() != "}") {
            //  loop_it =std::next(it,3);
            (*loop_it)->calculate(loop_it);
            loop_it++;
        }
    }
    it=next(loop_it,0);
}

WhileCommand::WhileCommand() {
    this->condition=new ConditionParser();
}

std::string WhileCommand::toString() {
    return "while";
}
