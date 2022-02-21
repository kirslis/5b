#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "string.h"

void test_swapRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3
            },
            3, 3
    );

    swapRows(m, 0, 2);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_swapColumns() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    6, 5, 4,
                    9, 8, 7
            },
            3, 3
    );

    swapColumns(m, 0, 2);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_isSquareMatrix_squareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isSquareMatrix_notSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 5,
                    6, 4, 5, 6,
                    7, 7, 8, 9
            },
            3, 4
    );

    assert(isSquareMatrix(m) == 0);

    freeMemMatrix(m);
}

void test_isEMatrix_EMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_notEMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );

    assert(isEMatrix(m) == 0);

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_symmetricalMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 1, 0,
                    3, 0, 1
            },
            3, 3
    );

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_notSymmetricalMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 2,
                    2, 1, 0,
                    3, 0, 1
            },
            3, 3
    );

    assert(isSymmetricMatrix(m) == 0);

    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    2, 5, 8,
                    3, 6, 9
            },
            3, 3
    );

    transposeSquareMatrix(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_swapMinAndMaxRows_differentRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3
            },
            3, 3
    );

    swapMinAndMaxRows(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_swapMinAndMaxRows_sameRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 9,
                    4, 5, 6,
                    7, 8, 3
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 9,
                    4, 5, 6,
                    7, 8, 3
            },
            3, 3
    );

    swapMinAndMaxRows(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_swapMinAndMaxRows_zeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    swapMinAndMaxRows(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortRowsByMaxElement_differentMaxElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1
            },
            3, 3
    );

    sortRowsByMaxElement(m);

    assert(twoMatricesEqual(m1, m));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortRowsByMaxElement_sameMaxElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    8, 1, 2,
                    1, 8, 1,
                    8, 2, 3
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 1, 2,
                    1, 8, 1,
                    8, 2, 3
            },
            3, 3
    );

    sortRowsByMaxElement(m);

    assert(twoMatricesEqual(m1, m));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortRowsByMaxElement_zeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    sortRowsByMaxElement(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortColsByMinElement_sameMinElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3
    );

    sortColsByMinElement(m);

    assert(twoMatricesEqual(m1, m));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortColsByMinElement_differentMinElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 4, 1,
                    8, 5, 2,
                    9, 6, 3
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    2, 5, 8,
                    3, 6, 9
            },
            3, 3
    );

    sortColsByMinElement(m);

    assert(twoMatricesEqual(m1, m));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortColsByMinElement_zeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    sortColsByMinElement(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_getSquareOfMatrixIfSymmetric_symmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 5, 6,
                    3, 6, 9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    14, 30, 42,
                    30, 65, 90,
                    42, 90, 126
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_getSquareOfMatrixIfSymmetric_notSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 4,
                    2, 5, 6,
                    3, 6, 9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 4,
                    2, 5, 6,
                    3, 6, 9
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_getSquareOfMatrixIfSymmetric_zeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_transposeIfSquareMatrixHasNotEqualSumOfRows_noEqualRowsSum() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    2, 5, 8,
                    3, 6, 9
            },
            3, 3
    );

    transposeIfSquareMatrixHasNotEqualSumOfRows(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_transposeIfSquareMatrixHasNotEqualSumOfRows_EqualRowsSum() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 2, 1,
                    7, 8, 9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 2, 1,
                    7, 8, 9
            },
            3, 3
    );

    transposeIfSquareMatrixHasNotEqualSumOfRows(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_transposeIfSquareMatrixHasNotEqualSumOfRows_zeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    transposeIfSquareMatrixHasNotEqualSumOfRows(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_isMutuallyInverseMatrices_inverseMatrices() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_isMutuallyInverseMatrices_notInverseMatrices() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 5, 2,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(m, m1) == 0);

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_isMutuallyInverseMatrices_EMatrices() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_isMutuallyInverseMatrices_zeroMatrices() {
    matrix m = createMatrixFromArray(
            (int[]) {

            },
            0, 0
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {

            },
            0, 0
    );

    assert(isMutuallyInverseMatrices(m, m1) == 0);

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_squareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 5, 2,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 18);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_rectangularMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 5, 2, 6,
                    6, 3, 4, 7,
                    5, -2, -3, 8
            },
            3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 32);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_EMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 0);

    freeMemMatrix(m);
}

void test_findSumOfMaxesOfPseudoDiagonal_emptyMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {

            },
            0, 0
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 0);

    freeMemMatrix(m);
}

void test_getMinInArea_lastElementIsMax() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );

    assert(getMinInArea(m) == 1);

    freeMemMatrix(m);
}

void test_getMinInArea_firstElementIsMax() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 2, 1,
                    4, 5, 6,
                    7, 8, 3
            },
            3, 3
    );

    assert(getMinInArea(m) == 9);

    freeMemMatrix(m);
}

void test_getMinInArea_middleElementIsMax() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    5, 2, 4, 1, 7, 9,
                    1, 9, 6, 2, 7, 4,
                    7, 0, 3, 1, 5, 3,
                    3, 5, 6, 7, 8, 8,
                    11, 12, 20, 14, 2
            },
            5, 6
    );

    assert(getMinInArea(m) == 0);

    freeMemMatrix(m);
}

void test_sortByDistances_positiveCoordinates() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 8, 3,
                    9, 2, 1,
                    4, 5, 6
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    9, 2, 1,
                    7, 8, 3
            },
            3, 3
    );

    sortByDistances(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortByDistances_negativeCoordinates() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -7, -8, -3,
                    -9, -2, -1,
                    -4, -5, -6
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -4, -5, -6,
                    -9, -2, -1,
                    -7, -8, -3
            },
            3, 3
    );

    sortByDistances(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortByDistances_onePoint() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -7, -8, -3,
            },
            1, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -7, -8, -3
            },
            1, 3
    );

    sortByDistances(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortByDistances_oneCoordinate() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -7,
                    -9,
                    -4
            },
            3, 1
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -4,
                    -7,
                    -9,
            },
            3, 1
    );

    sortByDistances(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortByDistances_voidMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    sortByDistances(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_countEqClassesByRowsSum_positiveNums() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 8, 3,
                    9, 2, 1,
                    4, 5, 6
            },
            3, 3
    );

    sortByDistances(m);

    assert(countEqClassesByRowsSum(m) == 3);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_negativeNums() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -7, -8, -3,
                    -9, -2, -1,
                    -4, -5, -6
            },
            3, 3
    );

    sortByDistances(m);

    assert(countEqClassesByRowsSum(m) == 3);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -7, -8, -3
            },
            1, 3
    );

    sortByDistances(m);

    assert(countEqClassesByRowsSum(m) == 1);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -7,
                    -9,
                    -4
            },
            3, 1
    );

    sortByDistances(m);

    assert(countEqClassesByRowsSum(m) == 3);

    freeMemMatrix(m);
}

void test_countEqClassesByRowsSum_zeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    sortByDistances(m);

    assert(countEqClassesByRowsSum(m) == 0);

    freeMemMatrix(m);
}

void test_swapPenultimateRow_positiveElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 8, 3,
                    9, 2, 1,
                    4, 5, 6
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 8, 3,
                    3, 1, 6,
                    4, 5, 6
            },
            3, 3
    );


    swapPenultimateRow(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_swapPenultimateRow_negativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -7, -8, -3,
                    -9, -2, -1,
                    -4, -5, -6
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -7, -8, -3,
                    -7, -9, -4,
                    -4, -5, -6
            },
            3, 3
    );


    swapPenultimateRow(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_swapPenultimateRow_twoMin() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 8, 3,
                    1, 2, 1,
                    4, 5, 6
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 8, 3,
                    7, 1, 4,
                    4, 5, 6
            },
            3, 3
    );


    swapPenultimateRow(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_getNSpecialElement_positiveElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },
            3, 4
    );

    assert(getNSpecialElement(m) == 2);

    freeMemMatrix(m);
}

void test_getNSpecialElement_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4
            },
            1, 4
    );

    assert(getNSpecialElement(m) == 4);

    freeMemMatrix(m);
}

void test_getNSpecialElement_negativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -3, -5, -5, -4,
                    -2, -3, -6, -7,
                    -12, -2, -1, -2
            },
            3, 4
    );

    assert(getNSpecialElement(m) == 8);

    freeMemMatrix(m);
}

void test_getNSpecialElement_zeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    assert(getNSpecialElement(m) == 0);

    freeMemMatrix(m);
}

void test_countNonDescendingRowsMatrices_squareMatrices() {
    matrix *ms = getMemArrayOfMatrices(4, 2, 2);

    ms[0] = createMatrixFromArray((int[]) {
                                          7, 1,
                                          1, 1
                                  },
                                  2, 2
    );

    ms[1] = createMatrixFromArray((int[]) {
                                          1, 6,
                                          2, 2
                                  },
                                  2, 2
    );

    ms[2] = createMatrixFromArray((int[]) {
                                          5, 4,
                                          2, 3
                                  },
                                  2, 2
    );

    ms[3] = createMatrixFromArray((int[]) {
                                          1, 3,
                                          7, 9
                                  },
                                  2, 2
    );

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_rectangularMatrices() {
    matrix *ms = getMemArrayOfMatrices(4, 2, 3);

    ms[0] = createMatrixFromArray((int[]) {
                                          7, 1, 5,
                                          1, 1, 6
                                  },
                                  2, 3
    );

    ms[1] = createMatrixFromArray((int[]) {
                                          1, 6, 7,
                                          2, 2, 2
                                  },
                                  2, 3
    );

    ms[2] = createMatrixFromArray((int[]) {
                                          5, 4, 3,
                                          2, 3, 4
                                  },
                                  2, 3
    );

    ms[3] = createMatrixFromArray((int[]) {
                                          1, 3, 4,
                                          7, 9, 10
                                  },
                                  2, 3
    );

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneRowMatrices() {
    matrix *ms = getMemArrayOfMatrices(4, 1, 3);

    ms[0] = createMatrixFromArray((int[]) {
                                          7, 1, 5
                                  },
                                  1, 3
    );

    ms[1] = createMatrixFromArray((int[]) {
                                          1, 6, 7
                                  },
                                  1, 3
    );

    ms[2] = createMatrixFromArray((int[]) {
                                          5, 4, 3
                                  },
                                  1, 3
    );

    ms[3] = createMatrixFromArray((int[]) {
                                          1, 3, 4
                                  },
                                  1, 3
    );

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneColMatrices() {
    matrix *ms = getMemArrayOfMatrices(4, 3, 1);

    ms[0] = createMatrixFromArray((int[]) {
                                          7,
                                          1,
                                          5
                                  },
                                  3, 1
    );

    ms[1] = createMatrixFromArray((int[]) {
                                          1,
                                          6,
                                          7
                                  },
                                  3, 1
    );

    ms[2] = createMatrixFromArray((int[]) {
                                          5,
                                          4,
                                          3
                                  },
                                  3, 1
    );

    ms[3] = createMatrixFromArray((int[]) {
                                          1,
                                          3,
                                          4
                                  },
                                  3, 1
    );

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_printMatrixWithMaxZeroRows() {
    matrix *ms = getMemArrayOfMatrices(5, 3, 2);

    ms[0] = createMatrixFromArray((int[]) {
                                          0, 1,
                                          1, 0,
                                          0, 0
                                  },
                                  3, 2
    );

    ms[1] = createMatrixFromArray((int[]) {
                                          1, 1,
                                          2, 1,
                                          1, 1
                                  },
                                  3, 2
    );

    ms[2] = createMatrixFromArray((int[]) {
                                          0, 0,
                                          0, 0,
                                          4, 7
                                  },
                                  3, 2
    );

    ms[3] = createMatrixFromArray((int[]) {
                                          0, 0,
                                          0, 1,
                                          0, 0
                                  },
                                  3, 2
    );

    ms[4] = createMatrixFromArray((int[]) {
                                          0, 1,
                                          0, 2,
                                          0, 3
                                  },
                                  3, 2
    );

    assert(countZeroRows(ms[0]) == 1);
    assert(countZeroRows(ms[1]) == 0);
    assert(countZeroRows(ms[2]) == 2);
    assert(countZeroRows(ms[3]) == 2);
    assert(countZeroRows(ms[4]) == 0);

    freeMemMatrices(ms, 4);
}

void test_countZeroRows_squareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    0, 0, 0,
                    1, 6, 3
            },
            3, 3
    );

    assert(countZeroRows(m) == 1);

    freeMemMatrix(m);
}

void test_countZeroRows_rectangularMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 7,
                    0, 0, 0, 0,
                    1, 6, 3, 0
            },
            3, 4
    );

    assert(countZeroRows(m) == 1);

    freeMemMatrix(m);
}

void test_countZeroRows_oneCollMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
                    0,
                    1
            },
            3, 1
    );

    assert(countZeroRows(m) == 1);

    freeMemMatrix(m);
}

void test_countZeroRows_oneRowMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 1
            },
            1, 3
    );

    assert(countZeroRows(m) == 0);

    freeMemMatrix(m);
}

void test_countZeroRows_zeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
            },
            0, 0
    );

    assert(countZeroRows(m) == 0);

    freeMemMatrix(m);
}

void test_getMaxMatrixNorm_positiveMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 8,
                    7, 3, 1
            },
            3, 3
    );

    assert(getMaxMatrixNorm(m) == 8);

    freeMemMatrix(m);
}

void test_getMaxMatrixNorm_negativeMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, -2, -3,
                    -4, -5, -8,
                    -7, -3, -1
            },
            3, 3
    );

    assert(getMaxMatrixNorm(m) == 8);

    freeMemMatrix(m);
}

void test_getMaxMatrixNorm_mixedMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, -2, 3,
                    -4, 5, -8,
                    7, -3, 1
            },
            3, 3
    );

    assert(getMaxMatrixNorm(m) == 8);

    freeMemMatrix(m);
}

void test_getMaxMatrixNorm_oneColMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
                    -4,
                    7
            },
            3, 1
    );

    assert(getMaxMatrixNorm(m) == 7);

    freeMemMatrix(m);
}

void test_getMaxMatrixNorm_oneRowMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,-4,7
            },
            1, 3
    );

    assert(getMaxMatrixNorm(m) == 7);

    freeMemMatrix(m);
}

void test() {
    test_swapRows();

    test_swapColumns();

    test_isSquareMatrix_squareMatrix();
    test_isSquareMatrix_notSquareMatrix();

    test_isEMatrix_EMatrix();
    test_isEMatrix_notEMatrix();

    test_isSymmetricMatrix_symmetricalMatrix();
    test_isSymmetricMatrix_notSymmetricalMatrix();

    test_transposeSquareMatrix();

    test_swapMinAndMaxRows_differentRows();
    test_swapMinAndMaxRows_sameRows();
    test_swapMinAndMaxRows_zeroMatrix();

    test_sortRowsByMaxElement_differentMaxElements();
    test_sortRowsByMaxElement_sameMaxElements();
    test_sortRowsByMaxElement_zeroMatrix();

    test_sortColsByMinElement_sameMinElements();
    test_sortColsByMinElement_differentMinElements();
    test_sortColsByMinElement_zeroMatrix();

    test_getSquareOfMatrixIfSymmetric_symmetricMatrix();
    test_getSquareOfMatrixIfSymmetric_notSymmetricMatrix();
    test_getSquareOfMatrixIfSymmetric_zeroMatrix();

    test_transposeIfSquareMatrixHasNotEqualSumOfRows_noEqualRowsSum();
    test_transposeIfSquareMatrixHasNotEqualSumOfRows_EqualRowsSum();
    test_transposeIfSquareMatrixHasNotEqualSumOfRows_zeroMatrix();

    test_isMutuallyInverseMatrices_inverseMatrices();
    test_isMutuallyInverseMatrices_notInverseMatrices();
    test_isMutuallyInverseMatrices_EMatrices();
    test_isMutuallyInverseMatrices_zeroMatrices();

    test_findSumOfMaxesOfPseudoDiagonal_squareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_rectangularMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_EMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_emptyMatrix();

    test_getMinInArea_lastElementIsMax();
    test_getMinInArea_firstElementIsMax();
    test_getMinInArea_middleElementIsMax();

    test_sortByDistances_positiveCoordinates();
    test_sortByDistances_negativeCoordinates();
    test_sortByDistances_onePoint();
    test_sortByDistances_oneCoordinate();

    test_countEqClassesByRowsSum_positiveNums();
    test_countEqClassesByRowsSum_negativeNums();
    test_countEqClassesByRowsSum_oneRow();
    test_countEqClassesByRowsSum_oneCol();
    test_countEqClassesByRowsSum_zeroMatrix();

    test_swapPenultimateRow_positiveElements();
    test_swapPenultimateRow_negativeElements();
    test_swapPenultimateRow_twoMin();

    test_getNSpecialElement_positiveElements();
    test_getNSpecialElement_oneRow();
    test_getNSpecialElement_negativeElements();
    test_getNSpecialElement_zeroMatrix();

    test_countNonDescendingRowsMatrices_squareMatrices();
    test_countNonDescendingRowsMatrices_rectangularMatrices();
    test_countNonDescendingRowsMatrices_oneRowMatrices();
    test_countNonDescendingRowsMatrices_oneColMatrices();

    test_printMatrixWithMaxZeroRows();

    test_countZeroRows_squareMatrix();
    test_countZeroRows_rectangularMatrix();
    test_countZeroRows_oneCollMatrix();
    test_countZeroRows_oneRowMatrix();
    test_countZeroRows_zeroMatrix();

    test_getMaxMatrixNorm_positiveMatrix();
    test_getMaxMatrixNorm_negativeMatrix();
    test_getMaxMatrixNorm_mixedMatrix();
    test_getMaxMatrixNorm_oneColMatrix();
    test_getMaxMatrixNorm_oneRowMatrix();
}


int main() {
    test();

    return 0;
}