
#include "lexer.h"
#include "parser.h"

#include <iostream>

int main(int argc, char** argv) {

    if(argc < 2) {
        std::cerr << "Not enough arguments." << std::endl;
        return EXIT_FAILURE;
    }

    std::string filePath = argv[1];

    // read in file stream
    std::string fileData;
    Lexer::ReadFile(filePath, fileData);

    // lex data in file and store tokens in vector
    std::vector<Token> tokens;
    Lexer::Lex(fileData, tokens);

    // [DEBUG] printout tokens
    for(int i = 0; i < tokens.size(); i++) {
        std::cout << "[" << tokens[i].line << "] ";
        if(tokens[i].type != TokenType::Invalid) {
            std::cout << "\u001b[32m" << tokens[i].data << "\u001b[37m, " << tokens[i].type << std::endl;
        }
        else {
            std::cout << "\u001b[31m" << tokens[i].data << "\u001b[37m, " << tokens[i].type << std::endl;
        }
    }

    // parse tokens whilst following grammer rules



    return EXIT_SUCCESS;

}