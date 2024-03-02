#include "Parser.h"

Parser::Parser(const std::vector<Token> &tokens) : tokens(tokens), currentTokenIndex(0) {}

void Parser::parse()
{
    parseExpression();
}

void Parser::parseExpression()
{
    parseTerm();
    while (getCurrentToken().value=="+" || getCurrentToken().value=="-")
    {
        Token op = getNextToken();
        parseTerm();
        std::cout<<"Operator: "<<op.value<<std::endl;
    }
}

void Parser::parseTerm()
{
      parseFactor();
    while (getCurrentToken().value == "*" || getCurrentToken().value == "/")
    {
        Token op = getNextToken();
        parseFactor();
        std::cout << "Operator: " << op.value << std::endl;
    }
}

void Parser::parseFactor()
{
    if (getCurrentToken().value == "(")
    {
        getNextToken();
        parseExpression();
        if (getCurrentToken().value == ")")
        {
            getNextToken();
        }
        else
        {
            std::cerr << "Error: Expected ')'." << std::endl;
            exit(1);
        }
    }
    else if (getCurrentToken().type == "identifier")
    {
        std::cout << "Identifier: " << getCurrentToken().value << std::endl;
        getNextToken(); 
    }
    else
    {
        std::cerr << "Error: Unexpected token." << std::endl;
        exit(1);
    }
}

Token Parser::getCurrentToken()
{
    return tokens[currentTokenIndex];
}

Token Parser::getNextToken()
{
    if (currentTokenIndex < tokens.size())
    {
        return tokens[currentTokenIndex++];
    }
    else
    {
        Token endToken;
        endToken.type = "END";
        return endToken;
    }
}