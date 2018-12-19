//
// Created by eden on 12/19/18.
//

#include "ClientSendingData.h"

using namespace std;

void ClientSendingData::writeMessage(std::string mess) {

    //convert the message to char*
    char mess_char [mess.length()];
    strcpy(mess_char, mess.c_str());

    char buffer[1024] = {0};

    //sent the message throw the socket
    if(send(this->sock , mess_char , strlen(mess_char) , 0 )<0)
        cout<<"ERROR in sending message"<<endl;

}
//"192.168.56.1"
/**
 * This function creates a client socket and connect to a server
 * @param ip
 * @param port
 * @return
 */
int ClientSendingData::creatSocketAndConnectToServer(std::string ip, int port) {

    struct sockaddr_in address{};
    int sock = 0;

    struct sockaddr_in serv_addr{};


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    char ip_char [ip.length()];

    strcpy(ip_char, ip.c_str());

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET,ip_char, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }


    if ( connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))< 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    this->sock=sock;


    return 0;
}

ClientSendingData::~ClientSendingData() {
        close(this->sock);
}
