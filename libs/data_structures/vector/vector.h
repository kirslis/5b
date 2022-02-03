//
// Created by HP on 02.02.2022.
//

#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include "stdio.h"
#include "malloc.h"

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

void isCorrectVector(vector v);

//создает структуру vector, с capacity равной n
vector createVector(size_t n);

//изменяет вместимость структуры vector на newCapacity
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из вектора, но не освобождает выделеннную память
void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

#endif //COURSE_VECTOR_H
