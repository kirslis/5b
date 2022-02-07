//
// Created by HP on 05.02.2022.
#include "vectorVoid.h"
#include "stdio.h"
#include "malloc.h"
#include "stdbool.h"
#include "string.h"

void memoryErrorV(vectorVoid v) {
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    if (n) {
        v = (vectorVoid) {malloc(baseTypeSize * n), 0, n, baseTypeSize};
        memoryErrorV(v);
    } else
        v = (vectorVoid) {NULL, 0, n, baseTypeSize};

    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = realloc(v->data, newCapacity);
        v->data = NULL;
    } else {
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
        memoryErrorV(*v);
    }

    v->capacity = newCapacity;
    if (v->size > newCapacity)
        v->size = newCapacity;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid *v) {
    if (!isEmptyV(v))
        free(v->data); // ошибка на пустых массивах
    v->data = NULL;

    clearV(v);
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void notCorrectIndexError(vectorVoid *v, size_t index) {
    if (v->size < index) {
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
        exit(1);
    }
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    notCorrectIndexError(v, index);
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    notCorrectIndexError(v, index);
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void pushBackV(vectorVoid *v, int *x) {
    if (isFullV(v)) {
        if (v->capacity != 0)
            reserveV(v, v->capacity * 2);
        else
            reserveV(v, 1);
    }

    setVectorValueV(v, v->size, x);
    v->size += 1;
}

void emptyVectorErrorV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "empty vector");
        exit(1);
    }
}

void popBackV(vectorVoid *v) {
    emptyVectorErrorV(v);

    v->size -= 1;
}

