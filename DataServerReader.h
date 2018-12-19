//
// Created by eden on 12/18/18.
//

#ifndef EX3_DATASERVERREADER_H
#define EX3_DATASERVERREADER_H
#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>
#include <string>
#include <strings.h>
#include <vector>
#include <sstream>
#include <pthread.h>
class DataServerReader{

public:
    static void* openServer(void* arg);
    static void splitMessageByComma(std::vector<std::string> &elems,char line[]);
    void createServerAndThread(int port,int hz);
private:

};


#endif //EX3_DATASERVERREADER_H
