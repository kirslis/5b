//
// Created by HP on 27.02.2022.
//

#include <ctype.h>
#include "memory.h"

size_t strlen_(const char *begin) {
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

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin -= 1;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs && *lhs == *rhs)
        lhs++, rhs++;

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination){
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char* copyIf(char *beginSource, const char *endSource,char *beginDestination, int (*f)(int)){
    while (beginSource != endSource) {
        if (f(*beginSource))
            *(beginDestination++) = *beginSource;

        beginSource++;
    }
    return beginDestination;
}