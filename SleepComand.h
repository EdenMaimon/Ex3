//
// Created by eden on 12/27/18.
//

#ifndef EX3_SLEEPCOMAND_H
#define EX3_SLEEPCOMAND_H
#include <vector>
#include "Command.h"
#include "ClientSendingData.h"
#include "Expression.h"

class SleepComand: public Command {
public:

    virtual int doCommand(std::vector<Expression *>::iterator &it) {
        sleep((*(it + 1))->calculate(it)/1000);
    };
    virtual std::string toString(){return "sleep";};
};
#endif //EX3_SLEEPCOMAND_H
