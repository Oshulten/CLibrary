//
// Created by oshul on 10/7/2024.
//

#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_INITIAL_SIZE 10
#define ARRAY_REALLOCATION_SIZE 5
#include <stddef.h>

typedef struct {
    void **elements;
    size_t memorySize;
    size_t numberOfElements;
} Array;

Array arrayCreate(int initialSize);
char *arrayToString(Array *array, char *(*toString)(void *));
void arrayPush(Array *array, void *element);
void *arrayGet(Array *array, int index);
void arraySet(Array *array, int index, void *element);
void arrayRemove(Array *array, int index);

#endif //ARRAY_H
