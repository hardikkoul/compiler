#ifndef PARSER_H
#define PARSER.H

#include<iostream>
#include<vector>

#include "Lexer.h"

class Parser
{
    public: 
        Parser(const std::vector<Token> &tokens);
        void parse();
    private:
        std::vector<Token> tokens;
        size_t currentTokenIndex;

        void parseExpression();
        void parseTerm();
        void parseFactor();

        Token getCurrentToken();
        Token getNextToken();
};

#endif