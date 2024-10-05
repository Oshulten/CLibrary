//
// Created by oshul on 10/5/2024.
//

#include "vector.h"

#include <stdarg.h>
#include <stdlib.h>

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
