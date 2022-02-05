#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(10);

    pushBack(&v, 1);

    vector v2 = createVector(1);
    v2.data[0] = 1;
    v2.size = 1;

    assert (isEqualVectors(&v, &v2));

    deleteVector(&v);
    deleteVector(&v2);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < 5; ++i) {
        v.data[i] = i;
    }
    v.size = 5;

    pushBack(&v, 1);

    vector v2 = createVector(6);
    for (int i = 0; i < 5; ++i) {
        v2.data[i] = i;
    }
    v2.data[5] = 1;
    v2.size = 6;

    assert (isEqualVectors(&v, &v2));

    deleteVector(&v);
    deleteVector(&v2);
}

void test_pushBack_zeroVector(){
    vector v = createVector(1);

    pushBack(&v, 1);

    vector v2 = createVector(1);
    v2.data[0] = 1;
    v2.size = 1;

    assert(isEqualVectors(&v, &v2));

    deleteVector(&v);
    deleteVector(&v2);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 0; i < 5; ++i) {
        v.data[i] = i;
    }
    v.size = 5;

    assert(atVector(&v, 0) == &v.data[0]);

    deleteVector(&v);
}

void test_atVector_requestToLastElement(){
    vector v = createVector(5);
    for (int i = 0; i < 5; ++i) {
        v.data[i] = i;
    }
    v.size = 5;

    assert(atVector(&v, 4) == &v.data[4]);

    deleteVector(&v);
}

void test_back_oneElementInVector(){
    vector v = createVector(1);
    v.size = 1;

    assert(back(&v) == &v.data[0]);

    deleteVector(&v);
}

void test_front_oneElementInVector(){
    vector v = createVector(1);
    v.size = 1;

    assert(front(&v) == &v.data[0]);

    deleteVector(&v);
}

void test() {
    test_pushBack_fullVector();
    test_pushBack_emptyVector();
    test_pushBack_zeroVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();
}
