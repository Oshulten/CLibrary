//
// Created by oshul on 10/7/2024.
//

#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_INITIAL_SIZE 10
#define ARRAY_REALLOCATION_SIZE 5
#include <stddef.h>

typedef struct {
    void **data;
    size_t size;
    size_t count;
} Array;

Array createArray();
void arrayPush(Array stack, void *element);

#endif //ARRAY_H
