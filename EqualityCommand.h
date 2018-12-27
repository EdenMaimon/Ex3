//
// Created by eden on 12/27/18.
//

#ifndef EX3_EQUALITYCOMMAND_H
#define EX3_EQUALITYCOMMAND_H

#include <vector>
#include "Command.h"
#include "Expression.h"
#include "vector"
#include "DataManager.h"

class EqualityCommand: Command{
public:
    EqualityCommand(DataManager* data){this->dataManager=data;};
    void doCommand(std::vector<Expression *>::iterator it) {
        this->dataManager->setValueOfVariable((*(it + 1))->toString(),(*(it+2))->calculate());
    };
    std::string toString(){return "EqualityCommand";};
private:
    DataManager* dataManager;

};
#endif //EX3_EQUALITYCOMMAND_H
