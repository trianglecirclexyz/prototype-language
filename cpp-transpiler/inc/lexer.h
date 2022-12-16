#ifndef LEXER_H
#define LEXER_H

#include "string_utils.h"
#include "token.h"

#include <fstream>
#include <sstream>
#include <unordered_set>

namespace Lexer {
    const std::unordered_set<std::string> keywords = 
        {"string", "int", "float", "bool", "true",
        "false", "fn", "for", "in", "list"};
    const std::unordered_set<char> symbols = 
        {'=', '+', '-', '*', '/', '^', '>', '<', '%',
         '(', ')', '{', '}', ';', '!', '.', '$',
         ',', ':', };

    // read file into fileData
    bool ReadFile(const std::string &filePath, std::string &fileData);
    // lex file into tokens 
    void Lex(const std::string &fileData, std::vector<Token> &tokens);
};

#endif // LEXER_H