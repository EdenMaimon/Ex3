#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "FileCreator.h"

#ifndef EX3_LEXER_H
#define EX3_LEXER_H
class Lexer{
public:
    Lexer(std::string file_name){this->fIleCreator =new FIleCreator(file_name);};
    ~Lexer(){delete this->fIleCreator;};
    void lexer();
    void mainLexer();
    void prepareParameters( std::vector<std::string>::iterator it, std::vector<std::string>::iterator end ,
                           std::vector<std::string> &para ,const std::string &spliter);
    bool startsWithChar(std::string &s, char c);
    bool isDigit(char c);
    bool endWithDigit(std::string &s);
    bool startWithDigit(std::string &s);
    bool endWithChar(std::string &s, char c);
    void splitStrlingByDelimerer(std::string s, std::vector<std::string>& elems);
    void deleteCharFromString(std::string &str, char c);
    void firstWord(std::string &line,std::string &first_word);
    void stripFromStart(std::string& line);
    void stripFromEnd(std::string &line);
    void scopedLexer(std::string &line, std::vector<std::string> &para);
    void conditionLexer(std::string &line, std::vector<std::string> &para);
    void varLexer(std::string &line, std::vector<std::string> &para);
    void equalityLexer(std::string &line, std::vector<std::string> &para);
    void printLexer(std::string &line, std::vector<std::string> &para);
    void connectLexer(std::string &line, std::vector<std::string> &para);
    void sleepLexer(std::string &line, std::vector<std::string> &para);
    void openDataServerLexer( std::string &line, std::vector<std::string> &para);


private:
    FIleCreator* fIleCreator;
};
#endif //EX3_LEXER_H
