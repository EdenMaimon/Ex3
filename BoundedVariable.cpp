#include "BoundedVariable.h"

/**
 * constructor
 * @param safe_map
 * @param value
 * @param cl
 */
BoundedVariable::BoundedVariable(ThreadSafeMap<string, double> safe_map, std::string value,
                                 ClientSendingData *cl) : path_value_table(safe_map) {
    this->path = value;
    this->client = cl;
}
/**
 * Return the double value being hold to this variable path
 * @return
 */
double BoundedVariable::calculate() {
    return this->path_value_table.getValue(this->path);
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

