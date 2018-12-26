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
#include "DataManager.h"
static vector< const char*>  path_order ={"/instrumentation/airspeed-indicator/indicated-speed-kt",
                                                 "/instrumentation/altimeter/indicated-altitude-ft",
                                                 "/instrumentation/altimeter/pressure-alt-ft",
                                                 "/instrumentation/attitude-indicator/indicated-pitch-deg",
                                                 "/instrumentation/attitude-indicator/indicated-roll-deg",
                                                 "/instrumentation/attitude-indicator/internal-pitch-deg",
                                                 "/instrumentation/attitude-indicator/internal-roll-deg",
                                                 "/instrumentation/encoder/indicated-altitude-ft",
                                                 "/instrumentation/encoder/pressure-alt-ft", "/instrumentation/gps/indicated-altitude-ft",
                                                 "/instrumentation/gps/indicated-ground-speed-kt", "/instrumentation/gps/indicated-vertical-speed",
                                                 "/instrumentation/heading-indicator/indicated-heading-deg",
                                                 "/instrumentation/magnetic-compass/indicated-heading-deg",
                                                 "/instrumentation/slip-skid-ball/indicated-slip-skid",
                                                 "/instrumentation/turn-indicator/indicated-turn-rate",
                                                 "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                                 "/controls/flight/aileron", "/controls/flight/elevator", "/controls/flight/rudder",
                                                 "/controls/flight/flaps", "/controls/engines/current-engine/throttle", "/engines/engine/rpm"};

class DataServerReader {

public:

    DataServerReader(ThreadSafeMap<std::string,double>* table){this->path_value_table=table;};
    static void *openServer(void *arg);

    static void splitMessageByComma(std::vector<std::string> &elems, char line[]);

    void createServerAndThread(int port, int hz);

    static void update(vector<string> mess, ThreadSafeMap<std::string,double>* path_value_table);


private:
    ThreadSafeMap<std::string,double>* path_value_table;
};
#endif //EX3_DATASERVERREADER_H
