//
// Created by HP on 04.03.2022.
//

#ifndef COURSE_ISCONTAYNINGSAMEWORDS_H
#define COURSE_ISCONTAYNINGSAMEWORDS_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

bool isContainingSameWords(char *s){
    getBagOfWords(&_bag1, s);
    int numberOfWord = 0;
    while (numberOfWord <_bag1.size){
        for (int i = numberOfWord+1; i < _bag1.size; ++i) {
            if(areWordsSame(_bag1.words[numberOfWord], _bag1.words[i]))
                return 1;
        }
        numberOfWord++;
    }
    return 0;
}

void test_isContainingSameWords_wordContaining(){
    char s1[] = "test words for test";
    assert(isContainingSameWords(s1) == 1);
}


void test_isContainingSameWords_wordNotContaining(){
    char s1[] = "test words for tests";
    assert(isContainingSameWords(s1) == 0);
}


void test_isContainingSameWords_lettersContaining(){
    char s1[] = "a b c a";
    assert(isContainingSameWords(s1) == 1);
}

void test_isContainingSameWords_voidString(){
    char s1[] = "";
    assert(isContainingSameWords(s1) == 0);
}

void test_isContainingSameWords(){
    test_isContainingSameWords_lettersContaining();
    test_isContainingSameWords_voidString();
    test_isContainingSameWords_wordContaining();
    test_isContainingSameWords_wordNotContaining();
}

#endif //COURSE_ISCONTAYNINGSAMEWORDS_H
