//
// Created by HP on 11.02.2022.
//

#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H
#include "stdbool.h"

typedef struct matrix{
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position{
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

int countZeroRows(matrix m, int nRows, int nCols);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

int getMinCriteriaIndex(const int *matrix, int iStart, int iStop);

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

int getMaxOfRow(int *a, int n);

void swapMinAndMaxRows(matrix m);

void getSquareOfMatrixIfSymmetric(matrix *m);

matrix mulMatrices(matrix m1, matrix m2);

void sortColsByMinElement(matrix m);

void sortRowsByMaxElement(matrix m);

void transposeIfSquareMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

float getDistance(const int *a, int n);

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(const int *, int));

void sortByDistances(matrix m);


#endif //COURSE_MATRIX_H
