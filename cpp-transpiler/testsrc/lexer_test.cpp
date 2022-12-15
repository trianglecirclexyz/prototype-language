#include <gtest/gtest.h>
#include "lexer.h"

TEST(LexerTest, Simple) {
    
    std::vector<Token> expectedTokens;

    {
        std::string fileData = 
            "stdout!(\"Hello world!\");";

        expectedTokens = {
            Token("stdout", TokenType::Identifier), 
            Token("!", TokenType::SpecialSymbol), 
            Token("(", TokenType::SpecialSymbol), 
            Token("\"Hello world!\"", TokenType::String),
            Token(")", TokenType::SpecialSymbol),
            Token(";", TokenType::SpecialSymbol),
        };
        
        std::vector<Token> tokens;
        Lexer::Lex(fileData, tokens);
        
        ASSERT_EQ(tokens.size(), expectedTokens.size());

        for(int i = 0; i < tokens.size(); i++) {
            EXPECT_EQ(tokens[i].data, expectedTokens[i].data) << 
                " \u001b[1m\u001b[31mFailure at index " << i << "\u001b[0m" << std::endl;
            EXPECT_EQ(tokens[i].type, expectedTokens[i].type) << 
                " \u001b[1m\u001b[31mFailure at index " << i << "\u001b[0m" << std::endl;
        }
    }

    {
        std::string fileData = 
            "int _12number = 12;";

        expectedTokens = {
            Token("int", TokenType::Keyword), 
            Token("_12number", TokenType::Identifier), 
            Token("=", TokenType::Operator), 
            Token("12", TokenType::Value),
            Token(";", TokenType::SpecialSymbol),
        };
        
        std::vector<Token> tokens;
        Lexer::Lex(fileData, tokens);
        
        EXPECT_EQ(tokens.size(), expectedTokens.size());

        for(int i = 0; i < tokens.size(); i++) {
            EXPECT_EQ(tokens[i].data, expectedTokens[i].data) << 
                "\u001b[1m\u001b[31mFailure at index " << i << "\u001b[0m" << std::endl;
            EXPECT_EQ(tokens[i].type, expectedTokens[i].type) << 
                " \u001b[1m\u001b[31mFailure at index " << i << "\u001b[0m" << std::endl;
        }
    }

}

TEST(LexerTest, FormatString) {
    
    std::vector<Token> expectedTokens;

    {
        std::string fileData = 
            "stdout!(\"Hello ${p1.name}, how is ${p2.name} doing?\");\n"
            "stdout!(\"\\${escaped}\");";

        expectedTokens = {
            Token("stdout", TokenType::Identifier), 
            Token("!", TokenType::SpecialSymbol), 
            Token("(", TokenType::SpecialSymbol), 
            Token("\"Hello ", TokenType::StringSegment),
            Token("$", TokenType::SpecialSymbol),
            Token("{", TokenType::SpecialSymbol),
            Token("p1", TokenType::Identifier),
            Token(".", TokenType::SpecialSymbol),
            Token("name", TokenType::Identifier),
            Token("}", TokenType::SpecialSymbol),
            Token(", how is ", TokenType::StringSegment),
            Token("$", TokenType::SpecialSymbol),
            Token("{", TokenType::SpecialSymbol),
            Token("p2", TokenType::Identifier),
            Token(".", TokenType::SpecialSymbol),
            Token("name", TokenType::Identifier),
            Token("}", TokenType::SpecialSymbol),
            Token(" doing?\"", TokenType::StringSegment),
            Token(")", TokenType::SpecialSymbol),
            Token(";", TokenType::SpecialSymbol),

            Token("stdout", TokenType::Identifier), 
            Token("!", TokenType::SpecialSymbol), 
            Token("(", TokenType::SpecialSymbol),
            Token("\"\\${escaped}\"", TokenType::String),
            Token(")", TokenType::SpecialSymbol),
            Token(";", TokenType::SpecialSymbol),
        };
        
        std::vector<Token> tokens;
        Lexer::Lex(fileData, tokens);
        
        ASSERT_EQ(tokens.size(), expectedTokens.size());

        for(int i = 0; i < tokens.size(); i++) {
            EXPECT_EQ(tokens[i].data, expectedTokens[i].data) << 
                " \u001b[1m\u001b[31mFailure at index " << i << "\u001b[0m" << std::endl;
            EXPECT_EQ(tokens[i].type, expectedTokens[i].type) << 
                " \u001b[1m\u001b[31mFailure at index " << i << "\u001b[0m" << std::endl;
        }
    }

}