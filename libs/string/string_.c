//
// Created by HP on 27.02.2022.
//

#include "string_.h"
#include <ctype.h>
#include <memory.h>
#include "stdio.h"

#define MAX_STRING_SIZE 100
char _stringBuffer[MAX_STRING_SIZE + 1];

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    char *end = begin;
    while (isspace(*end))
        end++;

    return end;
}

char *findSpace(char *begin) {
    char *end = begin;
    while (!isspace(*end) && *end != '\0')
        end++;

    return end;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin -= 1;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin -= 1;

    if (rbegin == rend)
        *(rbegin-- - 1) = ' ';

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs && *lhs == *rhs)
        lhs++, rhs++;

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource))
            *(beginDestination++) = *beginSource;

        beginSource++;
    }
    return beginDestination;
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource))
            *beginDestination++ = *rbeginSource;

        rbeginSource--;
    }
    return beginDestination;
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);


    word->begin = findSpaceReverse(word->end, rend);

    if (word->end <= word->begin || (*rend == '\0' && *rbegin == '\0'))
        return 0;

    return 1;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    return strcmp(w1.begin, w2.begin);
}

void getBagOfWords(BagOfWords *bag, char *s) {
    char *beginSearch = s;
    bag->size = 0;
    WordDescriptor w;

    while (getWord(beginSearch, &w)) {
        beginSearch = w.end;
        bag->words[bag->size] = w;
        bag->size++;
    }

}

//void digitToStart(WordDescriptor word) {
//    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
//    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
//    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
//}