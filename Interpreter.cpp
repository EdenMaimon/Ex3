//
// Created by eden on 12/12/18.
//
#include "Interpreter.h"

/**
 * Gets a string representing a line in the script and splits it according to white space delimeter
 * @param elems The vector being inserted with the splited strings of the line
 * @param line The line to be splited into small strings by the white space del
 */
void Interperter::lexer(std::vector<std::string> &elems,std::string line) {

    char delim = ' ';
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
    }

}

