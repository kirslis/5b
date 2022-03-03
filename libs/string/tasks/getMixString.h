//
// Created by HP on 03.03.2022.
//

#ifndef COURSE_GETMIXSTRING_H
#define COURSE_GETMIXSTRING_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];

char *getMixString(char *s1, char *s2) {
    char *mixString = ___stringBuffer;
    *mixString = '\0';

    char *result = mixString;

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            copy(word1.begin, word1.end, mixString);
            *(mixString + (word1.end - word1.begin)) = ' ';
            mixString += word1.end - word1.begin + 1;
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            copy(word2.begin, word2.end, mixString);
            *(mixString + (word2.end - word2.begin)) = ' ';
            mixString += word2.end - word2.begin + 1;
            beginSearch2 = word2.end;
        }
    }
    *(mixString - 1) = '\0';
    return result;
}

void test_getMixString_manyWords(){
    char s1[] = "bob the best";
    char s2[] = "not at all";

    ASSERT_STRING("bob not the at best all", getMixString(s1, s2));
}

void test_getMixString_oneWord(){
    char s1[] = "bob";
    char s2[] = "not";

    ASSERT_STRING("bob not", getMixString(s1, s2));
}

void test_getMixString_secondWordShorter(){
    char s1[] = "bob the best";
    char s2[] = "not";

    ASSERT_STRING("bob not the best", getMixString(s1, s2));
}

void test_getMixString_firstWordShorter(){
    char s1[] = "bob";
    char s2[] = "not at all";

    ASSERT_STRING("bob not at all", getMixString(s1, s2));
}

void test_getMixString_secondWordIsVoid(){
    char s1[] = "bob the best";
    char s2[] = "";

    ASSERT_STRING("bob the best", getMixString(s1, s2));
}

void test_getMixString_firstWordIsVoid(){
    char s1[] = "";
    char s2[] = "not at all";

    ASSERT_STRING("not at all", getMixString(s1, s2));
}

void test_getMixString_voidStrings(){
    char s1[] = "";
    char s2[] = "";

    ASSERT_STRING("", getMixString(s1, s2));
}

void test_getMixString(){
    test_getMixString_firstWordIsVoid();
    test_getMixString_firstWordShorter();
    test_getMixString_manyWords();
    test_getMixString_oneWord();
    test_getMixString_secondWordIsVoid();
    test_getMixString_secondWordShorter();
    test_getMixString_voidStrings();
}

#endif //COURSE_GETMIXSTRING_H
