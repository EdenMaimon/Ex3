#include "BoundedVariable.h"

/**
 * constructor
 * @param safe_map
 * @param value
 * @param cl
 */
BoundedVariable::BoundedVariable(std::string value,
                                 ClientSendingData *cl,ThreadSafeMap<std::string,double>* path_value_table){
    this->path = value;
    this->client = cl;
    this->path_value_table=path_value_table;
}
/**
 * Return the double value being hold to this variable path
 * @return
 */
double BoundedVariable::calculate() {
    return this->path_value_table->getValue(this->path);
}

/**
 * This function sends a message to the simulator server to set the value assosiated
 * with this path, through the client member
 * @param value the new value to be set by the simulator
 */
void BoundedVariable::setValue(double value) {

    std::string mess = "set " + this->path + " " + std::to_string(value)+"\r\n";

    if (this->client->SockOpen()) {
        this->client->writeMessage(mess);
        return;
    }
    cout<<"socket not open"<<endl;
}

