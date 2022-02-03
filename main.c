#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(10);
    if (v.data == NULL)
        printf("YES\n");
    reserve(&v, 0);
    if (v.data == NULL)
        printf("YES");

    return 0;
}
