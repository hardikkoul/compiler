#ifndef LEXER_H
#define LEXER_H

#include<iostream>
#include<vector>
#include<fstream>

struct  Token
{
    std::string type;
    std::string value;
};

class Lexer 
{
    public:
        Lexer(const std::string &filename);
        std::vector<Token> tokensize();
    private:
        std::ifstream fin;
        char ch;
        std::string buffer;

        int isKeyword(const char buffer[]);
};

#endif