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


void reverseOutoutWordsInString(char *s) {
    getBagOfWords(&_bag1, s);

    for (int i = _bag1.size; i > 0 ; --i) {
        char s[MAX_WORD_SIZE];
        copy(_bag1.words[i - 1].begin, _bag1.words[i - 1].end, s);
        *(s + strlen_(s)) = '\0';
        printf("%s \n", s);
    }
}

#endif //COURSE_REVERSEOUTOUTWORDSINSTRING_H
