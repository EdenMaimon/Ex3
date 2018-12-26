/*
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5402

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "10.0.0.138", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstring>
#include "Lexer.h"
#include "shuntingYard.h"
#include "BoundedVariable.h"
#include "DoubleVariable.h"


using namespace std;


int main(int argc, char** argv)
{

    ThreadSafeMap<std::string,double>* path_value_table =new ThreadSafeMap<std::string,double>();
    ClientSendingData* cl=new ClientSendingData();
   /* DataManager* dm=new DataManager(path_value_table);
    DataServerReader server(path_value_table);
    server.createServerAndThread(5400,10);


    cl->creatSocketAndConnectToServer("10.0.4.2",5402);
    string s="set controls/flight/rudder -1";
    s+="\r\n";
    cl->writeMessage(s);
    int b;
*/

    //s="set controls/flight/rudder -1";
    string s="\r\n";
   // cl->writeMessage(s);

    Expression* e,*e2,*e3;
    Variable* d = new BoundedVariable("controls/flight/rudder",cl,path_value_table);
    d->setValue(1);


    Lexer lexer(argv[1]);
    lexer.lexer();

    string test="5+4/3";


    e2=new Number(33);
    e3=new Number(22);

    e=new Minus(e2,e3);
    cout<<e->toString()<<endl;

    e=new Plus(e2,e3);
    cout<<e->toString()<<endl;

    e=new Div(e2,e3);
    cout<<e->toString()<<endl;

    e=new Mul(e2,e3);
    cout<<e->toString()<<endl;

    e=new Minus(e2,e3);
    cout<<e->toString()<<endl;


    e= new DoubleVariable(33);
    cout<<e->toString()<<endl;

    e=new Minus(e2,e3);
    cout<<e->toString()<<endl;

    int a;

    e=Shunting_yard("5+4/3");
    cout<<e->toString()<<"="<<e->calculate()<<endl;


    delete e;

	return 0;
}
