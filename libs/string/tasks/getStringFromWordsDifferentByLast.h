//
// Created by HP on 04.03.2022.
//

#ifndef COURSE_GETSTRINGFROMWORDSDIFFERENTBYLAST_H
#define COURSE_GETSTRINGFROMWORDSDIFFERENTBYLAST_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_WORD_SIZE 20

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];
char _wordBuffer[MAX_WORD_SIZE];

char *getStringFromWordsDifferentByLast(char *s) {
    char *beginDtn = s;
    char *beginSearch = copy(s, s + strlen_(s), ___stringBuffer);
    getBagOfWords(&_bag1, ___stringBuffer);
    if (_bag1.size != 0)
        for (int i = 0; i < _bag1.size - 1; ++i) {
            if (!areWordsSame(_bag1.words[i], _bag1.words[_bag1.size - 1])) {
                *beginDtn = ' ';
                WordDescriptor copyWord = _bag1.words[i];
                copy(copyWord.begin, copyWord.end + 1, beginDtn);
                beginDtn += copyWord.end - copyWord.begin + 1;
            }
        }
    *--beginDtn = '\0';
    return s;
}

void test_getStringFromWordsDifferentByLast_gotSameWords() {
    char s[] = "good luck bad top bad";
    char *b = getStringFromWordsDifferentByLast(s);
    ASSERT_STRING("good luck top", b);
}


void test_getStringFromWordsDifferentByLast_noSameWords() {
    char s[] = "good luck blue top bad";
    char *b = getStringFromWordsDifferentByLast(s);
    ASSERT_STRING("good luck blue top", b);
}


void test_getStringFromWordsDifferentByLast_gotSameOneLatters() {
    char s[] = "a b c b e b";
    char *b = getStringFromWordsDifferentByLast(s);
    ASSERT_STRING("a c e", b);
}


void test_getStringFromWordsDifferentByLast_noSameOneLatters() {
    char s[] = "a b c d e f g";
    char *b = getStringFromWordsDifferentByLast(s);
    ASSERT_STRING("a b c d e f", b);
}


void test_getStringFromWordsDifferentByLast_gotMoreSameWords() {
    char s[] = "good bad luck bad top bad";
    char *b = getStringFromWordsDifferentByLast(s);
    ASSERT_STRING("good luck top", b);
}

void test_getStringFromWordsDifferentByLast_voidString() {
    char s[] = "";
    char *b = getStringFromWordsDifferentByLast(s);
    ASSERT_STRING("", b);
}

void test_getStringFromWordsDifferentByLast() {
    test_getStringFromWordsDifferentByLast_gotMoreSameWords();
    test_getStringFromWordsDifferentByLast_gotSameOneLatters();
    test_getStringFromWordsDifferentByLast_gotSameWords();
    test_getStringFromWordsDifferentByLast_noSameOneLatters();
    test_getStringFromWordsDifferentByLast_noSameWords();
    test_getStringFromWordsDifferentByLast_voidString();
}


#endif //COURSE_GETSTRINGFROMWORDSDIFFERENTBYLAST_H
