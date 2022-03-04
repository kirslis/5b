//
// Created by HP on 27.02.2022.
//

#ifndef COURSE_STRING__H
#define COURSE_STRING__H

#include "stdint.h"
#include "stdbool.h"

#define MAX_N_WORDS_IN_STRING 20


#define ASSERT_STRING(expected, got) assertString (expected, got , \
 __FILE__ , __FUNCTION__ , __LINE__ )

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

static BagOfWords _bag1;
static BagOfWords _bag2;

bool getWord(char *beginSearch, WordDescriptor *word);

size_t strlen_(char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString(char *s);

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

void getBagOfWords(BagOfWords *bag, char *s);

void wordDescriptionToString(WordDescriptor word, char *destination);

bool areWordsSame(WordDescriptor w1, WordDescriptor w2);

bool isContained(WordDescriptor w, char *s);

#endif