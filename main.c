#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "string.h"


int main() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7,1,2,
                    1,8,1,
                    3, 2,3
            },
            3, 3
    );

    sortRowsByMinElement(m);

    outputMatrix(m);

    return 0;
}