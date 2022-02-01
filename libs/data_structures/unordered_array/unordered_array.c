
#include "unordered_array.h"
# include <assert.h>
# include <stdio.h>
#include <malloc.h>


// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}


// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unordered_array_set_in(unordered_array_set *set, int value) {
    for (int i = 0; i < set->size; ++i) {
        if (set->data[i] == value)
            return i;
    }
    return set->size;
}

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    if (unordered_array_set_in(set, value) == set->size)
        append_(set->data, &set->size, value);
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (int i = 0; i < size; ++i) {
        unordered_array_set_insert(&set, a[i]);
    }
    return set;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    return set1.size == set2.size && unordered_array_set_isSubset(set1, set2);
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t iNeedToDelete = unordered_array_set_in(set, value);
    if (iNeedToDelete < set->size)
        set->data[iNeedToDelete] = set->data[--set->size];
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set unionSet = unordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; ++i)
        unordered_array_set_insert(&unionSet, set1.data[i]);
    for (int i = 0; i < set2.size; ++i)
        unordered_array_set_insert(&unionSet, set2.data[i]);
    return unionSet;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set intersectionSet = unordered_array_set_create(set1.size);
    for (int i = 0; i < set1.size; ++i) {
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
            unordered_array_set_insert(&intersectionSet, set1.data[i]);
    }
    return intersectionSet;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set differenceSet = unordered_array_set_create(set1.size);
    for (int i = 0; i < set1.size; ++i) {
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            unordered_array_set_insert(&differenceSet, set1.data[i]);
    }
    return differenceSet;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set symmetricDifferenceSet = unordered_array_set_union(unordered_array_set_difference(set1, set2),
                                                                           unordered_array_set_difference(set2, set1));
    return symmetricDifferenceSet;
}

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return unordered_array_set_difference(universumSet, set);
}

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    if (subset.size > set.size)
        return false;
    for (int i = 0; i < subset.size; ++i) {
        if (unordered_array_set_in(&set, subset.data[i]) == set.size)
            return false;
    }
    return true;
}

void unordered_array_set_printf(unordered_array_set set) {

    printf("{");
    for (int i = 0; i < set.size; ++i) {
        printf("%d, ", set.data[i]);
    }
    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}");
}