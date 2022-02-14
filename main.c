#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "string.h"

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

void  test_swapMinAndMaxRows_zeroMatrix() {
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

void  test_sortRowsByMaxElement_zeroMatrix() {
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

void  test_sortColsByMinElement_zeroMatrix() {
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

void test_getSquareOfMatrixIfSymmetric_symmetricMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,2,3,
                    2,5,6,
                    3, 6,9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    14,	30,	42,
                    30,	65,	90,
                    42,	90,	126
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_getSquareOfMatrixIfSymmetric_notSymmetricMatrix(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,2,4,
                    2,5,6,
                    3, 6,9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,2,4,
                    2,5,6,
                    3, 6,9
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_getSquareOfMatrixIfSymmetric_zeroMatrix(){
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

void test_transposeIfSquareMatrixHasNotEqualSumOfRows_noEqualRowsSum(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,2,3,
                    4,5,6,
                    7, 8,9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,4,7,
                    2,5,8,
                    3, 6,9
            },
            3, 3
    );

    transposeIfSquareMatrixHasNotEqualSumOfRows(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_transposeIfSquareMatrixHasNotEqualSumOfRows_EqualRowsSum(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,2,3,
                    3,2,1,
                    7, 8,9
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,2,3,
                    3,2,1,
                    7, 8,9
            },
            3, 3
    );

    transposeIfSquareMatrixHasNotEqualSumOfRows(m);

    assert(twoMatricesEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_transposeIfSquareMatrixHasNotEqualSumOfRows_zeroMatrix(){
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

void test_isMutuallyInverseMatrices_inverseMatrices(){
    matrix m = createMatrixFromArray(
            (int[]) {
                2, 5, 7,
                6,3,4,
                5,-2,-3
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

void test_isMutuallyInverseMatrices_notInverseMatrices(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 5, 2,
                    6,3,4,
                    5,-2,-3
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

void test_isMutuallyInverseMatrices_EMatrices(){
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,0,0,
                    0,1,0,
                    0,0,1
            },
            3, 3
    );

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,0,0,
                    0,1,0,
                    0,0,1
            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_isMutuallyInverseMatrices_zeroMatrices(){
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

void test() {
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
}



int main() {
    test();

    return 0;
}