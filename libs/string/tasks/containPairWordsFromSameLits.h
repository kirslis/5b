//
// Created by HP on 04.03.2022.
//

#ifndef COURSE_CONTAINPAIRWORDSFROMSAMELITS_H
#define COURSE_CONTAINPAIRWORDSFROMSAMELITS_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_WORD_SIZE 20

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];
char _wordBuffer[MAX_WORD_SIZE];

void sortLitsByAlpha(WordDescriptor *w) {
    int wSize = w->end - w->begin;
    for (int i = 0; i < wSize; ++i) {
        char min = *(w->begin + i);
        char *iMin = w->begin + i;
        for (int j = i; j < wSize; ++j) {
            if (*(w->begin + j) < min) {
                min = *(w->begin + j);
                iMin = w->begin + j;
            }
        }

        char t = *iMin;
        *iMin = *(w->begin + i);
        *(w->begin + i) = t;
    }
}


bool containPairWordsFromSameLits(char *s) {
    char *endSearch = copy(s, s + strlen_(s), ___stringBuffer);
    char *beginSearch = ___stringBuffer;
    getBagOfWords(&_bag1, beginSearch);

    for (int i = 0; i < _bag1.size; ++i) {
        sortLitsByAlpha(&_bag1.words[i]);
    }

    for (int i = 0; i < _bag1.size; ++i)
        for (int j = i + 1; j < _bag1.size; ++j)
            if (areWordsSame(_bag1.words[i], _bag1.words[j]))
                return 1;

    return 0;
}

void test_containPairWordsFromSameLits_containingPair(){
    char s[] = "bob obb arr";
    assert (containPairWordsFromSameLits(s) == 1);
}

void test_containPairWordsFromSameLits_notContainingPair(){
    char s[] = "bob obs arr";
    assert (containPairWordsFromSameLits(s) == 0);
}

void test_containPairWordsFromSameLits_pairByOneLit(){
    char s[] = "a b g a";
    assert (containPairWordsFromSameLits(s) == 1);
}

void test_containPairWordsFromSameLits_notPairByOneLit(){
    char s[] = "a b c d e";
    assert (containPairWordsFromSameLits(s) == 0);
}

void test_containPairWordsFromSameLits_zeroString(){
    char s[] = "";
    assert (containPairWordsFromSameLits(s) == 0);
}

void test_containPairWordsFromSameLits(){
    test_containPairWordsFromSameLits_containingPair();
    test_containPairWordsFromSameLits_notContainingPair();
    test_containPairWordsFromSameLits_notPairByOneLit();
    test_containPairWordsFromSameLits_pairByOneLit();
    test_containPairWordsFromSameLits_zeroString();
}
#endif //COURSE_CONTAINPAIRWORDSFROMSAMELITS_H
