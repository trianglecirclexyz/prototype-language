#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    Keyword, // 0
    Identifier, // 1
    Symbol, // 2
    Value, // 3
    String, // 4
    StringSegment, // 5
    Invalid, // 6
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

#endif // TOKEN_H

