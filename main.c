#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(10);

    pushBack(&v, 1);
    assert (v.size == 1 && v.data[v.size - 1] == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < 5; ++i) {
        v.data[i] = i;
    }
    v.size = 5;

    pushBack(&v, 1);
    assert (v.size == 6 && v.data[v.size - 1] == 1);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}


void test() {
    test_pushBack_fullVector();
    test_pushBack_emptyVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();
}
