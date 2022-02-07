//
// Created by HP on 05.02.2022.
//

#ifndef COURSE_VECTORVOID_H
#define COURSE_VECTORVOID_H

# include <limits.h>
#include "stdbool.h"

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа
} vectorVoid;

void memoryErrorV(vectorVoid v);

//создает структуру vector, с capacity равной n
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

//изменяет вместимость структуры vector на newCapacity
void reserveV(vectorVoid *v, size_t newCapacity);

//удаляет элементы из вектора, но не освобождает выделеннную память
void clearV(vectorVoid *v);

void shrinkToFitV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

bool isEmptyV(vectorVoid *v);

bool isFullV(vectorVoid *v);

void getVectorValueV(vectorVoid *v, size_t index, void *destination);

void setVectorValueV(vectorVoid *v, size_t index, void *source);

void pushBackV(vectorVoid *v, int *x);

void popBackV(vectorVoid *v);

#endif //COURSE_VECTORVOID_H
