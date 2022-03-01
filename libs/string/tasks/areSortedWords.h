//
// Created by HP on 01.03.2022.
//

#ifndef COURSE_ARESORTEDWORDS_H
#define COURSE_ARESORTEDWORDS_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_STRING_SIZE 100
char __stringBuffer[MAX_STRING_SIZE + 1];

bool areOrderedWords(char *s) {
    char *beginSearch = s;
    WordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return 1;

    WordDescriptor previousWord = currentWord;
    beginSearch = currentWord.end;

    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, previousWord) < 0)
            return 0;

        previousWord = currentWord;
        beginSearch = currentWord.end;
    }
    return 1;
}

void test_isWordsOrdered_oneLetterOrdered() {
    char s[] = "a b c d e";
    assert(areOrderedWords(s));
}

void test_isWordsOrdered_oneLetterUnordered() {
    char s[] = "a b a d e";
    assert(!areOrderedWords(s));
}

void test_isWordsOrdered_ordered() {
    char s[] = "ab bc cd";
    assert(areOrderedWords(s));
}

void test_isWordsOrdered_unordered() {
    char s[] = "ab cd bc";
    assert(!areOrderedWords(s));
}

void test_isWordsOrdered_oneWord() {
    char s[] = "tasteWord";
    assert(areOrderedWords(s));
}

void test_isWordsOrdered_emptyString() {
    char s[] = "";
    assert(areOrderedWords(s));
}

void test_areSortedWords() {
    test_isWordsOrdered_oneLetterOrdered();
    test_isWordsOrdered_oneLetterUnordered();
    test_isWordsOrdered_ordered();
    test_isWordsOrdered_unordered();
    test_isWordsOrdered_oneWord();
    test_isWordsOrdered_emptyString();
}

#endif //COURSE_ARESORTEDWORDS_H
