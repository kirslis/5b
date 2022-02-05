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
        v->size = newCapacity;
        v->data = NULL;
    } else {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        v->capacity = newCapacity;
        if (v->size > newCapacity)
            v->size = newCapacity;
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
    if (!isEmpty(v))
        free(v->data); // ошибка на пустых массивах
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

int *atVector(vector *v, size_t index) {
    if (v->size <= index) {
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
    } else
        return (int *) &v->data[index];
}

int *back(vector *v) {
    if (isEmpty(v))
        fprintf(stderr, "No elements exist");
    else
        return &v->data[v->size - 1];
}

int *front(vector *v) {
    if (isEmpty(v))
        fprintf(stderr, "No elements exist");
    else
        return &v->data[0];
}

bool isEqualVectors(vector *v1, vector *v2) {
    if (v1->size == v2->size) {
        for (int i = 0; i < v1->size; ++i) {
            if (v1->data[i] != v2->data[i])
                return 0;
        }
        return 1;
    }
    return 0;
}