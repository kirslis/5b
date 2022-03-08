//
// Created by HP on 08.03.2022.
//

#ifndef COURSE_ISSTRINGCONTAINALLLITSOFWORD_H
#define COURSE_ISSTRINGCONTAINALLLITSOFWORD_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"
#include "malloc.h"

typedef struct containingLit {
    char lit;
    bool isContained;
} containingLit;

typedef struct containingLits {
    containingLit lit[MAX_WORD_SIZE];
    char nLits;
} containingLits;

bool checkLit(char *s, containingLits lits){
    char *beginSearch = s;
    char *endSearch = s + strlen_(s);

    while (beginSearch != endSearch){
        for (int i = 0; i < lits.nLits; ++i) {
            if (*beginSearch == lits.lit[i].lit)
                lits.lit[i].isContained = 1;
        }
        beginSearch++;
    }

    for (int i = 0; i < lits.nLits; ++i) {
        if (lits.lit[i].isContained == 0)
            return 0;
    }

    return 1;
}

bool isStringContainAllLitsOfWord(char *s, WordDescriptor w) {
    containingLits litsList;

    int lengthOfWord = (w.end - w.begin);
    if(lengthOfWord <= 0)
        return 0;

    for (int i = 0; i < lengthOfWord; ++i) {
        litsList.lit[i].lit = *w.begin;
        litsList.lit[i].isContained = 0;
        w.begin++;
        litsList.nLits = i + 1;
    }

    return (litsList.nLits != 0 && checkLit(s, litsList)) ;
}

void test_isStringContainAllLitsOfWord_litsDoesntContaining(){
    char s[] = "test string";
    char s1[] = "cool";
    WordDescriptor w;
    getWord(s1, &w);

    assert(isStringContainAllLitsOfWord(s, w) == 0);
}

void test_isStringContainAllLitsOfWord_litsAreContaining(){
    char s[] = "test string";
    char s1[] = "tig";
    WordDescriptor w;
    getWord(s1, &w);

    assert(isStringContainAllLitsOfWord(s, w) == 1);
}

void test_isStringContainAllLitsOfWord_litsAreContainingDuplet(){
    char s[] = "test string";
    char s1[] = "ttig";
    WordDescriptor w;
    getWord(s1, &w);

    assert(isStringContainAllLitsOfWord(s, w) == 1);
}

void test_isStringContainAllLitsOfWord_voidWord(){
    char s[] = "test string";
    char s1[] = "";
    WordDescriptor w;
    getWord(s1, &w);

    assert(isStringContainAllLitsOfWord(s, w) == 0);
}

void test_isStringContainAllLitsOfWord_voidStrig(){
    char s[] = "";
    char s1[] = "cool";
    WordDescriptor w;
    getWord(s1, &w);

    assert(isStringContainAllLitsOfWord(s, w) == 0);
}

void test_isStringContainAllLitsOfWord_allVoid(){
    char s[] = "";
    char s1[] = "";
    WordDescriptor w;
    getWord(s1, &w);

    assert(isStringContainAllLitsOfWord(s, w) == 0);
}

void test_isStringContainAllLitsOfWord(){
    test_isStringContainAllLitsOfWord_litsDoesntContaining();
    test_isStringContainAllLitsOfWord_allVoid();
    test_isStringContainAllLitsOfWord_litsAreContaining();
    test_isStringContainAllLitsOfWord_litsAreContainingDuplet();
    test_isStringContainAllLitsOfWord_voidStrig();
    test_isStringContainAllLitsOfWord_voidWord();
}

#endif //COURSE_ISSTRINGCONTAINALLLITSOFWORD_H
