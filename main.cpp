
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

    DataServerReader server;
    server.createServerAndThread(5400,10);

   /* ClientSendingData client;
    client.creatSocketAndConnectToServer("192.168.56.1",5402);
    string path="/controls/engines/engine/throttle";
    string set="set";
    std::string mess = set +path+ " " + std::to_string(1)+"\n";
    client.writeMessage(mess);
*/
}
