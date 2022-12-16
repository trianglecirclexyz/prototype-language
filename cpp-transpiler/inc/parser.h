#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include <vector>

// enum ErrorType {

// };

// struct Error {
//     std::size_t line;
//     ErrorType type;
// };

namespace Parser {

    bool Parse(const std::vector<Token> &tokens);

};

#endif // PARSER_H