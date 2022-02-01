#include <stdio.h>

void inputArray(int *a, int sizeA) {
    for (int i = 0; i < sizeA; ++i) {
        scanf("%d", a + i);
    }
}

void outputArray(int *a, int sizeA) {
    for (int i = 0; i < sizeA; ++i) {
        printf("%d ", a[i]);
    }
}

//1-й вариант
void uniteArraysFromUnique(const int *a, int sizeA, const int *b, int sizeB, int *c, int *sizeC) {
    for (int i = 0; i < sizeA; ++i) {
        c[i] = a[i];
    }
    *sizeC = sizeA;

    for (int i = 0; i < sizeB; ++i) {
        int isUnique = 1;
        for (int j = 0; j < sizeA; ++j) {
            if (b[i] == c[j])
                isUnique = 0;
        }
        if (isUnique == 1) {
            c[*sizeC] = b[i];
            *sizeC += 1;
        }
    }
}

//2-й вариант
void uniteArraysFromNotUnique(const int *a, int sizeA, const int *b, int sizeB, int *c, int *sizeC) {
    *sizeC = 0;
    for (int i = 0; i < sizeB; ++i) {
        int isUnique = 1;
        for (int j = 0; j < sizeA; ++j) {
            if (b[i] == a[j])
                isUnique = 0;
        }
        if (isUnique == 0) {
            c[*sizeC] = b[i];
            *sizeC += 1;
        }
    }
}

//3-й вариант
void uniteArraysFromUniqueA(const int *a, int sizeA, const int *b, int sizeB, int *c, int *sizeC) {
    *sizeC = 0;
    for (int i = 0; i < sizeA; ++i) {
        int isUnique = 1;
        for (int j = 0; j < sizeB; ++j) {
            if (b[j] == a[i])
                isUnique = 0;
        }
        if (isUnique == 1) {
            c[*sizeC] = a[i];
            *sizeC += 1;
        }
    }
}

//4-й вариант
void simmetricDifference(const int *a, int sizeA, const int *b, int sizeB, int *c, int *sizeC) {
    *sizeC = 0;
    for (int i = 0; i < sizeA; ++i) {
        int isUnique = 1;
        for (int j = 0; j < sizeB; ++j) {
            if (b[j] == a[i])
                isUnique = 0;
        }
        if (isUnique == 1) {
            c[*sizeC] = a[i];
            *sizeC += 1;
        }
    }

    for (int i = 0; i < sizeB; ++i) {
        int isUnique = 1;
        for (int j = 0; j < sizeA; ++j) {
            if (a[j] == b[i])
                isUnique = 0;
        }
        if (isUnique == 1) {
            c[*sizeC] = b[i];
            *sizeC += 1;
        }
    }
}

//5-й вариант
void isContained(const int *a, int sizeA, const int *b, int sizeB) {
    int isContained = 1;
    for (int i = 0; i < sizeA; ++i) {
        int f = 0;
        for (int j = 0; j < sizeB; ++j) {
            if (a[i] == b[j])
                f = 1;
        }
        if (f == 0)
            isContained = 0;
    }

    printf("%d", isContained);
}

//6-й вариант
void isEqual(const int *a, int sizeA, const int *b, int sizeB) {
    int isEqual = 1;
    if (sizeA == sizeB) {
        for (int i = 0; i < sizeA; ++i) {
            int isContained = 0;
            for (int j = 0; j < sizeB; ++j) {
                if (a[i] == b[j])
                    isContained = 1;
            }
            if (isContained == 0)
                isEqual = 0;
        }
    } else
        isEqual = 0;
    printf("%d", isEqual);
}

//7-й вариант
void isUniqueElements(const int *a, int sizeA, const int *b, int sizeB) {
    int isUnique = 1;
    for (int i = 0; i < sizeA; ++i) {
        int isContained = 0;
        for (int j = 0; j < sizeB; ++j) {
            if (a[i] == b[j])
                isContained = 1;
        }
        if (isContained == 1)
            isUnique = 0;
    }
    printf("%d", isUnique);
}
//8-й вариант
void unite(const int *a, int sizeA, const int *b, int sizeB, int *c, int *sizeC) {
    *sizeC = 0;
    int i = 0;
    int j = 0;
    while (i < sizeA || j < sizeB) {
        if (a[i] < b[j] && i < sizeA) {
            if (a[i] != c[*sizeC - 1]) {
                c[*sizeC] = a[i];
                *sizeC += 1;
            }
            i++;
        } else {
            if (b[j] != c[*sizeC - 1]) {
                c[*sizeC] = b[j];
                *sizeC += 1;
            }
            j++;
        }
    }
}

int main() {
    int a[100];
    int b[100];
    int sizeA, sizeB;
    scanf("%d %d", &sizeA, &sizeB);

    inputArray(a, sizeA);

    inputArray(b, sizeB);

    int c[100];
    int sizeC;

    unite(a, sizeA, b, sizeB, c, &sizeC);

    outputArray(c, sizeC);
}
