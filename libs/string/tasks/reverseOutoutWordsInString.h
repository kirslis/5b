//
// Created by HP on 03.03.2022.
//

#ifndef COURSE_REVERSEOUTOUTWORDSINSTRING_H
#define COURSE_REVERSEOUTOUTWORDSINSTRING_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

#define MAX_STRING_SIZE 100
char ___stringBuffer[MAX_STRING_SIZE + 1];


void reverseOutoutWordsInString(char *s) {
    char *end = s + strlen_(s);

    char *beginSearch = end - 1;
    WordDescriptor w;
    char *outWord = ___stringBuffer;
    char *lastSearch = s;

    while (getWordReverse(beginSearch, s, &w) && beginSearch > s)  {
        lastSearch = beginSearch;
        char *beginWord = (w.begin + (*w.begin == ' '));

        copy(beginWord, w.end + 1, outWord);
        *(outWord + (w.end - beginWord + 1)) = '\0';
        printf("%s\n", outWord);
        beginSearch -= w.end - w.begin;

        if(*beginSearch != ' ' && beginSearch!=s)
            beginSearch--;
    }
}

#endif //COURSE_REVERSEOUTOUTWORDSINSTRING_H
