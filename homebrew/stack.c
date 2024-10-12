//
// Created by oshul on 10/7/2024.
//

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack createStack() {
    Stack stack = {
        .data = calloc(STACK_INITIAL_SIZE, sizeof(void *)),
        .size = STACK_INITIAL_SIZE,
        .count = 0
    };
    return stack;
}

void stackPush(Stack stack, void *element) {
    if (stack.count + 1 > stack.size) {
        stack.size += STACK_REALLOCATION_SIZE;
        void **newData = realloc(stack.data, stack.size);
        stack.data = newData;
    }
    stack.count++;
    stack.data[stack.count] = element;
}

void printStack(Stack stack) {
    for (int i = 0; i < stack.count; i++) {
        printf("%f ", *(double *) stack.data[i]);
    }
}
