//
// Created by eden on 12/27/18.
//

#include "VarCommand.h"
void VarCommand::doCommand(std::vector<Expression *>::iterator it) {

    if ((*(it + 2))->toString() == "=") {
        this->dataManager->addNewVale((*(it + 1))->toString(), new DoubleVariable());
        it++;
        return;
    }
    if ((*(it + 2))->toString() == "bind") {
        this->dataManager->bind((*(it+3))->toString(),(*(it+4))->toString());
    }
}
