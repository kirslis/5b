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

void deleteAllPalindroms(char *s) {
    copy(s, s + strlen_(s), _stringBuffer);
    char *beginSearch = _stringBuffer;
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

void test_deleteAllPalindroms_poliWords() {
    char s[] = "aba boy do pap";
    deleteAllPalindroms(s);
    ASSERT_STRING("boy do", s);
}

void test_deleteAllPalindroms_Latters() {
    char s[] = "a b c d e";
    deleteAllPalindroms(s);
    ASSERT_STRING("a b c d e", s);
}

void test_deleteAllPalindroms_noPoliWords() {
    char s[] = "abt boy do par";
    deleteAllPalindroms(s);
    ASSERT_STRING("abt boy do par", s);
}

void test_deleteAllPalindroms() {
    test_deleteAllPalindroms_Latters();
    test_deleteAllPalindroms_noPoliWords();
    test_deleteAllPalindroms_poliWords();
}

#endif //COURSE_DELETEALLPALINDROS_H
