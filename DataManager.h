//
// Created by eden on 12/18/18.
//

#ifndef EX3_DATAMANAGER_H
#define EX3_DATAMANAGER_H

#include "ThreadSafeMap.h"

class DataManager{

public:
    ThreadSafeMap<std::string, double> symbolTable;
    ThreadSafeMap<std::string,std::string> boundedTable;


};
#endif //EX3_DATAMANAGER_H
