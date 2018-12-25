
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

//returns true if the string is number and false otherwise

bool isDigit(char c) {
	if (c <= 59 && c >= 48)
		return true;
	return false;
}

bool endWithDigit(string &s) {

	return isDigit(s.at(s.length() - 1));
}

bool startWithDigit(string &s) {
	
	return (isDigit(s.at(0)));
}

bool endWithChar(string &s, char c) {
	return c == s.at(s.length() - 1);
}

bool startsWithChar(string &s, char c) {
	return c == s.at(0);
}

//This function returns the a vector of expressions that represents the parameters of the command from line 
//represented by v. This function takes into con
void prepareParameters(vector<string>::iterator &it, vector<string>::iterator &end ,
	vector<string> &para ,const string &spliter) {

	string temp = "";
	int spliter_pos;
	//iterate over the vector of the seperated line
	while ((it + 1) != end) {  

		//if from some reason we have a space value in the aray- skip and ignor
		if ((*it) == "") {
			++it;
			continue;
		}
		//remove any space found in the string currently handled
		(*it).erase(remove((*it).begin(),(*it).end(),'	'), (*it).end());
		//if the specific value represents the last part of a parameters
		if (endWithDigit((*it)) && startWithDigit(*(it+1)) ||
			 endWithChar((*it),')') && startsWithChar(*(it+1),'(')
			|| endWithDigit(*it) && startsWithChar(*(it+1),'(')
			|| endWithChar((*it),')') && startWithDigit(*(it+1)))
		 {
				//add it to the expression
				temp += *it;
				//push the whole expression to the parameters vector
				para.push_back(temp);
				//initialize the temp for the next expression
				temp = "";	
				//move to the next cell
				++it;

		 }
		//if there is no unexplixit end to the parameters, look for the spliter
		else {
			//look for spliter in the current string
			spliter_pos = (*it).find(spliter);
			//if you found a spliter
			if (spliter_pos != string::npos) {
				//if the spliter is alone at the string (means it was seperated by spaces in the original line
				if ((*it).length() == spliter.length()){
					//split the parameters while ignoring the spliter
					para.push_back(temp);
					++it;
					temp = "";
					continue;
				}
				//add the part of the string untill the spliter to the last parameter
				temp += (*it).substr(0,spliter_pos);
				para.push_back(temp);

				//initialze the temp to be a new parameter that starts with the second part of the string after spliter
				temp = (*it).substr(spliter_pos + spliter.length(), (*it).length() - spliter_pos -spliter.length());
			}
			//if we are still in the same expression
			else {
				temp += *it;
			}
			++it;
		}
	}

	//look for spliter in the current string
	spliter_pos = (*it).find(spliter);
	if (spliter_pos != string::npos) {
		//add the part of the string untill the spliter to the last parameter
		temp += (*it).substr(0,spliter_pos);
		para.push_back(temp);
		para.push_back((*it).substr(spliter_pos + spliter.length(), (*it).length()  - spliter_pos - spliter.length()));
		return;
	}
	temp += *it;
	para.push_back(temp);
}
//used to read a line in a file
void readLine(std::ifstream &file, string& str) {
	
	if (!std::getline(file, str)) {
		cout<< "end of file";
		return;
	}
}

int writeFile(string file)
{
	ofstream myfile;
	myfile.open(file);
	myfile << "Writing this to a file 1.\n";
	myfile << "Writing this to a file 2.\n";
	myfile.close();
	return 0;
}
//used to split the lines by space delimiter
void splitStrlingByDelimerer(std::string s, std::vector<std::string>& elems)
{
	char delim = ' ';
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
	}

}	

//used to delete '{' from the scopes
void deleteCharFromString(string &str, char c)
{
	str.erase(remove(str.begin(), str.end(),c), str.end());
}

void firstWord(string &line,string &first_word) {
	first_word = "";
	//set first_word to be the first word in the line
	for (int i = 0; i < line.length(); ++i) {
		if (' ' != line.at(i) && '\t' != line.at(i)) {
			first_word += line.at(i);
		}
		else {
			return;
		}
	}
}
//used to strip the line string from all spaces at the beginning. In addition sets first_word to the first 
//word of the line
void stripFromStart(string& line) {

	
	//strip the line string
	for (int i = 0; i < line.length(); i++) {

		if (' ' != line.at(i) && '\t' != line.at(i)) {
			line.erase(0, i);
			break;
		}
	}
	
}

void openDataServerLexer( string &line, vector<string> &para) {
	vector<string> seperated_line;
	para.push_back("openDataServer");
	splitStrlingByDelimerer(line, seperated_line);
	prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, ",");
}

void connectLexer(string &line, vector<string> &para) {
	vector<string> seperated_line;
	para.push_back("connect");
	splitStrlingByDelimerer(line, seperated_line);
	prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, ",");
}

void sleepLexer(string &line, vector<string> &para) {
	vector<string> seperated_line;
	para.push_back("sleep");
	splitStrlingByDelimerer(line, seperated_line);
	//parameter spliter is $ in one parametered commands
	prepareParameters(seperated_line.begin() + 1, seperated_line.end(), para, "$");
}

void printLexer(string &line, vector<string> &para) {
	vector<string> seperated_line;
	para.push_back("print");
	string print_para;
	//get the print parameter
	line = line.substr(5, line.length());
	stripFromStart(line);
	para.push_back(line);
}

void equalityLexer(string &line, vector<string> &para) {
	vector<string> seperated_line;
	para.push_back("=");
	splitStrlingByDelimerer(line, seperated_line);
	prepareParameters((seperated_line.begin()), seperated_line.end(), para, "=");
}

void varLexer(string &line, vector<string> &para) {
	vector<string> seperated_line;
	vector <string> temp_para;

	para.push_back("var");
	//if this is only a decleration line
	if (line.find("=") == -1) {
		//var|x
		splitStrlingByDelimerer(line, seperated_line);
		para.push_back(seperated_line[1]);
		return;
	}
	//if there is "=" in the string, check for bind command
	int bind_pos1 = line.find(" bind ");
	int bind_pos2 = line.find("=bind ");
	//if there is no bind but there is "="
	if (bind_pos1 == -1 && bind_pos2 == -1) {
		//var x = bla
		splitStrlingByDelimerer(line, seperated_line);
		//x|bla
		prepareParameters(seperated_line.begin() + 1, seperated_line.end(), temp_para, "=");
		//x|=|x|bla
		para.push_back(temp_para[0]);
		para.push_back("=");
		para.push_back(temp_para[0]);
		para.push_back(temp_para[1]);
		//var|x|=|x|bla
		return;
	}
	//both "=" and "bind"
	//first, delete the bind from the string so we can seperate it by "="

	//_bind_
	if (bind_pos1 != -1) {
		line.erase(bind_pos1, 6);
	}
	else {
		//=bind_
		if (bind_pos2 != -1) {
			line.erase(bind_pos2 + 1, 5);
		}
	}
	splitStrlingByDelimerer(line, seperated_line);
	prepareParameters(seperated_line.begin() + 1, seperated_line.end(), temp_para, "=");
	para.push_back(temp_para[0]);
	para.push_back("bind");
	para.push_back(temp_para[0]);
	para.push_back(temp_para[1]);
	return;
	//var|x|bind|x|bla
}

void conditionLexer(string &line, vector<string> &para) {
	vector<string> seperated_line;

	if (line.find(">=") != -1) {
		para.push_back(">=");
		splitStrlingByDelimerer(line, seperated_line);
		prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, ">=");
	}

	if (line.find("<=") != -1) {
		para.push_back("<=");
		splitStrlingByDelimerer(line, seperated_line);
		prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, "<=");
	}
	if (line.find("==") != -1) {
		para.push_back("==");
		splitStrlingByDelimerer(line, seperated_line);
		prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, "==");
	}

	if (line.find("!=") != -1) {
		para.push_back("!=");
		splitStrlingByDelimerer(line, seperated_line);
		prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, "!=");
	}

	if (line.find(">") != -1) {
		para.push_back(">");
		splitStrlingByDelimerer(line, seperated_line);
		prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, ">");
	}

	if (line.find("<") != -1) {
		para.push_back("<");
		splitStrlingByDelimerer(line, seperated_line);
		prepareParameters((seperated_line.begin() + 1), seperated_line.end(), para, "<");
	}
}

//add fileCreator*cl
//get the para with pushed "while" of "if"
void scopedLexer(string &line, vector<string> &para){
	//****************************DELETE*****************************************************
	ifstream ifstem("Test.txt");
	string first;
	int open_suger = 1, closed_suger = 0;
	int close_pos;
	deleteCharFromString(line, '{');
	conditionLexer(line, para);

	bool flag;
	while (open_suger > closed_suger) {
		
		flag=false;

		readLine (ifstem,line);
		stripFromStart(line);
		firstWord(line, first);
		
		if ("if" == first) {
			//add fileCreator*cl
			//get the para with pushed "while" of "if"
			para.push_back("if");
			stripFromStart(line);
			scopedLexer(line, para);
			++open_suger;
			flag = true;
		}
		if ("while" == first) {
			//add fileCreator*cl
			//get the para with pushed "while" of "if"
			para.push_back("while");
			stripFromStart(line);
			scopedLexer(line, para);
			++open_suger;
			flag = true;
		}
		if ("var" == first) {
			stripFromStart(line);
			varLexer(line, para);
			flag = true;
		}
		if ("openDataServer" == first) {
			stripFromStart(line);
			openDataServerLexer(line, para);
			flag = true;
		}
		if ("connect" == first) {
			stripFromStart(line);
			conditionLexer(line, para);
			flag = true;
		}
		if ("print" == first) {
			stripFromStart(line);
			printLexer(line, para);
			flag = true;
		}
		if ("sleep" == first) {
			stripFromStart(line);
			sleepLexer(line, para);
			flag = true;
		}
		if (!flag && line.find("=") != -1) {
			stripFromStart(line);
			equalityLexer(line, para);
		}
		if (line.find("}") != -1) {
			++closed_suger;
		}
	}

}

int main()
{
	cout << "h0–h" << endl;
	
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
 