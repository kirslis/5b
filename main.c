#include "libs/string/string_.h"
#include "stdio.h"

int main() {
    char *s1 = "hel lo";
    char s2[10] = "\tHello \t";

    char *ind = findSpaceReverse(&s1[5], &s1[-1]);
    printf("%c", *ind);
    if (*ind == ' ')
        printf("Yes");
    printf("%d %d", '\0', *ind);
}