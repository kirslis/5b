#ifndef INC_BITSET_H
#define INC_BITSET_H

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef struct bitset {
    uint32_t values; // множество
    uint32_t maxValue; // максимальный элемент универсума
} bitset;

bitset bitset_create(unsigned maxValue) {
    assert(maxValue >= 1 && maxValue < 32);
    return (bitset) {0, maxValue};
}

// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitset_in(bitset set, unsigned int value) {
    return (set.values >> value) & 1;
}

// вывод множества set
void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

// добавляет элемент value в множество set
void bitset_insert(bitset *set, unsigned int value) {
    set->values |= (1 << value);
}

// удаляет элемент value из множества set
void bitset_deleteElement(bitset *set, unsigned int value) {
    set->values &= ~((1 << set->maxValue) >> (set->maxValue - value));
}

// возвращает объединение множеств set1 и set2
bitset bitset_union(bitset set1, bitset set2) {
    return (bitset) {set1.values | set2.values, set1.maxValue + set2.maxValue};
}

// возвращает пересечение множеств set1 и set2
bitset bitset_intersection(bitset set1, bitset set2) {
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

// возвращает разность множеств set1 и set2
bitset bitset_difference(bitset set1, bitset set2) {
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

// возвращает симметрическую разность множеств set1 и set2
bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool bitset_isSubset(bitset subset, bitset set) {
    return bitset_isEqual(bitset_intersection(set, subset), subset);
}

// возвращает дополнение до универсума множества set
bitset bitset_complement(bitset set) {
    return (bitset) {~set.values, set.maxValue};
}

#endif