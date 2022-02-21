//
// Created by HP on 11.02.2022.
//
#include "matrix.h"
#include "malloc.h"
#include "stdio.h"
#include "stdbool.h"
#include "assert.h"
#include "math.h"

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

int countZeroRows(matrix m) {
    int countOfZeroRows = 0;
    for (int i = 0; i < m.nRows; ++i) {
        int colsIndex = 0;
        bool isZeroLine = 1;
        while (colsIndex < m.nCols && isZeroLine == 1) {
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
    int numberOfPseudoDiagonals = m.nRows + m.nCols - 2;
    int maxValueOfPseudoDiagonal[numberOfPseudoDiagonals];
    int countOfPseudoDiagonals = 0;

    for (int i = 0; i < m.nCols + m.nRows - 1; ++i) {
        int iRow = m.nRows - 1 > i ? m.nRows - i - 1 : 0;
        int iCol = m.nRows - 1 > i ? 0 : i - m.nRows + 1;

        int pseudoDiagonalElements[m.nRows];
        int countOfElements = 0;

        if (iRow != 0 || iCol != 0) {
            while (iRow < m.nRows && iCol < m.nCols) {
                pseudoDiagonalElements[countOfElements] = m.values[iRow][iCol];
                countOfElements++;
                iRow++;
                iCol++;
            }

            maxValueOfPseudoDiagonal[countOfPseudoDiagonals] = max(pseudoDiagonalElements, countOfElements);
            countOfPseudoDiagonals++;
        }
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

    for (int i = 0; i < maxPos.colIndex; ++i)
        maxRowIndexForColl[i] = maxPos.rowIndex - (maxPos.colIndex - i);

    for (int i = maxPos.colIndex; i < m.nCols; ++i)
        maxRowIndexForColl[i] = maxPos.rowIndex - (i - maxPos.colIndex);

    int valuesInArea[m.nCols * m.nRows];
    int countOfValuesInArea = 0;

    for (int iCol = 0; iCol < m.nCols; ++iCol) {
        int iRow = 0;
        while (iRow <= maxRowIndexForColl[iCol]) {
            valuesInArea[countOfValuesInArea] = m.values[iRow][iCol];
            iRow++;
            countOfValuesInArea++;
        }
    }

    return getMin(valuesInArea, countOfValuesInArea);
}

float getDistance(const int *a, int n) {
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += (long long) a[i] * a[i];
    }

    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(const int *, int)) {
    float criteriaOfElements[m.nRows];

    for (int i = 0; i < m.nRows; ++i)
        criteriaOfElements[i] = criteria(m.values[i], m.nCols);

    for (int i = 0; i < m.nRows; ++i) {
        float t = criteriaOfElements[i];
        int j = i;

        while (j > 0 && criteriaOfElements[j - 1] > t) {
            swapRows(m, j, j - 1);
            criteriaOfElements[j] = criteriaOfElements[j - 1];
            j--;
        }

        criteriaOfElements[j] = t;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

bool isContained(const long long *a, int n, long long num) {
    bool isUnique = 1;
    int i = 0;
    while (isUnique == 1 && i < n) {
        isUnique = a[i] != num;
        i++;
    }
    return isUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long uniqueClasses[m.nRows];
    int countOfClasses = 0;

    for (int i = 0; i < m.nRows; ++i) {
        long long class = getSum(m.values[i], m.nCols);

        if (isContained(uniqueClasses, countOfClasses, class)) {
            uniqueClasses[countOfClasses] = class;
            countOfClasses += 1;
        }
    }

    return countOfClasses;
}

position getLeftMin(matrix m) {
    int minElement = m.values[0][0];
    position minPos = {0, 0};

    for (int i = 0; i < m.nCols; ++i)
        for (int j = 0; j < m.nRows; ++j)
            if (m.values[j][i] < minElement) {
                minElement = m.values[j][i];
                minPos = (position) {j, i};
            }

    return minPos;
}

void swapPenultimateRow(matrix m) {
    position minPos = getLeftMin(m);

    int preLastColElement = m.values[m.nRows - 2][minPos.colIndex];

    for (int i = 0; i < m.nRows; ++i)
        m.values[m.nRows - 2][i] = m.values[i][minPos.colIndex];

    if (minPos.colIndex < minPos.rowIndex)
        m.values[m.nRows - 2][minPos.rowIndex] = preLastColElement;
}

int getNSpecialElement(matrix m) {
    int sumOfCol[m.nCols];

    for (int i = 0; i < m.nCols; ++i) {
        sumOfCol[i] = 0;
    }

    for (int i = 0; i < m.nCols; ++i)
        for (int j = 0; j < m.nRows; ++j)
            sumOfCol[i] += m.values[j][i];

    int nSpecialElement = 0;

    for (int i = 0; i < m.nCols; ++i)
        for (int j = 0; j < m.nRows; ++j)
            nSpecialElement += m.values[j][i] > (sumOfCol[i] - m.values[j][i]);

    return nSpecialElement;
}

bool isNonDescendingSorted(const int *a, int n) {
    for (int i = 0; i < n - 1; ++i)
        if (a[i] > a[i + 1])
            return 0;

    return 1;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return 0;

    return 1;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int countGoodMatrices = 0;

    for (int i = 0; i < nMatrix; ++i) {
        countGoodMatrices += hasAllNonDescendingRows(ms[i]);
    }

    return countGoodMatrices;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int countZeroRowsOfMatrix[nMatrix];
    int maxCountOfZeroRows = 0;

    for (int i = 0; i < nMatrix; ++i) {
        countZeroRowsOfMatrix[i] = countZeroRows(ms[i]);

        if (countZeroRowsOfMatrix[i] > maxCountOfZeroRows)
            maxCountOfZeroRows = countZeroRowsOfMatrix[i];
    }

    for (int i = 0; i < nMatrix; ++i)
        if (countZeroRowsOfMatrix[i] == maxCountOfZeroRows)
            outputMatrix(ms[i]);
}

int getMaxMatrixNorm(matrix m) {
    int maxMatrixNorm = abs(m.values[0][0]);

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (abs(m.values[i][j]) > maxMatrixNorm)
                maxMatrixNorm = abs(m.values[i][j]);

    return maxMatrixNorm;
}

void printMinNormMatrix(matrix *ms, int nMatrix) {
    int matrixNorms[nMatrix];

    matrixNorms[0] = getMaxMatrixNorm(ms[0]);
    int minMatrixNorm = matrixNorms[0];

    for (int i = 1; i < nMatrix; ++i) {
        matrixNorms[i] = getMaxMatrixNorm(ms[i]);
        if (matrixNorms[i] < minMatrixNorm)
            minMatrixNorm = matrixNorms[i];
    }

    for (int i = 0; i < nMatrix; ++i)
        if (matrixNorms[i] == minMatrixNorm)
            outputMatrix(ms[i]);
}