#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "libs/algorithms/algorithm.h"
#include "memory.h"

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode \
        clock_t end_time = clock(); \
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
    }

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64]; // имя сортировки,
    // используемое при выводе
} SortFunc;

typedef struct SortFuncCountOperations {
    long long (*sort )(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64]; // имя сортировки,
    // используемое при выводе
} SortFuncCountOperations;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64]; // имя генератора,
    // используемое при выводе
} GeneratingFunc;

bool isOrdered(const int *a, size_t n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1])
            return 0;
    }

    return 1;
}

void outputArray_(int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu|", runCounter++);
    printf("Name: %s\n", experimentName);

    // замер времени
    double time;

    TIME_TEST({ sortFunc(innerBuffer, size); }, time);

    // результаты замера
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3fs.\n", time);

        // запись в файл
        char filename[256];
        sprintf(filename, "C:\\Users\\HP\\Desktop\\progi\\main\\cmake-build-debug\\data\\%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError%s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf(" Wrong !\n");


        // вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}

void checkOperations(long long (*SortFuncCountOperations )(int *, size_t),
                     void (*generateFunc )(int *, size_t),
                     size_t size, char *experimentName) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu|", runCounter++);
    printf("Name: %s\n", experimentName);

    // замер времени
    long long nComps = 0;

    nComps = SortFuncCountOperations(innerBuffer, size);

    // результаты замера
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Operations: %lld\n", nComps);

        // запись в файл
        char filename[256];
        sprintf(filename, "C:\\Users\\HP\\Desktop\\progi\\main\\cmake-build-debug\\data\\%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError%s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, nComps);
        fclose(f);
    } else {
        printf(" Wrong !\n");


        // вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}

long long selectionSortNComps(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < n; ++i) {
        size_t minIndex = i;

        for (int j = i + 1; ++nComps && j < n; ++j)
            if (a[j] < a[minIndex])
                minIndex = j;
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex], sizeof(int));
    }
    return nComps;
}

void selectionSort(int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        size_t minIndex = i;

        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minIndex])
                minIndex = j;
        if (i != minIndex)
            swap(&a[i], &a[minIndex], sizeof(int));
    }
}

long long insertionSortNComps(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 1; ++nComps && i < n; ++i) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && t < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
    return nComps;
}

void insertionSort(int *a, size_t n) {
    for (int i = 1; i < n; ++i) {
        int t = a[i];
        int j = i;
        while (j > 0 && t < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

long long bubbleSortNComps(int *a, size_t n) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < n; ++i) {
        for (int j = 0; ++nComps && j < n - 1; ++j)
            if (++nComps && a[j] > a[j + 1])
                swap(&a[j], &a[j + 1], sizeof(int));
    }
    return nComps;
}

void bubbleSort(int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1], sizeof(int));
    }
}

long long combsortNComps(int *a, const size_t size) {
    long long nComps = 0;
    size_t step = size;
    int swapped = 1;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; ++nComps && j < size; ++i, ++j)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j], sizeof(int));
                swapped = 1;
            }
    }
    return nComps;
}

void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j], sizeof(int));
                swapped = 1;
            }
    }
}

long long shellSortNComps(int *a, size_t n) {
    long long nComps = 0;
    for (int i = n / 2; ++nComps && i > 0; i /= 2)
        for (int j = i; ++nComps && j < n; ++j)
            for (int k = j - i; ++nComps && k >= 0 && a[k] > a[k + i]; k -= i) {
                int t = a[k];
                a[k] = a[k + i];
                a[k + i] = t;
            }
    return nComps;
}

void shellSort(int *a, size_t n) {
    for (int i = n / 2; i > 0; i /= 2)
        for (int j = i; j < n; ++j)
            for (int k = j - i; k >= 0 && a[k] > a[k + i]; k -= i) {
                int t = a[k];
                a[k] = a[k + i];
                a[k + i] = t;
            }
}

typedef struct number {
    int number;
    int key;
} number;

#define BITS_TEP 8
#define NUMBER_STEP 255


long long digitSortNComps(int *a, size_t n) {
    long long nComps = 0;
    number numbers[n];
    size_t countKeys[NUMBER_STEP + 1];
    for (int i = 0; ++nComps && i < NUMBER_STEP + 1; ++i)
        countKeys[i] = 0;

    for (int i = 0; ++nComps && i < sizeof(int) * 8; i += BITS_TEP) {
        int scanBits = NUMBER_STEP;
        for (int j = 0; ++nComps && j < n; ++j) {
            int key = (a[j] >> i) & scanBits;
            numbers[j].number = a[j];
            numbers[j].key = key;
            countKeys[key]++;
        }

        size_t keyIndex[NUMBER_STEP + 1];
        keyIndex[0] = 0;

        for (int j = 1; ++nComps && j < NUMBER_STEP + 1; ++j)
            keyIndex[j] = keyIndex[j - 1] + countKeys[j - 1];

        for (int j = 0; ++nComps && j < n; ++j) {
            size_t iWrite = keyIndex[numbers[j].key]++;
            a[iWrite] = numbers[j].number;
        }

        for (int j = 0; ++nComps && j < NUMBER_STEP + 1; ++j)
            countKeys[j] = 0;
    }
    return nComps;
}

void digitSort(int *a, size_t n) {
    number numbers[n];
    size_t countKeys[NUMBER_STEP + 1];
    for (int i = 0; i < NUMBER_STEP + 1; ++i)
        countKeys[i] = 0;

    for (int i = 0; i < sizeof(int) * 8; i += BITS_TEP) {
        int scanBits = NUMBER_STEP;
        for (int j = 0; j < n; ++j) {
            int key = (a[j] >> i) & scanBits;
            numbers[j].number = a[j];
            numbers[j].key = key;
            countKeys[key]++;
        }

        size_t keyIndex[NUMBER_STEP + 1];
        keyIndex[0] = 0;

        for (int j = 1; j < NUMBER_STEP + 1; ++j)
            keyIndex[j] = keyIndex[j - 1] + countKeys[j - 1];

        for (int j = 0; j < n; ++j) {
            size_t iWrite = keyIndex[numbers[j].key]++;
            a[iWrite] = numbers[j].number;
        }
//        outputArray_(a, n);

        for (int j = 0; j < NUMBER_STEP + 1; ++j)
            countKeys[j] = 0;
    }
}


void generateRandomArray(int *a, size_t n) {
    srand(time(0));
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 100000;
}

void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; ++i)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t n) {
    for (int i = 0; i < n; ++i)
        a[i] = n - i;
}

void mergeNComps(const int *a, const int n,
                 const int *b, const int m, int *c, long long *nComps) {
    int i = 0, j = 0;
    while (++*nComps && i < n || j < m)
        if (++*nComps && j == m || i < n && a[i] < b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
}

void merge(const int *a, const int n,
           const int *b, const int m, int *c) {
    int i = 0, j = 0;
    while (i < n || j < m)
        if (j == m || i < n && a[i] < b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
}

void mergeSortNComps_(int *source, int l, int r, int *buffer, long long *nComps) {
    int n = r - l;
    if (++*nComps && n <= 1)
        return;

    int m = (l + r) / 2;
    mergeSortNComps_(source, l, m, buffer, nComps);
    mergeSortNComps_(source, m, r, buffer, nComps);

    mergeNComps(source + l, m - l, source + m, r - m, buffer, nComps);
    memcpy(source + l, buffer, sizeof(int) * n);
}

void mergeSort_(int *source, int l, int r, int *buffer) {
    int n = r - l;
    if (n <= 1)
        return;

    // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    int m = (l + r) / 2;
    mergeSort_(source, l, m, buffer);
    mergeSort_(source, m, r, buffer);

    // производим слияние элементов, результат сохраняем в буфере
    merge(source + l, m - l, source + m, r - m, buffer);
    // переписываем сформированную последовательность с буфера
    // в исходный массив
    memcpy(source + l, buffer, sizeof(int) * n);
}

long long mergeSortNComps(int *a, size_t n) {
    long long nComps = 0;
    int *buffer = (int *) malloc(sizeof(int) * n);
    mergeSortNComps_(a, 0, n, buffer, &nComps);
    free(buffer);
    return nComps;
}

void mergeSort(int *a, size_t n) {
    // создаём буфер из которого будут браться элементы массива
    int *buffer = (int *) malloc(sizeof(int) * n);
    mergeSort_(a, 0, n, buffer);
    free(buffer);
}

void insertHeapNComps(int *a, size_t *size, int x, long long *nComps) {
    a[(*size)++] = x;
    size_t childIndex = *size - 1;
    size_t parentIndex = (childIndex - 1) / 2;
    while (++*nComps && a[childIndex] > a[parentIndex] && childIndex != 0) {
        swap(&a[childIndex], &a[parentIndex], sizeof(int));
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

void insertHeap(int *a, size_t *size, int x) {
    a[(*size)++] = x;
    size_t childIndex = *size - 1;
    size_t parentIndex = (childIndex - 1) / 2;
    while (a[childIndex] > a[parentIndex] && childIndex != 0) {
        swap(&a[childIndex], &a[parentIndex], sizeof(int));
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

bool hasLeftChild(size_t parentIndex, size_t size) {
    return 2 * parentIndex + 1 < size;
}

bool hasRightChild(size_t parentIndex, size_t size) {
    return 2 * parentIndex + 2 < size;
}

size_t getLeftChildIndex(size_t parentIndex) {
    return 2 * parentIndex + 1;
}

size_t getMinChildIndexNComps(const int *a, size_t size, size_t parentIndex, long long *nComps) {
    size_t minChildIndex = getLeftChildIndex(parentIndex);
    size_t rightChildIndex = minChildIndex + 1;
    if (++*nComps && hasRightChild(parentIndex, size))
        if (++*nComps && a[rightChildIndex] > a[minChildIndex])
            minChildIndex = rightChildIndex;
    return minChildIndex;
}

size_t getMinChildIndex(const int *a, size_t size, size_t parentIndex) {
    size_t minChildIndex = getLeftChildIndex(parentIndex);
    size_t rightChildIndex = minChildIndex + 1;
    if (hasRightChild(parentIndex, size))
        if (a[rightChildIndex] > a[minChildIndex])
            minChildIndex = rightChildIndex;
    return minChildIndex;
}

void removeMinHeapNComps(int *a, size_t *size, long long *nComps) {
    *size -= 1;
    swap(&a[0], &a[*size], sizeof(int));
    size_t parentIndex = 0;
    while (++*nComps && hasLeftChild(parentIndex, *size)) {
        size_t minChildIndex = getMinChildIndexNComps(a, *size, parentIndex, nComps);
        if (++*nComps && a[minChildIndex] > a[parentIndex]) {
            swap(&a[minChildIndex], &a[parentIndex], sizeof(int));
            parentIndex = minChildIndex;
        } else
            break;
    }
}

void removeMinHeap(int *a, size_t *size) {
    *size -= 1;
    swap(&a[0], &a[*size], sizeof(int));
    size_t parentIndex = 0;
    while (hasLeftChild(parentIndex, *size)) {
        size_t minChildIndex = getMinChildIndex(a, *size, parentIndex);
        if (a[minChildIndex] > a[parentIndex]) {
            swap(&a[minChildIndex], &a[parentIndex], sizeof(int));
            parentIndex = minChildIndex;
        } else
            break;
    }
}

long long heapSortNComps(int *a, size_t size) {
    long long nComps = 0;
    size_t heapSize = 0;
    while (++nComps && heapSize != size)
        insertHeapNComps(a, &heapSize, a[heapSize], &nComps);
    while (++nComps && heapSize)
        removeMinHeapNComps(a, &heapSize, &nComps);
    return nComps;
}

void heapSort(int *a, size_t size) {
    size_t heapSize = 0;
    while (heapSize != size)
        insertHeap(a, &heapSize, a[heapSize]);
    while (heapSize)
        removeMinHeap(a, &heapSize);
}


void timeExperiment() {
    // описание функций сортировки
    SortFuncCountOperations sorts[] = {
            {selectionSortNComps, "selectionSortNComps"},
            {insertionSortNComps, "insertionSort"},
            {bubbleSortNComps,    "bubbleSort"},
            {combsortNComps,      "combsort"},
            {shellSortNComps,     "shellSort"},
            {digitSortNComps,     "digitSort"},
            {mergeSortNComps,     "mergeSort"},
            {heapSortNComps,      "heapSort"},
//            {selectionSort, "selectionSort"},
//            {insertionSort, "insertionSort"},
//            {bubbleSort,    "bubbleSort"},
//            {combsort,      "combsort"},
//            {shellSort,     "shellSort"},
//            {digitSort,     "digitSort"},
//            {mergeSort,     "mergeSort"},
//            {heapSort,      "heapSort"},
            // вы добавите свои сортировки
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      "random"},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     "ordered"},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

 // запись статистики в файлe
        for (size_t size = 10000; size <= 100000; size += 10000) {
            printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
            printf(" Size : %d\n", size);
            for (int i = 0; i < FUNCS_N; i++) {
                for (int j = 0; j < CASES_N; j++) {
                    // генерация имени файла
                    static char filename[128];
                    sprintf(filename, "%s_% s_time",
                            sorts[i].name, generatingFuncs[j].name);
                    checkOperations(sorts[i].sort,
                              generatingFuncs[j].generate,
                              size, filename);
                }
            }
            printf("\n");
        }
}

int main() {
    timeExperiment();
}

