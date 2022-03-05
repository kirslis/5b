//
// Created by HP on 04.03.2022.
//

#ifndef COURSE_DELETEALLPALINDROS_H
#define COURSE_DELETEALLPALINDROS_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_WORD_SIZE 20

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];
char _wordBuffer[MAX_WORD_SIZE];

void deleteAllPalindros(char *s) {
    copy(s, s + strlen_(s), ___stringBuffer);
    char *beginSearch = ___stringBuffer;
    char *beginDtn = s;
    getBagOfWords(&_bag1, beginSearch);

    for (int i = 0; i < _bag1.size; ++i) {
        WordDescriptor checkingWord = _bag1.words[i];
        if (!isPoly(checkingWord.begin, checkingWord.end)) {
            *beginDtn = ' ';
            WordDescriptor copyWord = _bag1.words[i];
            copy(copyWord.begin, copyWord.end + 1, beginDtn);
            beginDtn += copyWord.end - copyWord.begin + 1;
        }
    }

    *--beginDtn = '\0';
}

void test_deleteAllPalindros_poliWords() {
    char s[] = "aba boy do pap";
    deleteAllPalindros(s);
    ASSERT_STRING("boy do", s);
}

void test_deleteAllPalindros_Latters() {
    char s[] = "a b c d e";
    deleteAllPalindros(s);
    ASSERT_STRING("a b c d e", s);
}

void test_deleteAllPalindros_noPoliWords() {
    char s[] = "abt boy do par";
    deleteAllPalindros(s);
    ASSERT_STRING("abt boy do par", s);
}

void test_deleteAllPalindros() {
   test_deleteAllPalindros_Latters();
   test_deleteAllPalindros_noPoliWords();
   test_deleteAllPalindros_poliWords();
}

#endif //COURSE_DELETEALLPALINDROS_H
