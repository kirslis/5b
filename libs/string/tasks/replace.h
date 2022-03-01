//
// Created by HP on 01.03.2022.
//

#ifndef COURSE_REPLACE_H
#define COURSE_REPLACE_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"

#define MAX_STRING_SIZE 100
char __stringBuffer[MAX_STRING_SIZE + 1];

bool isSameWords(char *s, char *w, size_t wSize) {
    for (int i = 0; i < wSize; ++i)
        if (*s++ != *w++)
            return 0;
    return 1;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), __stringBuffer);
        *(__stringBuffer + strlen_(source)) ='\0';
        readPtr = __stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (isSameWords(readPtr, w1, w1Size)){
            char *copyW = w2;
            for (int i = 0; i < w2Size; ++i)
                *recPtr++ = *copyW++;
            readPtr += w1Size;
        }
        else
            *recPtr++ = *readPtr++;
    }
    *recPtr = '\0';
}

void test_replace_firstWord(){
    char s[MAX_STRING_SIZE] = "testWords";
    char w1[] = "test";
    char w2[] = "NO";
    replace(s, w1,w2);
    ASSERT_STRING("NOWords", s);
}

void test_replace_lastWord(){
    char s[MAX_STRING_SIZE] = "testWords";
    char w1[] = "Words";
    char w2[] = "NO";
    replace(s, w1,w2);
    ASSERT_STRING("testNO", s);
}

void test_replace_middleWord(){
    char s[MAX_STRING_SIZE] = "testWords";
    char w1[] = "st";
    char w2[] = "NO";
    replace(s, w1,w2);
    ASSERT_STRING("teNOWords", s);
}

void test_replace_twoWord(){
    char s[MAX_STRING_SIZE] = "testWords";
    char w1[] = "t";
    char w2[] = "NO";
    replace(s, w1,w2);
    ASSERT_STRING("NOesNOWords", s);
}

void test_replace_noWord(){
    char s[MAX_STRING_SIZE] = "testWords";
    char w1[] = "good";
    char w2[] = "NO";
    replace(s, w1,w2);
    ASSERT_STRING("testWords", s);
}

void test_replace_voidString(){
    char s[MAX_STRING_SIZE] = "";
    char w1[] = "test";
    char w2[] = "NO";
    replace(s, w1,w2);
    ASSERT_STRING("", s);
}

void test_replace(){
    test_replace_firstWord();
    test_replace_lastWord();
    test_replace_middleWord();
    test_replace_noWord();
    test_replace_twoWord();
    test_replace_voidString();
}
#endif //COURSE_REPLACE_H
