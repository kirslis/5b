#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "string.h"


int main() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,2,3,
                    4,5,6,
                    7, 8,9
            },
            3, 3
    );

    swapMinAndMaxRows(m);

    outputMatrix(m);

    return 0;
}