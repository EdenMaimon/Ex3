//
// Created by eden on 12/27/18.
//

#ifndef EX3_VARCOMMAND_H
#define EX3_VARCOMMAND_H

#include "Command.h"
#include <vector>
#include "Command.h"
#include "Expression.h"
#include "vector"
#include "DataManager.h"

class VarCommand : public Command{

public:
    VarCommand(DataManager* data){this->dataManager=data;};
    virtual int doCommand(std::vector<Expression *>::iterator &it) ;
    virtual std::string toString(){return "VarCommand";};

private:
    DataManager* dataManager;
};
#endif //EX3_VARCOMMAND_H
