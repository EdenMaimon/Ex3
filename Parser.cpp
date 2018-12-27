    //
    // Created by eden on 12/27/18.
    //
    #include "Parser.h"
    Parser::Parser(DataServerReader *server, DataManager *data, ClientSendingData *cl) {
        this->command_map["openDataServer"]=new CommandExpression(new OpenDataServerCommand(server));
        this->command_map["connect"]=new CommandExpression(new ConnectCommand(cl));
        this->command_map["var"]=new CommandExpression(new VarCommand(data));
        this->command_map["while"]=new CommandExpression(new WhileCommand());
        this->command_map["="]=new CommandExpression(new EqualityCommand(data));
        this->command_map["sleep"]=new CommandExpression(new SleepComand());
        this->command_map["print"]=new CommandExpression(new PrintCommand());
        this->command_map["if"]=new CommandExpression(new IfCommand());
        this->shunting=new shuntingYard();
    }

    void Parser::parser(std::vector<std::string> &string_line){
        if()

    }

    void Parser::openDataServertoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
    exp_vector.push_back(this->command_map["openDataServer"]);
    exp_vector.push_back(this->shunting->string_to_expression(string_line[0]));
        exp_vector.push_back(this->shunting->string_to_expression(string_line[1]));
    }


    void Parser::connecttoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
        exp_vector.push_back(this->command_map["connect"]);
        exp_vector.push_back(new StringExpression(string_line[1]));
        exp_vector.push_back(new StringExpression(string_line[2]));
    }

    void Parser::vartoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
        exp_vector.push_back(this->command_map["var"]);
        exp_vector.push_back((new StringExpression(string_line[1])));
        if(string_line.size() ==5){
            if(string_line[2]=="="){
                exp_vector.push_back(this->command_map["="]);
                exp_vector.push_back(new StringExpression(string_line[3]));
                exp_vector.push_back(this->shunting->string_to_expression(string_line[4]));
                return;
            }
            if(string_line[2]=="bind"){
                string s="bind";
                exp_vector.push_back(new StringExpression(s));
                exp_vector.push_back(new StringExpression(string_line[3]));
                exp_vector.push_back(new StringExpression(string_line[4]));
            }

        }
    }

    void Parser::printtoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
        exp_vector.push_back(this->command_map["print"]);
        if(string_line[1].find("\"")){
            string_line[1]=string_line[1].substr(1,string_line[1].length()-2);
            exp_vector.push_back(new StringExpression(string_line[1]));
            return;
        }
        exp_vector.push_back(this->shunting->string_to_expression(string_line[1]));
    }

    void Parser::sleeptoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
        exp_vector.push_back(this->command_map["sleep"]);
        exp_vector.push_back(this->shunting->string_to_expression(string_line[1]));
    }

    void Parser::equalitytoExpression(std::vector<std::string> &string_line, std::vector<Expression *> &exp_vector) {
        exp_vector.push_back(this->command_map["="]);
        exp_vector.push_back(new StringExpression(string_line[1]));
        exp_vector.push_back(this->shunting->(string_line[2]));

    }
