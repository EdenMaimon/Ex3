//
// Created by eden on 12/12/18.
//

#include <string>
#include <vector>
#include <map>
#include "Expression.h"
#include "Command.h"
#include <sstream>

#ifndef EX3_INTERPRETER_H
#define EX3_INTERPRETER_H


class Interperter {
public:
    void lexer(std::vector<std::string> &elems, std::string line);

    void parser(std::vector<std::string> lines);


private:
    std::map<std::string, Expression*> exp_map;
    std::map<std::string, double> var_map;


};

#endif //EX3_INTERPRETER_H
