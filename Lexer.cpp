#include "lexer.h"

Lexer::Lexer(const std::string &filename) : fin(filename), buffer("") {}

std::vector<Token> Lexer::tokensize()
{
    std::vector<Token> tokens;

    while(fin>>ch){
        if(ch==' ' || ch=='\n'){
            if(!buffer.empty()){
                Token token;
                token.type = isKeyword(buffer.c_str()) ? "keyword" : "identifier";
                token.value = buffer;
                tokens.push_back(token);
                buffer.clear();
            }
        }
        else
        {
            buffer += ch;
        }
    }
    fin.close();
    return tokens;
}

int Lexer::isKeyword(const char buffer[])
{
    char keywords[32][20] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};


    for (int i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            return 1;
        }
    }
    return 0;
}