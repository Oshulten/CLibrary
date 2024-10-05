//
// Created by oshul on 10/5/2024.
//

#include "vector.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector createVector(const int dimension, ...) {
    va_list args;
    va_start(args, dimension);

    const Vector vector = {
        .elements = calloc(dimension, sizeof(double)),
        .dimension = dimension
    };

    for (int i = 0; i < dimension; i++) {
        vector.elements[i] = va_arg(args, double);
    }

    return vector;
}

void printVector(const Vector vector) {
    constexpr int DIGITS_PER_ELEMENT = 8;

    char *printString = calloc(
        vector.dimension * (2 + DIGITS_PER_ELEMENT),
        sizeof(char)
    );

    for (int i = 0; i < vector.dimension; i++) {
        const bool isLast = (i == vector.dimension - 1);

        const auto valueString = (char *) calloc(
            DIGITS_PER_ELEMENT + isLast * 2,
            sizeof(char)
        );

        sprintf(
            valueString,
            isLast ? "%f" : "%f, ",
            vector.elements[i]
        );

        strncat(printString, valueString, DIGITS_PER_ELEMENT + 2);
        free(valueString);
    }

    printf("(%s)\n", printString);

    free(printString);
}

Vector copyVector(const Vector vector) {
    const Vector copy = {
        .elements = calloc(vector.dimension, sizeof(double)),
        .dimension = vector.dimension
    };

    for (int i = 0; i < vector.dimension; i++) {
        copy.elements[i] = vector.elements[i];
    }

    return copy;
}

