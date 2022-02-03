//
// Created by HP on 02.02.2022.
//
#include "vector.h"
#include "stdio.h"
#include "malloc.h"

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
        realloc(v->data, newCapacity);
        v->data = NULL;
    } else {
        realloc(v->data, sizeof(int) * newCapacity);
        isCorrectVector(*v);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    free(v->data);
    v->capacity = v->size = 0;
}