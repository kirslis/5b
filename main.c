#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>
#include "libs/data_structures/vectorVoid/vectorVoid.h"
#include "string.h"

void test_pushBack_emptyVectorVoid() {
    vectorVoid v = createVectorV(10, sizeof(int));

    int x = 1;
    pushBackV(&v, &x);

    vectorVoid v2 = createVectorV(1, sizeof(int));

    char *destination = (char *) v2.data;
    memcpy(destination, &x, v2.baseTypeSize);
    v2.size = 1;

    assert (isEqualVectorsV(&v, &v2));

    deleteVectorV(&v);
    deleteVectorV(&v2);
}

void test_pushBack_fullVectorVoid() {
    vectorVoid v = createVectorV(5, sizeof(int));

    for (int i = 0; i < 5; ++i) {
        int x = i;
        char *destination = (char *) v.data + i * v.baseTypeSize;
        memcpy(destination, &x, v.baseTypeSize);
    }
    v.size = 5;

    int b = 5;
    pushBackV(&v, &b);

    vectorVoid v2 = createVectorV(6, sizeof(int));
    for (int i = 0; i < 6; ++i) {
        int x = i;
        char *destination = (char *) v2.data + i * v2.baseTypeSize;
        memcpy(destination, &x, v2.baseTypeSize);
    }
    v2.size = 6;

    assert (isEqualVectorsV(&v, &v2));

    deleteVectorV(&v);
    deleteVectorV(&v2);
}

void test_pushBack_zeroVectorVoid() {
    vectorVoid v = createVectorV(1, sizeof(int));

    int x = 1;
    pushBackV(&v, &x);

    vectorVoid v2 = createVectorV(1, sizeof(int));

    char *destination = (char *) v2.data;
    memcpy(destination, &x, v2.baseTypeSize);
    v2.size = 1;

    assert(isEqualVectorsV(&v, &v2));

    deleteVectorV(&v);
    deleteVectorV(&v2);
}

void test_popBack_notEmptyVectorVoid() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int x = 10;
    pushBackV(&v, &x);

    assert (v.size == 1);
    popBackV(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);

    deleteVectorV(&v);
}

void test_getVectorValueV_notEmptyVector() {
    vectorVoid v = createVectorV(5, sizeof(int));

    for (int i = 0; i < 5; ++i) {
        int x = i;
        pushBackV(&v, &x);
    }
    v.size = 5;

    int value;
    getVectorValueV(&v, 0, &value);

    int rightValue;
    memcpy(&rightValue, v.data, v.baseTypeSize);

    assert(value == rightValue);

    deleteVectorV(&v);
}

void test_getVectorValueV_requestToLastElement() {
    vectorVoid v = createVectorV(5, sizeof(int));

    for (int i = 0; i < 5; ++i) {
        int x = i;
        pushBackV(&v, &x);
    }
    v.size = 5;

    int value;
    getVectorValueV(&v, 4, &value);

    int rightValue;
    memcpy(&rightValue, v.data + 4 * v.baseTypeSize, v.baseTypeSize);

    assert(value == rightValue);

    deleteVectorV(&v);
}

void test() {
    test_pushBack_emptyVectorVoid();
    test_pushBack_fullVectorVoid();
    test_pushBack_zeroVectorVoid();
    test_popBack_notEmptyVectorVoid();
    test_getVectorValueV_notEmptyVector();
    test_getVectorValueV_requestToLastElement();
}

int main() {
    test();

    return 0;
}
