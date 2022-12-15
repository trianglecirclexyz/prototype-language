#include <gtest/gtest.h>
#include "string_utils.h"

TEST(StringUtilsTest, Slice) {
    EXPECT_EQ(StringUtils::Slice("hello", 0), "hello");
    EXPECT_EQ(StringUtils::Slice("hello", 0, 0), "hello");
    EXPECT_EQ(StringUtils::Slice("hello", 0, 10), "hello");
    EXPECT_EQ(StringUtils::Slice("hello", 2, 4), "ll");
    EXPECT_EQ(StringUtils::Slice("hello", 2), "llo");
    EXPECT_EQ(StringUtils::Slice("hello", 3, -2), "");
    EXPECT_EQ(StringUtils::Slice("hello", -3, -1), "ll");
    EXPECT_EQ(StringUtils::Slice("hello", 3, -1), "l");
    EXPECT_EQ(StringUtils::Slice("hello", -2, 0), "lo");
    EXPECT_EQ(StringUtils::Slice("hello", -2), "lo");
    EXPECT_EQ(StringUtils::Slice("hello", -5), "hello");
}

TEST(StringUtilsTest, Capitalize) {
    EXPECT_EQ(StringUtils::Capitalize("hello world"), "Hello world");
    EXPECT_EQ(StringUtils::Capitalize("say my name"), "Say my name");
    EXPECT_EQ(StringUtils::Capitalize("domain expansion: chimera shadow Garden!!!"), "Domain expansion: chimera shadow garden!!!");
    EXPECT_EQ(StringUtils::Capitalize("have some more chicken\nHave Some More Pie"), "Have some more chicken\nhave some more pie");
}

TEST(StringUtilsTest, Upper) {
    EXPECT_EQ(StringUtils::Upper("hello world"), "HELLO WORLD");
    EXPECT_EQ(StringUtils::Upper("no, i am not angry!!!"), "NO, I AM NOT ANGRY!!!");
    EXPECT_EQ(StringUtils::Upper("a b C d EFg"), "A B C D EFG");
}

TEST(StringUtilsTest, Lower) {
    EXPECT_EQ(StringUtils::Lower("hello WOrld"), "hello world");
    EXPECT_EQ(StringUtils::Lower("AAAAAAAA\n\tHAHAHAHAHAHHA"), "aaaaaaaa\n\thahahahahahha");
    EXPECT_EQ(StringUtils::Lower("\n\ta b C d EFg"), "\n\ta b c d efg");
}

TEST(StringUtilsTest, LStrip) {
    EXPECT_EQ(StringUtils::LStrip("    how do you do"), "how do you do");
    EXPECT_EQ(StringUtils::LStrip("\nhow do you do"), "how do you do");
    EXPECT_EQ(StringUtils::LStrip("\thow do you do"), "how do you do");
    EXPECT_EQ(StringUtils::LStrip("\n  \te  \t\n   "), "e  \t\n   ");
    EXPECT_EQ(StringUtils::LStrip("     "), "");
    EXPECT_EQ(StringUtils::LStrip(""), "");
    EXPECT_EQ(StringUtils::LStrip("\n\t"), "");
    EXPECT_EQ(StringUtils::LStrip(" \n\t  \n "), "");

}

TEST(StringUtilsTest, RStrip) {
    EXPECT_EQ(StringUtils::RStrip("how do you do    "), "how do you do");
    EXPECT_EQ(StringUtils::RStrip("how do you do\n"), "how do you do");
    EXPECT_EQ(StringUtils::RStrip("how do you do\t"), "how do you do");
    EXPECT_EQ(StringUtils::RStrip("\n  \te   \n\t"), "\n  \te");
    EXPECT_EQ(StringUtils::RStrip("     "), "");
    EXPECT_EQ(StringUtils::RStrip(""), "");
    EXPECT_EQ(StringUtils::RStrip("\n\t"), "");
    EXPECT_EQ(StringUtils::RStrip(" \n\t  \n "), "");
}

TEST(StringUtilsTest, Strip) {
    EXPECT_EQ(StringUtils::Strip("   hello   "), "hello");
    EXPECT_EQ(StringUtils::Strip("\nhello\n"), "hello");
    EXPECT_EQ(StringUtils::Strip("\thello\t"), "hello");
    EXPECT_EQ(StringUtils::Strip("\t\n    hello\n  \t"), "hello");
    EXPECT_EQ(StringUtils::Strip("\n  \te  \t\n   "), "e");
    EXPECT_EQ(StringUtils::Strip(""), "");
    EXPECT_EQ(StringUtils::Strip("     "), "");
    EXPECT_EQ(StringUtils::Strip("\n\t"), "");
    EXPECT_EQ(StringUtils::Strip(" \n\t  \n "), "");

}

TEST(StringUtilsTest, Center) {
    EXPECT_EQ(StringUtils::Center("hello", 10), "  hello   ");
    EXPECT_EQ(StringUtils::Center("hello", 2), "hello");
    EXPECT_EQ(StringUtils::Center("hello", 6), "hello ");
    EXPECT_EQ(StringUtils::Center(" my name is", 20), "     my name is     ");
    EXPECT_EQ(StringUtils::Center(" my name is", 12), " my name is ");
    EXPECT_EQ(StringUtils::Center(" my name is", 13), "  my name is ");
    EXPECT_EQ(StringUtils::Center(" my name is", 20, '.'), ".... my name is.....");
    EXPECT_EQ(StringUtils::Center(" my name is", 12, 'e'), " my name ise");
    EXPECT_EQ(StringUtils::Center(" my name is", 13, '~'), "~ my name is~");
}

TEST(StringUtilsTest, LJust) {
    EXPECT_EQ(StringUtils::LJust("hello", 10), "hello     ");
    EXPECT_EQ(StringUtils::LJust("hello", 2), "hello");
    EXPECT_EQ(StringUtils::LJust("hello", 6), "hello ");
    EXPECT_EQ(StringUtils::LJust(" my name is", 20), " my name is         ");
    EXPECT_EQ(StringUtils::LJust(" my name is", 12), " my name is ");
    EXPECT_EQ(StringUtils::LJust(" my name is", 13), " my name is  ");
    EXPECT_EQ(StringUtils::LJust(" my name is", 20, '.'), " my name is.........");
    EXPECT_EQ(StringUtils::LJust(" my name is", 12, 'e'), " my name ise");
    EXPECT_EQ(StringUtils::LJust(" my name is", 13, '~'), " my name is~~");
}

TEST(StringUtilsTest, RJust) {
    EXPECT_EQ(StringUtils::RJust("hello", 10), "     hello");
    EXPECT_EQ(StringUtils::RJust("hello", 2), "hello");
    EXPECT_EQ(StringUtils::RJust("hello", 6), " hello");
    EXPECT_EQ(StringUtils::RJust(" my name is", 20), "          my name is");
    EXPECT_EQ(StringUtils::RJust(" my name is", 12), "  my name is");
    EXPECT_EQ(StringUtils::RJust(" my name is", 13), "   my name is");
    EXPECT_EQ(StringUtils::RJust(" my name is", 20, '.'), "......... my name is");
    EXPECT_EQ(StringUtils::RJust(" my name is", 12, 'e'), "e my name is");
    EXPECT_EQ(StringUtils::RJust(" my name is", 13, '~'), "~~ my name is");
}

TEST(StringUtilsTest, Replace) {
    EXPECT_EQ(StringUtils::Replace("hello", "hello", "hello"), "hello");
    EXPECT_EQ(StringUtils::Replace("hello", "hell", "heaven"), "heaveno");
    EXPECT_EQ(StringUtils::Replace("hello", "he", "she"), "shello");
    EXPECT_EQ(StringUtils::Replace("hello", "something", "literally anything"), "hello");
    EXPECT_EQ(StringUtils::Replace("hello", "hellow", "x"), "hello");
    EXPECT_EQ(StringUtils::Replace("eeeeeeeeeee", "ee", "a"), "aaaaae");
    EXPECT_EQ(StringUtils::Replace("ee.eee.", "ee", "a"), "a.ae.");
    EXPECT_EQ(StringUtils::Replace("changeme", "changeme", "i have now been changed, poggers\n\n\t"), "i have now been changed, poggers\n\n\t");
}

TEST(StringUtilsTest, Split) {
    std::vector<std::string> tmpVec = {"word"};
    EXPECT_EQ(StringUtils::Split("word"), tmpVec);

    tmpVec = {"word", ""};
    EXPECT_EQ(StringUtils::Split("word "), tmpVec);

    tmpVec = {"", "word", ""};
    EXPECT_EQ(StringUtils::Split(" word "), tmpVec);

    tmpVec = {"", "word", ""};
    EXPECT_EQ(StringUtils::Split(" word ", " "), tmpVec);

    tmpVec = {"", "word", ""};
    EXPECT_EQ(StringUtils::Split("ccwordcc", "cc"), tmpVec);

    tmpVec = {" word "};
    EXPECT_EQ(StringUtils::Split(" word ", "\n"), tmpVec);

    tmpVec = {"hello,", "how", "are", "you", "?\n\t"};
    EXPECT_EQ(StringUtils::Split("hello, how are you ?\n\t", " "), tmpVec);

    tmpVec = {"hello,", "how", "are", "you", "?", "", ""};
    EXPECT_EQ(StringUtils::Split("hello, how are you ?  "), tmpVec);

    tmpVec = {"hello,", "", "how", "are", "you", "?\n\t"};
    EXPECT_EQ(StringUtils::Split("hello,  how are you ?\n\t", " "), tmpVec);

    tmpVec = {"word1", "\tword2"};
    EXPECT_EQ(StringUtils::Split("word1\n\tword2", "\n"), tmpVec);

    tmpVec = {"word1", "word2"};
    EXPECT_EQ(StringUtils::Split("word1word3word2", "word3"), tmpVec);
    
    tmpVec = {"word1", "word2"};
    EXPECT_EQ(StringUtils::Split("word1 word2"), tmpVec);
    EXPECT_EQ(StringUtils::Split("word1 word2", " "), tmpVec);
    
}

TEST(StringUtilsTest, Join) {
    std::vector<std::string> tmpVec = {"word1", "word2", "word3\n"};
    EXPECT_EQ(StringUtils::Join(" ", tmpVec), "word1 word2 word3\n");

    tmpVec = {"word1", "word2", "word3"};
    EXPECT_EQ(StringUtils::Join("word4", tmpVec), "word1word4word2word4word3");
}

TEST(StringUtilsTest, ExpandTabs) {

    // some examples taken from https://www.programiz.com/python-programming/methods/string/expandtabs 

    EXPECT_EQ(StringUtils::ExpandTabs("xyz\t12345\tabc", 8), "xyz     12345   abc");
    EXPECT_EQ(StringUtils::ExpandTabs("\txyz\t12345\tabc", 8), "        xyz     12345   abc");
    EXPECT_EQ(StringUtils::ExpandTabs("xyz\t12345\tabc", 2), "xyz 12345 abc");
    EXPECT_EQ(StringUtils::ExpandTabs("xyz\t12345\tabc", 3), "xyz   12345 abc");
    EXPECT_EQ(StringUtils::ExpandTabs("xyz\t12345\tabc", 4), "xyz 12345   abc");
    EXPECT_EQ(StringUtils::ExpandTabs("xyz\t12345\tabc"), "xyz 12345   abc");
    EXPECT_EQ(StringUtils::ExpandTabs("xyz\t12345\tabc", 5), "xyz  12345     abc");
    EXPECT_EQ(StringUtils::ExpandTabs("xyz\t12345\tabc", 6), "xyz   12345 abc");

}

TEST(StringUtilsTest, EditDistance) {
    
    EXPECT_EQ(StringUtils::EditDistance("right", "lefT"), 5);
    EXPECT_EQ(StringUtils::EditDistance("right", "lefT", true), 4);
    EXPECT_EQ(StringUtils::EditDistance("righT", "lefT"), 4);
    EXPECT_EQ(StringUtils::EditDistance("righT", "lefT", true), 4);
    EXPECT_EQ(StringUtils::EditDistance("my name is walter white", "say my name"), 18);
    EXPECT_EQ(StringUtils::EditDistance("cabbages", "rabbit"), 5);

}
