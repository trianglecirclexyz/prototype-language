#ifndef TOKEN_H
#define TOKEN_H

#include <string>

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

#endif // TOKEN_H

