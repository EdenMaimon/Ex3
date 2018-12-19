//
// Created by eden on 12/19/18.
//

#ifndef EX3_CLIENTSENDINGDATA_H
#define EX3_CLIENTSENDINGDATA_H
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include "iostream"
class ClientSendingData{
public:
    int creatSocketAndConnectToServer(std::string ip,int port);
    void writeMessage(std::string mess);

private:
    int sock=0;
};
#endif //EX3_CLIENTSENDINGDATA_H
