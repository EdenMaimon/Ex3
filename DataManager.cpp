#include "DataManager.h"

DataManager::DataManager()
    {
        this->client = new ClientSendingData();
        this->data_server_reader = new DataServerReader();

        path_order = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
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
    }


    void DataManager::bind(string var, string anchor) {

        //if the anchor is a path
        if (anchor.find('/') == string::npos) {

            Variable *new_var = new BoundedVariable(this->path_value_table, anchor, this->client);

            this->symbolTable[var] = new_var;

            return;
        }

        //if anchor is not a path, than it is a var

        //create new baoundvariable
        Variable *new_var = new BoundedVariable(this->path_value_table, this->symbolTable[anchor]->toString(),
                                                this->client);

        this->symbolTable[var] = new_var;
    }

    void DataManager::update(vector<string> mess) {

        for (int i = 0; i < this->path_order.size(); ++i) {
            this->path_value_table.setKeyValue(path_order[i], std::stod(mess[i]));
        }
    }
    DataManager::~DataManager()
    {
        if (this->client != nullptr) delete client;
        if (this->data_server_reader != nullptr)
            delete data_server_reader;


        std::map<std::string, Variable *>::iterator it = this->symbolTable.begin();
        while (it != symbolTable.end()) {
            if (it->second != nullptr)
                delete it->second;
        }
    }


void DataManager::addNewVale(string var_name, Variable *var) {
    this->symbolTable[var_name] = var;
}
