//
// Created by HP on 02.03.2022.
//

#ifndef COURSE_COUNTPOLINDROMS_H
#define COURSE_COUNTPOLINDROMS_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];

char *findComma(char *beginScan, char *endScan) {
    while (*beginScan != ',' && beginScan != endScan)
        beginScan++;
    return beginScan;
}

int countOfPolindroms(char *s) {
    int countOfPoli = 0;
    char *startCheck = s;
    char *end = getEndOfString(s);

    while (startCheck < end) {
        char *endCheck = findComma(startCheck, end);

        countOfPoli += isPoly(startCheck, endCheck);

        startCheck = endCheck+1;
    }

    return countOfPoli;
}

void test_countOfPolindroms_onePoli() {
    char s[] = "aba";

    assert((countOfPolindroms(s)) == 1);
}

void test_countOfPolindroms_oneNotPoli() {
    char s[] = "abd";

    assert((countOfPolindroms(s)) == 0);
}


void test_countOfPolindroms_twoPoli() {
    char s[] = "aba,baab";

    assert((countOfPolindroms(s)) == 2);
}

void test_countOfPolindroms_twoNotPoli() {
    char s[] = "abd,dabba";

    assert((countOfPolindroms(s)) == 0);
}


void test_countOfPolindroms_mixedString() {
    char s[] = "aba,dabba";

    assert((countOfPolindroms(s)) == 1);
}

void test_countOfPolindroms_voidString() {
    char s[] = "";

    assert((countOfPolindroms(s)) == 0);
}

void test_countOfPolindroms() {
    test_countOfPolindroms_mixedString();
    test_countOfPolindroms_oneNotPoli();
    test_countOfPolindroms_onePoli();
    test_countOfPolindroms_twoNotPoli();
    test_countOfPolindroms_twoPoli();
    test_countOfPolindroms_voidString();
}

#endif //COURSE_COUNTPOLINDROMS_H
