#include "lexer.h"

#include <iostream>


bool Lexer::ReadFile(const std::string &filePath, std::string &fileData) {

    std::ifstream srcFile;
    srcFile.open(filePath);

    if (srcFile.fail()) {
        return false;
    }

    std::stringstream buffer;
    buffer << srcFile.rdbuf();

    fileData = buffer.str();

    return true;
}

// helper function
void tokenBufferPushBack(std::string &buffer, std::vector<Token> &tokens) {
    buffer = StringUtils::Strip(buffer);
    if(buffer.empty()) {
        return;
    }
    tokens.push_back(Token(buffer));
    buffer.clear();
}

bool Lexer::Lex(const std::string &fileData, std::vector<Token> &tokens) {

    bool comment = false, string = false, stringFormat = false, number = false;
    std::string charBuffer;
    // iterate char at a time and split tokens
    for(int i = 0; i < fileData.size(); i++) {
        char currChar = fileData[i];
        char nextChar = (i+1) == fileData.size() ? '\0' : fileData[i+1];

        if(!comment && currChar == '\"') {
            string = !string;
        }
        else if(string) {
            if(currChar == '$' && nextChar == '{') {
                stringFormat = true;
                string = false;
                tokenBufferPushBack(charBuffer, tokens);
            }
        }
        else if(!string && (currChar == '/' && nextChar == '/')) {
            comment = true;
        }
        else if(currChar == '\n') {
            comment = false;
            continue;
        }
        else if(isdigit(currChar) || isdigit(nextChar)) {
            std::cout << "curr, next: " << currChar << ", " << nextChar << std::endl; 
            number = true;
        }
        else if(number && !isdigit(nextChar)) {
            number = false;
        }
        
        // append char to buffer
        if(!comment) {
            charBuffer += currChar;
        }

        // conditions for pushing token to tokens vector
        if(!number && !string && !comment && 
                                     (Lexer::specialSymbols.count(nextChar) 
                                   || Lexer::specialSymbols.count(currChar)
                                   || isspace(nextChar))) {
            tokenBufferPushBack(charBuffer, tokens);
            if(stringFormat && currChar == '}') {
                stringFormat = false;
                string = true;
            }
        }

    }

    // idetify token types
    for(Token &tk: tokens) {
        if(Lexer::keywords.count(tk.data)) {
            tk.type = TokenType::Keyword;
        }
        else if(Lexer::operators.count(tk.data)) {
            tk.type = TokenType::Operator;
        }
        else if(tk.data.size() == 1 && Lexer::specialSymbols.count(tk.data[0])) {
            tk.type = TokenType::SpecialSymbol;
        }
        // check if constant value (int, float, bool)
        else if(false) {
            tk.type = TokenType::Value;
        }
        else {

            // if() {

            // }
            // else if() {

            // }
            // else {
            //     tk.type = TokenType::Identifier;
            // }

        }
    }

    return true;
}