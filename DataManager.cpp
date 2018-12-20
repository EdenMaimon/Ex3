#include "DataManager.h"

void DataManager::bind(std::string var, std::string anchor) {

    //if the anchor is a path
    if(anchor.find("/") == string::npos){


        BoundedVariable new_var(this->path_value_table,anchor,this->client);

        this->symbolTable[var] = new_var;

        return;
    }

    //if anchor is not a path, than it is a var

    //dwon cast the variable to bounded var to get the path
    BoundedVariable &temp = dynamic_cast<BoundedVariable&>(this->symbolTable[var]);

    //create new baoundvariable
    BoundedVariable new_var(this->path_value_table,temp.getpath(),this->client);

    this->symbolTable[var]=new_var;

}
