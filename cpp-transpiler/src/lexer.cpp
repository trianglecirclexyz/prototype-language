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


// helper functions
void tokenBufferPushBack(std::string &buffer, std::vector<Token> &tokens, 
    std::size_t line, bool strip=true) {
    if(strip) {
        buffer = StringUtils::Strip(buffer);
    }
    if(buffer.empty()) {
        return;
    }
    tokens.push_back(Token(buffer, line));
    buffer.clear();
}

bool isNumber(const std::string &str) {
    int numDecimal = 0;
    for(int i = 0; i < str.size(); i++) {
        if(!isdigit(str[i]) && str[i] != '.') {
            return false;
        }
        else if(str[i] == '.') {
            numDecimal++;
        }
        else if(numDecimal > 1) {
            return false;
        }
    }
    return true;
}

bool isSymbol(const char &c) {
    return Lexer::symbols.count(c);
}

bool isKeyword(const std::string &str) {
    return Lexer::keywords.count(str);
}


void Lexer::Lex(const std::string &fileData, std::vector<Token> &tokens) {

    bool comment = false, string = false, stringFormat = false, number = false;
    std::string charBuffer;
    // iterate char at a time and split tokens
    std::size_t line = 1;
    for(int i = 0; i < fileData.size(); i++) {
        char currChar = fileData[i];
        char nextChar = (i+1) == fileData.size() ? '\0' : fileData[i+1];
        char prevChar = (i-1) < 0 ? '\0' : fileData[i-1];

        if(!comment && currChar == '\"') {
            string = !string;
        }
        else if(string) {
            if(currChar == '$' && nextChar == '{' && prevChar != '\\') {
                stringFormat = true;
                string = false;
                tokenBufferPushBack(charBuffer, tokens, line, false);
            }
        }
        else if(!string && (currChar == '/' && nextChar == '/')) {
            comment = true;
        }
        else if(currChar == '\n') {
            comment = false;
            line++;
            // push buffer at end of line 
            tokenBufferPushBack(charBuffer, tokens, line);
            continue;
        }
        else if(isdigit(currChar) || (currChar == '.' && isdigit(nextChar))) { 
            number = true;
        }
        else if(number && (isspace(currChar) 
            || isSymbol(currChar))) {
            number = false;
            tokenBufferPushBack(charBuffer, tokens, line);
        }
        
        // append char to buffer if not in comment
        if(!comment) {
            charBuffer += currChar;
        }

        // conditions for pushing token to tokens vector
        if(!number && !string && !comment && 
            (isSymbol(nextChar) || isSymbol(currChar)
            || isspace(nextChar))) {
            // certified bruh moment
            // we dont strip if the buffer is the last part of a string segment
            tokenBufferPushBack(charBuffer, tokens, line, 
                !(charBuffer[charBuffer.size()-1] == '\"' 
                && charBuffer[0] != '\"'));
            if(stringFormat && currChar == '}') {
                stringFormat = false;
                string = true;
            }
        }

    }
    // push remaining buffer
    tokenBufferPushBack(charBuffer, tokens, line);

    // idetify token types
    bool openStringSeg = false, openFormatSpecifier = false;
    for(Token &tk: tokens) {
        if(isKeyword(tk.data)) {
            tk.type = TokenType::Keyword;
        }
        else if(tk.data.size() == 1 && isSymbol(tk.data[0])) {
            tk.type = TokenType::Symbol;
            if(tk.data == "{" && openStringSeg) {
                openFormatSpecifier = true;
            }
            else if(tk.data == "}" && openStringSeg) {
                openFormatSpecifier = false;
            }
        }
        // check if constant value (int, float, bool)
        else if(isNumber(tk.data)) {
            tk.type = TokenType::Value;
        }
        else {
            std::string tmpStrip = StringUtils::Strip(tk.data);
            if(tk.data.size() > 1 && tmpStrip[0] == '\"' && 
               tmpStrip[tmpStrip.size() - 1] == '\"') {
                tk.data = tmpStrip;
                tk.type = TokenType::String;
            }
            else if(tk.data[0] == '\"' || tk.data[tk.data.size() - 1] == '\"') {
                tk.type = TokenType::StringSegment;
                openStringSeg = !openStringSeg;
            }
            else if(openStringSeg && !openFormatSpecifier) {
                tk.type = TokenType::StringSegment;
            }
            else if(!isdigit(tk.data[0]) && !isSymbol(tk.data[0])){
                tk.type = TokenType::Identifier;
            }
            // else it stays as invalid

        }
    }

}

// Note: all tokens are combined and parsed in the parsing stage