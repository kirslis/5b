#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "string.h"


int main() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,7,2,
                    2,5,6,
                    3, 6,9
            },
            3, 3
    );

    sortRowsByMaxElement(m);

    outputMatrix(m);

    return 0;
}