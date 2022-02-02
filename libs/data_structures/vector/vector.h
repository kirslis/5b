//
// Created by HP on 02.02.2022.
//

#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include "stdio.h"
#include "malloc.h"

typedef struct vector{
    int *data;
    size_t size;
    size_t capacity;
} vector;

//создает структуру vector,
vector createVector(size_t n);



#endif //COURSE_VECTOR_H
