//
// Created by HP on 27.02.2022.
//

#ifndef COURSE_STRING__H
#define COURSE_STRING__H

#include "stdint.h"
#include "stdbool.h"



#define ASSERT_STRING(expected, got) assertString (expected, got , \
 __FILE__ , __FUNCTION__ , __LINE__ )

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;


bool getWord(char *beginSearch, WordDescriptor *word);

size_t strlen_(char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString(char *s);

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

#endif