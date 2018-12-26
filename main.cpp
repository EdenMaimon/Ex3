
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstring>
#include "Lexer.h"
#include "shuntingYard.h"
#include "BoundedVariable.h"
#include "DoubleVariable.h"


using namespace std;


int main(int argc, char** argv)
{


    ThreadSafeMap<std::string,double>* path_value_table =new ThreadSafeMap<std::string,double>();

    DataManager* dm=new DataManager(path_value_table);
    DataServerReader server(path_value_table);
    //server.createServerAndThread(5400,10);

    ClientSendingData* cl=new ClientSendingData();
    cl->creatSocketAndConnectToServer("196.168.56.1",5402);
    string s="set controls/flight/rudder 1";
    s+="\r\n";
    cl->writeMessage("hiii");
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

    e = new BoundedVariable("/path/",cl,path_value_table);
    cout<<e->toString()<<endl;

    e= new DoubleVariable(33);
    cout<<e->toString()<<endl;

    e=new Minus(e2,e3);
    cout<<e->toString()<<endl;

    int a;
    cin>>a;
    /*e=Shunting_yard("5+4/3");
    cout<<e->toString()<<"="<<e->calculate()<<endl;
*/

    delete e;

	return 0;
}
 