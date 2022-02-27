//
// Created by HP on 27.02.2022.
//

#ifndef COURSE_STRING__H
#define COURSE_STRING__H

#endif //COURSE_STRING__H
#include "stdint.h"

size_t strlen_(const char *begin);

char *find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);