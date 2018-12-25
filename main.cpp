
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;


int writeFile(string file)
{
	ofstream myfile;
	myfile.open(file);
	myfile << "Writing this to a file 1.\n";
	myfile << "Writing this to a file 2.\n";
	myfile.close();
	return 0;
}









int main()
{

	
	vector<string> para;
	string first = "";
	
	para.push_back("while");
	string line = "while alt < 1000 {";
	scopedLexer(line, para);

	for (int i = 0; i < para.size(); i++) {
		if (i == 6)
			cout << para[i].at(3)+'0' << endl;
		cout << para[i] << "|";
	}
	cout << endl;

	/*
	string line = "var x=bindy ";
	stripFromStart(line);
	firstWord(line, first);
	if ("var" == first) {

		varLexer(line, para);
		cout << "Enters the var lexer" << endl;
		cout << para[0] << "|" << para[1] << "|" << para[2] << "|" << para[3] << "|" << para[4] << endl;
	}

	para.clear();

	line = "var x= bind \"path\" ";
	stripFromStart(line);
	firstWord(line, first);
	if ("var" == first) {

		varLexer(line, para);
		cout << "Enters the var lexer" << endl;
		cout << para[0] << "|" << para[1] << "|" << para[2] <<"|"<<para[3]<<"|"<<para[4]<<endl;
	}

	para.clear();




	 line = "\topenDataServer (5 * 1000 +4) 10";
	stripFromStart(line);
	firstWord(line,first);
	if ("openDataServer" == first) {
		
		openDataServerLexer(line, para);
		cout << "Enters the opendataserver lexer" << endl;
		cout << para[0] << "**" << para[1] << "**" << para[2] << endl;
	}

	para.clear();

	line = "connect 127.0.0.1 (5* 4000)/2 +3)";
	stripFromStart(line);
	firstWord(line, first);
	if ("connect" == first) {

		connectLexer(line, para);
		cout << "Enters the connect lexer" << endl;
		cout << para[0] << "**" << para[1] << "**" << para[2] << endl;
	}

	para.clear();

	 line = "print \"or cupper skin\" ";
	stripFromStart(line);
	firstWord(line, first);
	if ("print" == first) {

		printLexer(line, para);
		cout << "Enters the print lexer" << endl;
		cout << para[0] << "**" << para[1]<< endl;
	}

	para.clear();

	 line = "sleep 25 *100";
	stripFromStart(line);
	firstWord(line, first);
	if ("sleep" == first) {

		sleepLexer(line, para);
		cout << "Enters the sleep lexer" << endl;
		cout << para[0] << "**" << para[1] << endl;
	}

	para.clear();

	line = "while alt == ( 100* 4)/2 ";
	stripFromStart(line);
	firstWord(line, first);
	if ("while" == first) {

		conditionLexer(line, para);
		cout << "Enters the consition lexer" << endl;
		cout << para[0] << "**" << para[1] <<"**"<<para[2]<< endl;
	}

	para.clear();

	line = "if alt <= ( 100* 4)/2 ";
	stripFromStart(line);
	firstWord(line,first);
	if ("if" == first) {

		conditionLexer(line, para);
		cout << "Enters the consition lexer" << endl;
		cout << para[0] << "**" << para[1] << "**" << para[2] << endl;
	}

	para.clear();

	line = "while alt < ( 100* 4)/2 ";
	stripFromStart(line);
	firstWord(line, first);
	if ("while" == first) {

		conditionLexer(line, para);
		cout << "Enters the consition lexer" << endl;
		cout << para[0] << "**" << para[1] << "**" << para[2] << endl;
	}
	system("pause");

	/*
	string s = "5*";
	string s2 = "*5";
	
	cout << startWithDigit(s) << " " << "true" << endl;
	cout << startWithDigit(s2) << " " << "false" << endl;

	cout << endWithDigit(s) << " " << "false" << endl;
	cout << endWithDigit(s2) << " " << "true" << endl;
	
	string s3 = "  alt <= 1000 {";
	string s4 = "breaks";
	string first = "";
	stripFromStart(s4,first);
	cout << (s4) <<"-------"<<first<< endl;

	stripFromStart(s3,first);
	cout << s3 <<"---------"<<first<< endl;

	std::vector<string> v; //= { "(a+","b)/d","+2","6" };
	splitStrlingByDelimerer(s4,v);

	vector<string> para;
	//getParameters(v.begin(),v.end(),para,"<=");
	vector<string>::iterator it = v.begin();
	
	
	//writeFile("Test.txt");

	
	ifstream file("Test.txt");


	readLine(file,line);
	cout << line << endl;

	readLine(file, line);
	cout << line << endl;

	readLine(file, line);
	cout << line << endl;*/

	return 0;
}
 