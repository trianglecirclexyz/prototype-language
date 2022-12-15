#include <gtest/gtest.h>
#include "lexer.h"

TEST(LexerTest, TokenData) {
    
    std::vector<Token> expectedTokens;

    {
        std::string fileData = 
            "stdout!(\"Hello world!\");";

        expectedTokens = {
            Token("stdout"), 
            Token("!"), 
            Token("("), 
            Token("\"Hello world!\""),
            Token(")"),
            Token(";"),
        };
        
        std::vector<Token> tokens;
        Lexer::Lex(fileData, tokens);
        
        ASSERT_EQ(tokens.size(), expectedTokens.size());

        for(int i = 0; i < tokens.size(); i++) {
            EXPECT_EQ(tokens[i].data, expectedTokens[i].data) << 
                " \u001b[1m\u001b[31mFailure at index " << i << std::endl;
        }
    }

    {
        std::string fileData = 
            "int _12number = 12;";

        expectedTokens = {
            Token("int"), 
            Token("_12number"), 
            Token("="), 
            Token("12"),
            Token(";"),
        };
        
        std::vector<Token> tokens;
        Lexer::Lex(fileData, tokens);
        
        EXPECT_EQ(tokens.size(), expectedTokens.size());

        for(int i = 0; i < tokens.size(); i++) {
            EXPECT_EQ(tokens[i].data, expectedTokens[i].data) << 
                "\u001b[1m\u001b[31mFailure at index " << i << "\u001b[0m" << std::endl;
        }
    }

}

TEST(LexerTest, TokenType) {
    
    std::vector<Token> expectedTokens;

    {
    }

}