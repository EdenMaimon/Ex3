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
class DataServerReader{

public:
    int openServer(int port, int hz);
    void splitMessageByComma(std::vector<std::string> &elems,char line[]);
private:

};


#endif //EX3_DATASERVERREADER_H
