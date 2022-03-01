//
// Created by HP on 01.03.2022.
//

#ifndef COURSE_REMOVEEXTRASPACES_H
#define COURSE_REMOVEEXTRASPACES_H

#include "../string_.h"
#include <ctype.h>

void removeExtraSpaces(char *s) {
    char *begin = s;
    char *destination = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || !isspace(last))
            *destination++ = *begin;

        last = *begin++;
    }

    if (last == ' ')
        destination--;

    *destination = '\0';
}

void test_removeExtraSpaces_noSpaces() {
    char s[] = "testWords";
    removeExtraSpaces(s);
    ASSERT_STRING("testWords", s);
}

void test_removeExtraSpaces_spacesBeforeWord() {
    char s[] = "   testWords";
    removeExtraSpaces(s);
    ASSERT_STRING("testWords", s);
}

void test_removeExtraSpaces_spacesBeforeAfterWord() {
    char s[] = "   testWords  ";
    removeExtraSpaces(s);
    ASSERT_STRING("testWords", s);
}

void test_removeExtraSpaces_spacesBetweenBeforeAfterWords() {
    char s[] = "  test   words  ";
    removeExtraSpaces(s);
    ASSERT_STRING("test words", s);
}

void test_removeExtraSpaces_emptyString() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_allSpaces() {
    char s[] = "            ";
    removeExtraSpaces(s);
    ASSERT_STRING("            ", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_spacesBeforeWord();
    test_removeExtraSpaces_spacesBetweenBeforeAfterWords();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_spacesBeforeAfterWord();
    test_removeExtraSpaces_allSpaces();

}


#endif //COURSE_REMOVEEXTRASPACES_H


