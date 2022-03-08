//
// Created by HP on 03.03.2022.
//

#ifndef COURSE_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define COURSE_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"
#include "assert.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore) {
    if (strlen_(s) == 0)
        return EMPTY_STRING;
    if (*beginWordBefore == (s + strlen_(s)))
        return NOT_FOUND_A_WORD_WITH_A;
    if (*endWordBefore == (s + strlen_(s)) )
        return FIRST_WORD_WITH_A;


    return WORD_FOUND;
}

bool isContainedA(char *beginSearch, const char *endSearch) {
    while (endSearch >= beginSearch && (*beginSearch != 'a' && *beginSearch != 'A'))
        beginSearch++;

    return (*beginSearch == 'a' || *beginSearch == 'A');
}

WordBeforeFirstWordWithAReturnCode printWordBeforeFirstWordWithA(char *s) {
    char *beginSearch = findNonSpace(s);
    WordDescriptor word;
    WordDescriptor lastWord;
    lastWord.end = lastWord.begin = 0;

    while (getWord(beginSearch, &word) && !isContainedA(word.begin, word.end)) {
        lastWord = word;
        beginSearch += word.end - word.begin;
    }

    char *outWord = _stringBuffer;
    copy(lastWord.begin, lastWord.end, outWord);

    printf("%s", outWord);
    return getWordBeforeFirstWordWithA(s, &lastWord.begin, &lastWord.end);
}

void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    beginWord = findNonSpace(s1);
    endWord = s1 + strlen_(s1);
    assert (getWordBeforeFirstWordWithA(s1, &beginWord, &endWord)== EMPTY_STRING);

    char s2[] = " ABC";
    beginWord = findNonSpace(s2);
    endWord = s2 + strlen_(s2);
    assert (getWordBeforeFirstWordWithA(s2, &beginWord, &endWord)== FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert (getWordBeforeFirstWordWithA(s3, &beginWord, &endWord)== WORD_FOUND);

    char s4[] = "B Q WE YR OW IUWR ";
    beginWord = s4 + strlen_(s4);
    endWord = s4 + strlen_(s4);
    assert (getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) ==
            NOT_FOUND_A_WORD_WITH_A);
}


#endif //COURSE_PRINTWORDBEFOREFIRSTWORDWITHA_H
