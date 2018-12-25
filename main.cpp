
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "Lexer.h"
using namespace std;



int main(int argc, char** argv)
{
    Lexer lexer(argv[1]);
    lexer.lexer();

	return 0;
}
 