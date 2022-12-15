#ifndef LEXER_H
#define LEXER_H

#include "string_utils.h"
#include <fstream>
#include <sstream>
#include <unordered_set>


enum TokenType {
    Keyword,
    Identifier,
    SpecialSymbol,
    Operator,
    Value,
    String,
    StringSegment,
    Unassigned,
};

struct Token {
    std::string data;
    TokenType type = TokenType::Unassigned;

    Token(std::string data) {
        this->data = data;
    };
};

namespace Lexer {
    const std::unordered_set<std::string> keywords = 
        {"fn"};
    const std::unordered_set<std::string> operators = 
        {""};
    const std::unordered_set<char> specialSymbols = 
        {'(', ')', '{', '}', ';', '!', '.', '$'};

    // read file into fileData
    bool ReadFile(const std::string &filePath, std::string &fileData);
    // lex file into tokens 
    bool Lex(const std::string &fileData, std::vector<Token> &tokens);
};

#endif // LEXER_H