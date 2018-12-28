//
// Created by eden on 12/12/18.
//

#include <string>
#include <vector>
#include <map>
#include "Expression.h"
#include "Command.h"
#include "Lexer.h"
#include "Parser.h"
#include <sstream>

#ifndef EX3_INTERPRETER_H
#define EX3_INTERPRETER_H


class Interperter {
public:
    void lexer(std::vector<std::string> &elems, std::string line);


private:
    Lexer lex;
    Parser pars;

};

#endif //EX3_INTERPRETER_H
