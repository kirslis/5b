//
// Created by HP on 04.03.2022.
//

#ifndef COURSE_FILLINGSMALLSTRINGBYREVERSEBIGSTRING_H
#define COURSE_FILLINGSMALLSTRINGBYREVERSEBIGSTRING_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_WORD_SIZE 20

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];
char _wordBuffer[MAX_WORD_SIZE];
char _stringBuffer2[MAX_WORD_SIZE];

void fillingSmallStringByReverseBigString(char *s1, char *s2) {
    copy(s1, s1 + strlen_(s1), ___stringBuffer);
    copy(s2, s2 + strlen_(s2), _stringBuffer2);
    getBagOfWords(&_bag1, ___stringBuffer);
    getBagOfWords(&_bag2, _stringBuffer2);

    char *beginDtn;
    if (_bag1.size > _bag2.size) {
        beginDtn = s2 + strlen_(s2);
        for (int i = _bag1.size - 1; i >= 0; --i) {
            WordDescriptor copyWord = _bag1.words[i];
            *beginDtn++ = ' ';
            copy(copyWord.begin, copyWord.end, beginDtn);
            beginDtn += copyWord.end - copyWord.begin;
        }
        *beginDtn = '\0';
    } else {
        beginDtn = s1 + strlen_(s1);
        for (int i = _bag2.size - 1; i >= 0; --i) {
            WordDescriptor copyWord = _bag2.words[i];
            *beginDtn++ = ' ';
            copy(copyWord.begin, copyWord.end, beginDtn);
            beginDtn += copyWord.end - copyWord.begin;
        }
        *beginDtn = '\0';
    }
}

void test_fillingSmallStringByReverseBigString_secondStringBigger() {
    char s1[] = "good luck";
    char s2[] = "buddy me for";

    fillingSmallStringByReverseBigString(s1, s2);
    ASSERT_STRING("good luck for me buddy", s1);
}


void test_fillingSmallStringByReverseBigString_firstStringBigger() {
    char s1[] = "good luck";
    char s2[] = "buddy";

    fillingSmallStringByReverseBigString(s1, s2);
    ASSERT_STRING("buddy luck good", s2);
}

void test_fillingSmallStringByReverseBigString_twoStringsAreEqual() {
    char s1[] = "good luck";
    char s2[] = "buddy me";

    fillingSmallStringByReverseBigString(s1, s2);
    ASSERT_STRING("good luck me buddy", s1);
}

void test_fillingSmallStringByReverseBigString_voidStrings() {
    char s1[] = "";
    char s2[] = "";

    fillingSmallStringByReverseBigString(s1, s2);
    ASSERT_STRING("", s1);
}

void test_fillingSmallStringByReverseBigString() {
    test_fillingSmallStringByReverseBigString_firstStringBigger();
    test_fillingSmallStringByReverseBigString_secondStringBigger();
    test_fillingSmallStringByReverseBigString_twoStringsAreEqual();
    test_fillingSmallStringByReverseBigString_voidStrings();
}

#endif //COURSE_FILLINGSMALLSTRINGBYREVERSEBIGSTRING_H
