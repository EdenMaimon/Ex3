
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "Lexer.h"
#include "shuntingYard.h"
#include "BoundedVariable.h"
#include "DoubleVariable.h"

using namespace std;



int main(int argc, char** argv)
{
    Lexer lexer(argv[1]);
    lexer.lexer();

    string test="5+4/3";

    Expression* e,*e2,*e3;
    e2=new Number(33);
    e3=new Number(22);

    e=new Minus(e2,e3);
    cout<<e->toString()<<endl;

    e=new Plus(e2,e3);
    cout<<e->toString()<<endl;

    e=new Div(e2,e3);
    cout<<e->toString()<<endl;

    e=new Mul(e2,e3);
    cout<<e->toString()<<endl;

    e=new Minus(e2,e3);
    cout<<e->toString()<<endl;

    ThreadSafeMap<std::string, double> path_value_table;
    ClientSendingData* cl =new ClientSendingData();
    e = new BoundedVariable(path_value_table,"/path/",cl);
    cout<<e->toString()<<endl;

    e= new DoubleVariable(33);
    cout<<e->toString()<<endl;

    delete e;

	return 0;
}
 