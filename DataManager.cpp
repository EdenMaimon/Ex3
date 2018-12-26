#include "DataManager.h"
#include "BoundedVariable.h"
DataManager::DataManager(ThreadSafeMap<std::string,double>* table) {

    this->client = new ClientSendingData();

    this->path_value_table=table;
}


void DataManager::bind(string var, string anchor) {

    //if the anchor is a path
    if (anchor.find('/') == string::npos) {

        Variable *new_var = new BoundedVariable(anchor, this->client,this->path_value_table);

        this->symbolTable[var] = new_var;

        return;
    }

    //if anchor is not a path, than it is a var

    //create new baoundvariable
    Variable *new_var = new BoundedVariable(this->symbolTable[anchor]->toString(),
                                            this->client,this->path_value_table);

    this->symbolTable[var] = new_var;
}

DataManager::~DataManager() {
    if (this->client != nullptr) delete client;


    std::map<std::string, Variable *>::iterator it = this->symbolTable.begin();
    while (it != symbolTable.end()) {
        if (it->second != nullptr)
            delete it->second;
    }
}


void DataManager::addNewVale(string var_name, Variable *var) {
    this->symbolTable[var_name] = var;
}

double DataManager::getValueFromPathValueMap(std::string path) {
    return  this->path_value_table->getValue(path);
}

