#include "Lexer.h"
#include "Parser.h"

int main(){
    Lexer lexer("sourcecode.txt");

    std::vector<Token> tokens = lexer.tokensize();

    Parser parser(tokens);

    parser.parse();

    return 0;
}