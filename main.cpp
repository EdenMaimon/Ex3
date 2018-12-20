
// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>
#include "ClientSendingData.h"
#include "DataServerReader.h"
#include "BoundedVariable.h"
int main(int argc, char const *argv[])
{
    /*
    DataServerReader server;
    server.createServerAndThread(5400,10);
*/

    ClientSendingData client;
    client.creatSocketAndConnectToServer("192.168.56.1",5402);
    std::string mess = "set" +"/controls/engines/engine/throttle" + " " + std::to_string(1)+"\n";
    client.writeMessage("Can you fell the love tonight??");


}
