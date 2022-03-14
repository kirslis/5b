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


void reverseWordsInString(char *s) {
    copy(s, getEndOfString(s), _stringBuffer);
    char *beginRead = _stringBuffer;
    char *beginCopy = s;

    getBagOfWords(&_bag1, beginRead);

    for (int i = _bag1.size; i > 0 ; --i) {
        copy(_bag1.words[i - 1].begin, _bag1.words[i - 1].end, beginCopy);
        beginCopy += _bag1.words[i-1].end - _bag1.words[i-1].begin;
        *beginCopy++ = ' ';
    }
    *(beginCopy - 1) = '\0';
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
