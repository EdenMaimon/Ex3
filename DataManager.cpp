#include "DataManager.h"

void DataManager::bind(std::string var, std::string anchor) {

    //if the anchor is a path
    if(anchor.find('/') == string::npos){


        Variable* new_var =new BoundedVariable (this->path_value_table,anchor,this->client);

        this->symbolTable[var] = new_var;

        return;
    }

    //if anchor is not a path, than it is a var

    //create new baoundvariable
    Variable* new_var=new BoundedVariable(this->path_value_table,this->symbolTable[anchor]->toString()
            ,this->client);

    this->symbolTable[var]=new_var;

}
