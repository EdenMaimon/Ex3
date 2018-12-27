
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
#include "Minus.h"
#include "Plus.h"
#include "Div.h"
#include "Mul.h"
#include "Number.h"
#include "BinaryExpression.h"

using namespace std;


int main(int argc, char** argv)
{

    ThreadSafeMap<std::string,double>* path_value_table =new ThreadSafeMap<std::string,double>();
    ClientSendingData* cl=new ClientSendingData();
   /* DataManager* dm=new DataManager(path_value_table);
    DataServerReader server(path_value_table);
    server.createServerAndThread(5400,10);


    cl->creatSocketAndConnectToServer("10.0.4.2",5402);
    string s="set controls/flight/rudder -1";
    s+="\r\n";
    cl->writeMessage(s);
    int b;
*/

    //s="set controls/flight/rudder -1";
    string s="\r\n";
   // cl->writeMessage(s);



    Lexer lexer(argv[1]);
    lexer.lexer();

    string test="5+4/3";
/*

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


    e= new DoubleVariable(33);
    cout<<e->toString()<<endl;

    e=new Minus(e2,e3);
    cout<<e->toString()<<endl;

    int a;

//    shuntingYard* sh=new shuntingYard();
  //  e=sh->string_to_expression("(5+4)/3");
    cout<<e->toString()<<"="<<e->calculate()<<endl;


    delete e;

	return 0;
*/
 }
