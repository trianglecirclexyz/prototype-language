#ifndef LEXER_H
#define LEXER_H

#include "string_utils.h"
#include <fstream>
#include <sstream>
#include <unordered_set>


enum TokenType {
    Keyword, // 0
    Identifier, // 1
    SpecialSymbol, // 2
    OperatorToken, // 3
    Value, // 4
    String, // 5
    StringSegment, // 6
    Invalid, // 7
};

struct Token {
    std::string data;
    TokenType type = TokenType::Invalid;
    std::size_t line;

    Token(std::string data, std::size_t line) {
        this->data = data;
        this->line = line;
    };

    Token(std::string data, TokenType type) {
        this->data = data;
        this->type = type;
    };
};

namespace Lexer {
    const std::unordered_set<std::string> keywords = 
        {"string", "int", "float", "bool", "fn",};
    const std::unordered_set<char> operatorTokens = 
        {'=', '+', '-', '*', '/', '^', '>', '<',};
    const std::unordered_set<char> specialSymbols = 
        {'(', ')', '{', '}', ';', '!', '.', '$',
         ',', ':', };

    // read file into fileData
    bool ReadFile(const std::string &filePath, std::string &fileData);
    // lex file into tokens 
    void Lex(const std::string &fileData, std::vector<Token> &tokens);
};

#endif // LEXER_H