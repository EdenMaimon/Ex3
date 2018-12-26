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

    void addNewVale(std::string var_name, Variable* var);
    void bind(std::string var, std::string anchor);
    void update(std::vector<std::string> mess);

    ~DataManager();


private:
    std::map<std::string, Variable*> symbolTable;

    ThreadSafeMap<std::string,double> path_value_table;

     vector<const char*>  path_order ;

    DataServerReader* data_server_reader;

    ClientSendingData* client;

};
#endif //EX3_DATAMANAGER_H
