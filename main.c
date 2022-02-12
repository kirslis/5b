#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "string.h"


int main() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,2,3,
                    2,5,6,
                    3, 6,9
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    outputMatrix(m);

    return 0;
}