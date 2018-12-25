#include <fstream>
#include <sstream>
#ifndef EX3_FILECREATOR_H
#define EX3_FILECREATOR_H


class FIleCreator{
public:
    ~FIleCreator(){this->ifstem.close();};
    FIleCreator(std::string &file): ifstem(file) {};
    //used to read a line in a file
    void readLine(std::string& str) {
        if (!std::getline(this->ifstem, str)) {
            this->did_reach_end_of_file=true;
        }
    }
    bool wasEndOfFileReached(){return this->did_reach_end_of_file;};
private:
    std::ifstream ifstem;
    bool did_reach_end_of_file=false;


};









#endif //EX3_FILECREATOR_H
