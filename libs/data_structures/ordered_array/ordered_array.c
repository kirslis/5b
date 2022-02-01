#include "ordered_array.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;
    for (int i = 0; i < set1.size; ++i) {
        if (set1.data[i] != set2.data[i])
            return false;
    }
    return true;
}

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    if (subset.size > set.size)
        return false;
    for (int i = 0; i < subset.size; ++i) {
        if (ordered_array_set_in(&set, subset.data[i]) == set.size)
            return false;
    }
    return true;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

//возвращает максимальный индекс элемента массива a размера n не меньше value
int closestRightIndex(const int *a, const int n, const int value) {
    int left = -1;
    int right = n - 1;
    while (right - left > 1) {
        int middle = left + (right - left) / 2;
        if (a[middle] < value)
            left = middle;
        else
            right = middle;
    }
    if (a[right] < value)
        right += 1;
    return right;
}

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    size_t insertIndex = 0;
    if (set->size != 0)
        insertIndex = binarySearchMoreOrEqual_(set->data, set->size, value);
    if (set->data[insertIndex] != value)
        insert_(set->data, &set->size, insertIndex, value);
}

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    if (set->size != 0) {
        size_t deleteIndex = ordered_array_set_in(set, value);
        if (set->data[deleteIndex] == value)
            deleteByPosSaveOrder_(set->data, &set->size, deleteIndex - 1);
    }
}

// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; ++i) {
        ordered_array_set_insert(&set, set1.data[i]);
    }

    for (int i = 0; i < set2.size; ++i) {
        if (ordered_array_set_in(&set1, set2.data[i]) == set1.size) {
            ordered_array_set_insert(&set, set2.data[i]);
        }
    }
    return set;
}

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size);
    for (int i = 0; i < set1.size; ++i) {
        if (ordered_array_set_in(&set2, set1.data[i]) != set2.size)
            ordered_array_set_insert(&set, set1.data[i]);
    }
    return set;
}

// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size);
    for (int i = 0; i < set1.size; ++i) {
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size)
            ordered_array_set_insert(&set, set1.data[i]);
    }
    return set;
}

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_union(ordered_array_set_difference(set1, set2),
                                                    ordered_array_set_difference(set2, set1));
    return set;
}

// возвращает дополнение до универсума universumSet множества set
ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    return ordered_array_set_difference(universumSet, set);
}

// вывод множества set
void ordered_array_set_print(ordered_array_set set) {
    if (set.size == 0)
        printf("{}");
    else {
        printf("{");
        for (int i = 0; i < set.size; ++i) {
            printf("%d, ", set.data[i]);
        }
        printf("\b\b}");
    }
}

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}

// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (int i = 0; i < size; ++i) {
        ordered_array_set_insert(&set, a[i]);
    }
    return set;
}
