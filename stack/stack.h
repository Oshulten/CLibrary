//
// Created by oshul on 10/7/2024.
//

#ifndef STACK_H
#define STACK_H

#define STACK_INITIAL_SIZE 10
#define STACK_REALLOCATION_SIZE 5
#include <stddef.h>

typedef struct {
    void **data;
    size_t size;
    size_t count;
} Stack;

Stack createStack();
void stackPush(Stack stack, void *element);
void printStack(Stack stack);


#endif //STACK_H
