//
// Created by oshul on 10/7/2024.
//

#include "array.h"

#include <stdio.h>
#include <stdlib.h>

Array arrayCreate(int initialSize) {
    Array array = {
        .elements = calloc(initialSize, sizeof(void *)),
        .memorySize = initialSize,
        .numberOfElements = 0
    };

    return array;
}

void arrayPush(Array *array, void *element) {
    if (array->numberOfElements + 1 > array->memorySize) {
        array->memorySize += ARRAY_REALLOCATION_SIZE;
        void **newData = realloc(array->elements, array->memorySize*sizeof(void*));

        for (int i = 0; i < array->numberOfElements; i++) {
            newData[i] = array->elements[i];
        }

        array->elements = newData;
    }

    array->elements[array->numberOfElements] = element;
    array->numberOfElements += 1;
}

void *arrayGet(Array *array, int index) {
    if (index >= array->memorySize) {
        return nullptr;
    }

    return array->elements[index];
}

void arraySet(Array *array, int index, void *element) {
    if (index >= array->memorySize) {
        return;
    }

    array->elements[index] = element;
}

void arrayRemove(Array *array, int index) {
    if (index >= array->memorySize) {
        return;
    }

    size_t numberOfNewElements = array->numberOfElements - 1;
    void **newElements = calloc(numberOfNewElements, sizeof(void*));

    for (int i = 0; i < index; i++) {
        newElements[i] = array->elements[i];
    }

    for (int i = index; i < numberOfNewElements; i++) {
        newElements[i] = array->elements[i+1];
    }

    free(array->elements);
    array->elements = newElements;
}



