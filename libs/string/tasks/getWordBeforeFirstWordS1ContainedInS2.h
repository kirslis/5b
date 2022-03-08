//
// Created by HP on 04.03.2022.
//

#ifndef COURSE_GETWORDBEFOREFIRSTWORDS1CONTAINEDINS2_H
#define COURSE_GETWORDBEFOREFIRSTWORDS1CONTAINEDINS2_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

WordDescriptor getWordBeforeFirstWordS1ContainedInS2(char *s1, char *s2) {
    getBagOfWords(&_bag1, s1);
    bool isContainedFlag = 0;
    int numberOfWord = 0;
    while (isContainedFlag == 0 && numberOfWord <= _bag1.size) {
        if (isContained(_bag1.words[numberOfWord], s2))
            isContainedFlag = 1;
        numberOfWord++;
    }

    if (isContainedFlag == 0)
        numberOfWord = _bag1.size+2;
    return _bag1.words[numberOfWord - 2];
}


void test_getWordBeforeFistWordS1ContainedInS2_oneContainedWord() {
    char s1[] = "very bad good";
    char s2[] = "good not luck";

    WordDescriptor w = getWordBeforeFirstWordS1ContainedInS2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("bad", s3);
}


void test_getWordBeforeFistWordS1ContainedInS2_twoContainedWord() {
    char s1[] = "very bad good";
    char s2[] = "good bad luck";

    WordDescriptor w = getWordBeforeFirstWordS1ContainedInS2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("very", s3);
}


void test_getWordBeforeFirstWordS1ContainedInS2_wordsByOneLit() {
    char s1[] = "a b c d";
    char s2[] = "t d e q";

    WordDescriptor w = getWordBeforeFirstWordS1ContainedInS2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("c", s3);
}


void test_getWordBeforeFistWordS1ContainedInS2_noContainedWords() {
    char s1[] = "good bad luck";
    char s2[] = "nope";

    WordDescriptor w = getWordBeforeFirstWordS1ContainedInS2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("", s3);
}


void test_getWordBeforeFistWordS1ContainedInS2_voidStrings() {
    char s1[] = "";
    char s2[] = "";

    WordDescriptor w = getWordBeforeFirstWordS1ContainedInS2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("", s3);
}

void testgetWordBeforeFistWordS1ContainedInS2_firstWordContained(){
    char s1[] = "good bad";
    char s2[] = "good bad";

    WordDescriptor w = getWordBeforeFirstWordS1ContainedInS2(s1, s2);

    char *s3[MAX_WORD_SIZE];
    wordDescriptionToString(w, s3);

    ASSERT_STRING("", s3);
}

void test_getWordBeforeFirstWordS1ContainedInS2() {
    test_getWordBeforeFistWordS1ContainedInS2_noContainedWords();
    test_getWordBeforeFistWordS1ContainedInS2_oneContainedWord();
    test_getWordBeforeFistWordS1ContainedInS2_twoContainedWord();
    test_getWordBeforeFistWordS1ContainedInS2_voidStrings();
    test_getWordBeforeFirstWordS1ContainedInS2_wordsByOneLit();
    testgetWordBeforeFistWordS1ContainedInS2_firstWordContained();
}

#endif //COURSE_GETWORDBEFOREFIRSTWORDS1CONTAINEDINS2_H
