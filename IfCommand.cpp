//
// Created by eden on 12/27/18.
//
#include "IfCommand.h"

int IfCommand::doCommand(std::vector<Expression *>::iterator &it) {

    ++it;
    std::vector<Expression *>::iterator loop_it=it+3;

   if((*(loop_it))->toString() != "}" && this->condition->calculate(it)){
        loop_it =std::next(it,3);
        (*loop_it)->calculate(loop_it);
        loop_it++;
    }
}
