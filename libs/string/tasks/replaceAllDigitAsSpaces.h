//
// Created by HP on 01.03.2022.
//

#ifndef COURSE_REPLACEALLDIGITASSPACES_H
#define COURSE_REPLACEALLDIGITASSPACES_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];
#define DIGIT_DIFFERENCE  48

void replaceAllDigitAsSpaces(char *s) {
    char *endOfString = getEndOfString(s);
    char *startBuffer = ___stringBuffer;
    char *endOfBuffer = copy(s, endOfString, startBuffer);
    *endOfBuffer = '\0';

    while (*startBuffer != '\0') {
        if (isdigit(*startBuffer))
            for (int j = 0; j < *startBuffer - DIGIT_DIFFERENCE; ++j) {
                *s++ = ' ';
            }
        else
            *s++ = *startBuffer;
        startBuffer++;
    }
}

void test_replaceAllDigitAsSpaces_digitsBeforeWord() {
    char s[MAX_STRING_SIZE] = "123testWords";
    replaceAllDigitAsSpaces(s);
    ASSERT_STRING("      testWords", s);
}

void test_replaceAllDigitAsSpaces_digitsAfterWord() {
    char s[MAX_STRING_SIZE] = "testWords123";
    replaceAllDigitAsSpaces(s);
    ASSERT_STRING("testWords      ", s);
}

void test_replaceAllDigitAsSpaces_digitsBetweenWord() {
    char s[MAX_STRING_SIZE] = "testW123ords";
    replaceAllDigitAsSpaces(s);
    ASSERT_STRING("testW      ords", s);
}

void test_replaceAllDigitAsSpaces_digitsMixInWord() {
    char s[MAX_STRING_SIZE] = "1test2Word3s";
    replaceAllDigitAsSpaces(s);
    ASSERT_STRING(" test  Word   s", s);
}

void test_replaceAllDigitAsSpaces_noDigits() {
    char s[MAX_STRING_SIZE] = "testWords";
    replaceAllDigitAsSpaces(s);
    ASSERT_STRING("testWords", s);
}

void test_replaceAllDigitAsSpaces_voidString() {
    char s[MAX_STRING_SIZE] = "";
    replaceAllDigitAsSpaces(s);
    ASSERT_STRING("", s);
}

void test_replaceAllDigitAsSpaces() {
    test_replaceAllDigitAsSpaces_digitsBeforeWord();
    test_replaceAllDigitAsSpaces_digitsAfterWord();
    test_replaceAllDigitAsSpaces_digitsBetweenWord();
    test_replaceAllDigitAsSpaces_digitsMixInWord();
    test_replaceAllDigitAsSpaces_noDigits();
    test_replaceAllDigitAsSpaces_voidString();
}

#endif //COURSE_REPLACEALLDIGITASSPACES_H
