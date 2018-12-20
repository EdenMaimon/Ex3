//
// Created by eden on 12/18/18.
//

#ifndef EX3_DATAMANAGER_H
#define EX3_DATAMANAGER_H

#include <vector>
#include "ThreadSafeMap.h"
#include "BoundedVariable.h"
#include "DoubleVariable.h"
#include "map"
#include "string"
#include "DataServerReader.h"

class DataManager{

public:
    DataManager();
    void bind(std::string var, std::string anchor);
    void update(std::vector<std::string> mess);


private:
    std::map<std::string, Variable> symbolTable;

    ThreadSafeMap<std::string,double> path_value_table;

    std::string path_order[23];

    DataServerReader* data_server_reader;

    ClientSendingData* client;

};
#endif //EX3_DATAMANAGER_H
