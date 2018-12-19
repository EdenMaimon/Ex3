
// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "ClientSendingData.h"
#define PORT 5402

int main(int argc, char const *argv[])
{
    ClientSendingData client;
    client.creatSocketAndConnectToServer("192.168.56.1",5402);
}
