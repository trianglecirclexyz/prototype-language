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
    Operator, // 3
    Value, // 4
    String, // 5
    StringSegment, // 6
    Invalid, // 7
};

struct Token {
    std::string data;
    TokenType type = TokenType::Invalid;

    Token(std::string data) {
        this->data = data;
    };

    Token(std::string data, TokenType type) {
        this->data = data;
        this->type = type;
    };
};

namespace Lexer {
    // one of these is not like the other
    const std::unordered_set<std::string> keywords = 
        {"string", "int", "float", "bool", "fn", "->"};
    const std::unordered_set<std::string> operators = 
        {"=", "+"};
    const std::unordered_set<char> specialSymbols = 
        {'(', ')', '{', '}', ';', '!', '.', '$',
         ',', ':', };

    // read file into fileData
    bool ReadFile(const std::string &filePath, std::string &fileData);
    // lex file into tokens 
    void Lex(const std::string &fileData, std::vector<Token> &tokens);
};

#endif // LEXER_H