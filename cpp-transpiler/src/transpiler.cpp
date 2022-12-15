
#include "lexer.h"

#include <iostream>

int main(int argc, char** argv) {

    if(argc < 2) {
        std::cerr << "Not enough arguments." << std::endl;
        return EXIT_FAILURE;
    }

    std::string filePath = argv[1];

    std::string fileData;
    Lexer::ReadFile(filePath, fileData);

    std::vector<Token> tokens;
    Lexer::Lex(fileData, tokens);

    // printout tokens
    for(int i = 0; i < tokens.size(); i++) {
        std::cout << "[" << tokens[i].line << "] ";
        if(tokens[i].type != TokenType::Invalid) {
            std::cout << "\u001b[32m" << tokens[i].data << "\u001b[37m, " << tokens[i].type << std::endl;
        }
        else {
            std::cout << "\u001b[31m" << tokens[i].data << "\u001b[37m, " << tokens[i].type << std::endl;
        }
    }

    return EXIT_SUCCESS;

}