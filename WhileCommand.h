//
// Created by eden on 12/27/18.
//

#ifndef EX3_WHILECOMMAND_H
#define EX3_WHILECOMMAND_H

#include "Command.h"
#include "ConditionParser.h"

class WhileCommand: public Command{
public:
    WhileCommand();
    virtual int doCommand(std::vector<Expression*>::iterator &it);
    virtual std::string toString();
    ~WhileCommand(){if(this->condition!= nullptr) delete this->condition;};

private:
    ConditionParser* condition;
};
#endif //EX3_WHILECOMMAND_H
