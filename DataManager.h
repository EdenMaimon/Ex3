//
// Created by eden on 12/18/18.
//

#ifndef EX3_DATAMANAGER_H
#define EX3_DATAMANAGER_H

#include <vector>
#include "ThreadSafeMap.h"
#include "ClientSendingData.h"
#include "DoubleVariable.h"
#include "map"
#include "string"
#include "DataServerReader.h"
class DataManager{

public:
    DataManager(ThreadSafeMap<std::string,double>* table);
    void addNewVale(std::string var_name, Variable* var);
    void bind(std::string var, std::string anchor);
    double getValueFromPathValueMap(std::string path);
    ~DataManager();


private:
    std::map<std::string, Variable*> symbolTable;

    ThreadSafeMap<std::string,double>* path_value_table;

    ClientSendingData* client;

};
#endif //EX3_DATAMANAGER_H
