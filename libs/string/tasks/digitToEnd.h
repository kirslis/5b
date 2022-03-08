//
// Created by HP on 01.03.2022.
//

#ifndef COURSE_DIGITTOEND_H
#define COURSE_DIGITTOEND_H
#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"

void digitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void test_digitToEnd_digitsBefore(){
    char s[] = "123testWords";
    WordDescriptor w ;
    getWord(s, &w);
    digitToEnd(w);
    ASSERT_STRING("testWords123", s);
}

void test_digitToEnd_digitsAfter(){
    char s[] = "testWords123";
    WordDescriptor w ;
    getWord(s, &w);
    digitToEnd(w);
    ASSERT_STRING("testWords123", s);
}

void test_digitToEnd_digitsBetween(){
    char s[] = "test123Words";
    WordDescriptor w ;
    getWord(s, &w);
    digitToEnd(w);
    ASSERT_STRING("testWords123", s);
}

void test_digitToEnd_digitsMixed(){
    char s[] = "1tes2tWo3rds";
    WordDescriptor w ;
    getWord(s, &w);
    digitToEnd(w);
    ASSERT_STRING("testWords123", s);
}

void test_digitToEnd_allDigits(){
    char s[] = "123";
    WordDescriptor w ;
    getWord(s, &w);
    digitToEnd(w);
    ASSERT_STRING("123", s);
}

void test_digitToEnd_noDigits(){
    char s[] = "testWords";
    WordDescriptor w ;
    getWord(s, &w);
    digitToEnd(w);
    ASSERT_STRING("testWords", s);
}


void test_digitToEnd_voidString(){
    char s[] = "";
    WordDescriptor w ;
    getWord(s, &w);
    digitToEnd(w);
    ASSERT_STRING("", s);
}


void test_digitToEnd(){
    test_digitToEnd_allDigits();
    test_digitToEnd_digitsAfter();
    test_digitToEnd_digitsBefore();
    test_digitToEnd_digitsBetween();
    test_digitToEnd_digitsMixed();
    test_digitToEnd_noDigits();
    test_digitToEnd_voidString();
}

#endif //COURSE_DIGITTOEND_H
