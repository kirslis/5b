//
// Created by HP on 02.03.2022.
//

#ifndef COURSE_REVERSEWORDSINSTRING_H
#define COURSE_REVERSEWORDSINSTRING_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];

void reverseWordsInString(char *s) {
    char *end = copy(s, getEndOfString(s), ___stringBuffer);
    char *beginCopy = s - 1;

    char *beginSearch = end - 1;
    WordDescriptor w;

    while (getWordReverse(beginSearch, ___stringBuffer, &w)) {
        beginCopy = copy(w.begin - (w.begin == ___stringBuffer), w.end + 1, beginCopy);

        beginSearch -= w.end - w.begin + 1 + (w.begin == ___stringBuffer);
    }
}

void test_reverseWordsInString_moreLettersInWord() {
    char s[MAX_STRING_SIZE] = "this task has caused me a lot of pain";
    reverseWordsInString(s);

    ASSERT_STRING("pain of lot a me caused has task this", s);
}

void test_reverseWordsInString_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c a b c";
    reverseWordsInString(s);

    ASSERT_STRING("c b a c b a", s);
}

void test_reverseWordsInString_empty() {
    char s[MAX_STRING_SIZE] = "";
    reverseWordsInString(s);

    ASSERT_STRING("", s);
}

void test_reverseWordsInString() {
    test_reverseWordsInString_moreLettersInWord();
    test_reverseWordsInString_oneLetter();
    test_reverseWordsInString_empty();
}

#endif //COURSE_REVERSEWORDSINSTRING_H
