//
// Created by HP on 02.02.2022.
//
#include "vector.h"
#include "stdio.h"
#include "malloc.h"
#include "stdbool.h"

void isCorrectVector(vector v) {
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vector createVector(size_t n) {
    vector v;
    if (n) {
        v = (vector) {malloc(sizeof(int) * n), 0, n};
        isCorrectVector(v);
    } else
        v = (vector) {NULL, 0, n};

    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = (int *) realloc(v->data, newCapacity);
        v->capacity = newCapacity;
        v->data = NULL;
    } else {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        v->capacity = newCapacity;
        isCorrectVector(*v);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    clear(v);
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->size == v->capacity) {
        if (v->capacity != 0)
            reserve(v, v->capacity * 2);
        else
            reserve(v, 1);
    }

    v->data[v->size] = x;
    v->size += 1;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "empty vector");
        exit(1);
    }
    realloc(v->data, v->size - 1);
    v->size -= 1;
}