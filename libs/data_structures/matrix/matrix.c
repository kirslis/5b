//
// Created by HP on 11.02.2022.
//
#include "matrix.h"
#include "malloc.h"
#include "stdio.h"
#include "stdbool.h"
#include "assert.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);

    for (int i = 0; i < nRows; ++i)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    if (!nRows || !nCols)
        values = NULL;
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; ++i)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        free(m.values[i]);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        printf("input row %d:", i + 1);

        for (int j = 0; j < m.nCols; ++j)
            scanf("%d", &m.values[i][j]);
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        printf("input matrix %d:\n", i + 1);
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j)
            printf("%d ", m.values[i][j]);

        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        printf("print matrix %d: ", i + 1);
        printf("\n");

        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *value = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = value;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; ++i) {
        int value = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = value;
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols) {
        for (int i = 0; i < m1.nRows; ++i)
            for (int j = 0; j < m1.nCols; ++j)
                if (m1.values[i][j] != m2.values[i][j])
                    return 0;
        return 1;
    }
    return 0;
}

bool isEMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (i != j && m.values[i][j] != 0)
                return 0;

    return 1;
}

bool isSymmetricMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < i; ++j)
            if (m.values[i][j] != m.values[j][i])
                return 0;

    return 1;
}

void swapMatrixValues(matrix m, int i, int j) {
    int value = m.values[i][j];
    m.values[i][j] = m.values[j][i];
    m.values[j][i] = value;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < i; ++j)
            if (m.values[i][j] != m.values[j][i])
                swapMatrixValues(m, i, j);
}

position getMinValuePos(matrix m) {
    position minValueIndex = {0, 0};
    int minValue = m.values[0][0];

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                minValueIndex = (position) {i, j};
            }

    return minValueIndex;
}

position getMaxValuePos(matrix m) {
    position maxValueIndex = {0, 0};
    int maxValue = m.values[0][0];

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] > maxValue) {
                maxValue = m.values[i][j];
                maxValueIndex = (position) {i, j};
            }

    return maxValueIndex;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

int countZeroRows(matrix m, int nRows, int nCols) {
    int countOfZeroRows = 0;
    for (int i = 0; i < nRows; ++i) {
        int colsIndex = 0;
        bool isZeroLine = 1;
        while (colsIndex < nCols && isZeroLine == 1) {
            isZeroLine = m.values[i][colsIndex] == 0;
            colsIndex += 1;
        }
        countOfZeroRows += isZeroLine;
    }
    return countOfZeroRows;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int maxElementRow[m.nRows];

    for (int i = 0; i < m.nRows; ++i) {
        maxElementRow[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 0; i < m.nRows; ++i) {
        int t = maxElementRow[i];
        int j = i;

        while (j > 0 && maxElementRow[j - 1] > t) {
            swapRows(m, j, j - 1);
            maxElementRow[j] = maxElementRow[j - 1];
            j--;
        }

        maxElementRow[j] = t;
    }
}

int getMaxOfRow(int *a, int n) {
    int max = a[0];

    for (int i = 0; i < n; ++i)
        if (a[i] > max)
            max = a[i];

    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMaxOfRow);
}

void swapMinAndMaxRows(matrix m) {
    if (m.nRows != 0) {
        position p1 = getMaxValuePos(m);
        position p2 = getMinValuePos(m);

        swapRows(m, p1.rowIndex, p2.rowIndex);
    }
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix m3 = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            m3.values[i][j] = 0;
        }
    }

    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            for (int k = 0; k < m1.nCols; ++k) {
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int collMinElements[m.nCols];

    for (int i = 0; i < m.nCols; ++i) {
        int colsElems[m.nRows];
        for (int j = 0; j < m.nRows; ++j) {
            colsElems[j] = m.values[j][i];
        }
        collMinElements[i] = criteria(colsElems, m.nRows);
    }

    for (int i = 0; i < m.nRows; ++i) {
        int t = collMinElements[i];
        int j = i;

        while (j > 0 && collMinElements[j - 1] > t) {
            swapColumns(m, j, j - 1);
            collMinElements[j] = collMinElements[j - 1];
            j--;
        }

        collMinElements[j] = t;
    }
}

int getMinOfCol(int *a, int n) {
    int min = a[0];

    for (int i = 0; i < n; ++i)
        if (a[i] < min)
            min = a[i];

    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMinOfCol);
}

long long getSum(const int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];

    return sum;
}

bool isUnique(const long long *a, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] == a[j])
                return 0;

    return 1;
}

void transposeIfSquareMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumArray[m.nRows];

    for (int i = 0; i < m.nRows; ++i)
        sumArray[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sumArray, m.nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.values == NULL || m2.values == NULL)
        return 0;
    return isEMatrix(mulMatrices(m1, m2));
}

int max(const int *a, int b) {
    int max = a[0];
    for (int i = 1; i < b; ++i)
        if (a[i] > max)
            max = a[i];

    return max;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int numberOfPseudoDiagonals = m.nRows + m.nCols - 1;
    int maxValueOfPseudoDiagonal[numberOfPseudoDiagonals];

    for (int i = 1; i < m.nRows; ++i) {
        int colIndex = 0;
        int rowIndex = i;
        int a[m.nCols];
        int j = 0;

        while (colIndex < m.nCols && rowIndex < m.nRows) {
            a[j] = m.values[rowIndex][colIndex];
            rowIndex++;
            colIndex++;
            j++;
        }
        maxValueOfPseudoDiagonal[i - 1] = max(a, j);
    }

    for (int i = 1; i < m.nCols; ++i) {
        int colIndex = i;
        int rowIndex = 0;
        int a[m.nRows];
        int j = 0;

        while (colIndex < m.nCols && rowIndex < m.nRows) {
            a[j] = m.values[rowIndex][colIndex];
            rowIndex++;
            colIndex++;
            j++;
        }
        maxValueOfPseudoDiagonal[m.nRows + i - 1] = max(a, j);
    }

    return getSum(maxValueOfPseudoDiagonal, numberOfPseudoDiagonals);
}

int getMin(const int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i)
        if (a[i] < min)
            min = a[i];

    return min;
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);

    int maxRowIndexForColl[m.nCols];

    for (int i = 0; i < maxPos.colIndex; ++i) {
        maxRowIndexForColl[i] = i + 1;
    }
    for (int i = maxPos.colIndex; i < m.nCols; ++i) {
        maxRowIndexForColl[i] = maxPos.rowIndex - (i - maxPos.colIndex) + 1;
    }

    int valuesInArea[m.nCols * m.nRows];
    int countOfValuesInArea = 0;

    for (int iCol = 0; iCol < m.nCols; ++iCol) {
        int iRow = 0;
        while (iRow < maxRowIndexForColl[iCol]) {
            valuesInArea[countOfValuesInArea] = m.values[iRow][iCol];
            iRow++;
            countOfValuesInArea++;
        }
    }

    return getMin(valuesInArea, countOfValuesInArea);
}