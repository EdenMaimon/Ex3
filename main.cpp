#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int main() {

    vector<std::string> v;
    v.push_back("1");
    v.push_back("b");
    std::vector<string>::iterator it;

    it = v.begin();

    int c = std::stoi(*it);

    try {
        std::stoi(*next(it, 1));
    } catch (std::invalid_argument) {
        cout << "invalid argument" << endl;
    }

    cout << c + 1 << endl;


    return 0;
}