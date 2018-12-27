//
// Created by eden on 12/12/18.
//
#include "Expression.h"
#include "Command.h"

#ifndef EX3_COMMANDEXPRESSION_H
#define EX3_COMMANDEXPRESSION_H

/**
 * THis class is an object adaptor whose job is to make expression out of a command
 */
class CommandExpression : public Expression {

public:
    //The calculate function of a command object will do the command
    double calculate() {
        return this->c->doCommand();
    }
    std::string toString(){return this->c->toString();};
private:
    Command* c;

};

#endif //EX3_COMMANDEXPRESSION_H
