//
// Created by HP on 04.03.2022.
//

#ifndef COURSE_GETLASTWORDINSTRING1CONTAINEDSTRING2_H
#define COURSE_GETLASTWORDINSTRING1CONTAINEDSTRING2_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_WORD_SIZE 20

WordDescriptor getLastWordInString1ContainedString2(char *s1, char *s2) {
    getBagOfWords(&_bag1, s1);
    bool isContainedFlag = 0;
    int numberOfWord = _bag1.size - 1;
    while (isContainedFlag == 0 && numberOfWord > 0) {
        if (isContained(_bag1.words[numberOfWord], s2))
            isContainedFlag = 1;
        numberOfWord--;
    }
    numberOfWord++;
    if (isContainedFlag == 0)
        numberOfWord = _bag1.size;
    return _bag1.words[numberOfWord];
}

void test_getLastWordInString1ContainedString2_oneContainedWord() {
    char s1[] = "very bad good";
    char s2[] = "good not luck";

    WordDescriptor w = getLastWordInString1ContainedString2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("good", s3);
}


void test_getLastWordInString1ContainedString2_twoContainedWord() {
    char s1[] = "very bad good";
    char s2[] = "good bad luck";

    WordDescriptor w = getLastWordInString1ContainedString2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("good", s3);
}


void test_getLastWordInString1ContainedString2_wordsByOneLit() {
    char s1[] = "a b c d";
    char s2[] = "t d e q";

    WordDescriptor w = getLastWordInString1ContainedString2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("d", s3);
}


void test_getLastWordInString1ContainedString2_noContainedWords() {
    char s1[] = "good bad luck";
    char s2[] = "nope";

    WordDescriptor w = getLastWordInString1ContainedString2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("", s3);
}


void test_getLastWordInString1ContainedString2_voidStrings() {
    char s1[] = "";
    char s2[] = "";

    WordDescriptor w = getLastWordInString1ContainedString2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("", s3);
}

void test_getLastWordInString1ContainedString2() {
    test_getLastWordInString1ContainedString2_noContainedWords();
    test_getLastWordInString1ContainedString2_oneContainedWord();
    test_getLastWordInString1ContainedString2_twoContainedWord();
    test_getLastWordInString1ContainedString2_voidStrings();
    test_getLastWordInString1ContainedString2_wordsByOneLit();
}

#endif //COURSE_GETLASTWORDINSTRING1CONTAINEDSTRING2_H
