//
// Created by eden on 12/27/18.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H

#include "Command.h"
#include "ConditionParser.h"

class IfCommand:public Command{
public:
    IfCommand(){this->condition=new ConditionParser();};
    virtual int doCommand(std::vector<Expression*>::iterator &it) override;
    virtual std::string toString(){return "IfCommand";};
    ~IfCommand(){if(this->condition!= nullptr)delete this->condition;};

private:
    ConditionParser* condition;
};


#endif //EX3_IFCOMMAND_H
