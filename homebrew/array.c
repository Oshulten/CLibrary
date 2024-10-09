//
// Created by oshul on 10/7/2024.
//

#include "array.h"

#include <stdio.h>
#include <stdlib.h>

Array createArray() {
    Array array = {
        .data = calloc(ARRAY_INITIAL_SIZE, sizeof(void *)),
        .size = ARRAY_INITIAL_SIZE,
        .count = 0
    };
    return array;
}

void arrayPush(Array array, void *element) {
    if (array.count + 1 > array.size) {
        array.size += ARRAY_REALLOCATION_SIZE;
        void **newData = realloc(array.data, array.size);
        array.data = newData;
    }
    array.count++;
    array.data[array.count] = element;
}
