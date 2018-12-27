//
// Created by eden on 12/12/18.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include <string>
#include "Expression.h"

class Command {
public:
   virtual int doCommand(std::vector<Expression*>::iterator &it)=0;
   virtual std::string toString()=0;

};
#endif //EX3_COMMAND_H
