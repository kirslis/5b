//
// Created by HP on 02.02.2022.
//
#include "vector.h"
#include "stdio.h"
#include "malloc.h"

vector createVector(size_t n){
    vector v = {malloc(sizeof(int) * n), 0, n};

    if (v.data == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v ;
};