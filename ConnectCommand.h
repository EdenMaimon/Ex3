//
// Created by eden on 12/27/18.
//

#ifndef EX3_CONNECTCOMMAND_H
#define EX3_CONNECTCOMMAND_H

#include <vector>
#include "Command.h"
#include "ClientSendingData.h"
#include "Expression.h"

class ConnectCommand: public Command{
public:
    ConnectCommand(ClientSendingData* cl){this->client=cl;};
    void doCommand(std::vector<Expression*>::iterator it){
        this->client->creatSocketAndConnectToServer((*(it+1))->toString(),(*(it+2))->calculate());
    }
    std::string toString(){return "ConnectCommand";};

private:
    ClientSendingData* client;
};
#endif //EX3_CONNECTCOMMAND_H
