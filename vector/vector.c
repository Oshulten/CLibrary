//
// Created by oshul on 10/5/2024.
//

#include "vector.h"

#include <float.h>
#include <tgmath.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector createVector(const int dimension, double elements[]) {
    for (int i = 0; i < dimension; i++) {
        printf("\n%f", elements[i]);
    }
    const Vector vector = {
        .elements = elements,
        .dimension = dimension
    };

    for (int i = 0; i < dimension; i++) {
        vector.elements[i] = elements[i];
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

void freeVector(const Vector vector) {
    free(vector.elements);
}

// Vector operateOnVectors(const Operation operation, const int count, const Vector vectors[]) {
//     int minVectorDimension = INT_MAX;
//     for (int i = 0; i < count; i++) {
//         minVectorDimension = (vectors[i].dimension < minVectorDimension)
//                                  ? vectors[i].dimension
//                                  : minVectorDimension;
//     }
//
//     const Vector result = {
//         .elements = calloc(minVectorDimension, sizeof(double)),
//         .dimension = minVectorDimension
//     };
//
//     for (int i = 0; i < minVectorDimension; i++) {
//         result.elements[i] = operation;
//         for (int j = 0; j < count; j++) {
//             switch (operation) {
//                 case ADD:
//                     result.elements[i] += vectors[j].elements[i];
//                 break;
//
//                 case MULTIPLY:
//                     result.elements[i] *= vectors[j].elements[i];
//                 break;
//
//                 default:
//                     break;
//             }
//         }
//     }
//
//     return result;
// }
//
// Vector copyVector(const Vector vector) {
//     const Vector copy = {
//         .elements = calloc(vector.dimension, sizeof(double)),
//         .dimension = vector.dimension
//     };
//
//     for (int i = 0; i < vector.dimension; i++) {
//         copy.elements[i] = vector.elements[i];
//     }
//
//     return copy;
// }
//
// Vector translateVector(const Vector vector, const Vector translation) {
//     for (int i = 0; i < vector.dimension; i++) {
//         vector.elements[i] += translation.elements[(int)fmin(i, translation.dimension-1)];
//     }
//     return vector;
// }
//
// Vector dilateVector(const Vector vector, const Vector dilation) {
//     for (int i = 0; i < vector.dimension; i++) {
//         vector.elements[i] *= dilation.elements[(int)fmin(i, dilation.dimension-1)];
//     }
//     return vector;
// }
//
// void vectorDimensionsMinMax(const Vector *vectors, const int count, int *min, int *max) {
//     *min = INT_MAX;
//     *max = 0;
//     for (int i = 0; i < count; i++) {
//         *min = vectors[i].dimension < *min
//                                  ? vectors[i].dimension
//                                  : *min;
//         *max = vectors[i].dimension > *max
//                                  ? vectors[i].dimension
//                                  : *max;
//     }
// }
//
// bool approximateEqual(const double value, const double comparisonValue, const double epsilon) {
//     return fabs(value - comparisonValue) <= epsilon;
// }
//
// bool allEqual(const int count, const int values[]) {
//     for (int i = 1; i < count; i++) {
//         if (values[i] != values[0])
//             return false;
//     }
//     return true;
// }
//
// Vector blendVectorsElementwise(const Vector blendVector, const Vector firstVector, const Vector secondVector) {
//     const Vector vectors[] = { blendVector, firstVector, secondVector };
//
//     int minVectorDimension, maxVectorDimension;
//     vectorDimensionsMinMax(vectors, 3, &minVectorDimension, &maxVectorDimension);
//
//     const Vector result = {
//         .elements = calloc(maxVectorDimension, sizeof(double)),
//         .dimension = maxVectorDimension
//     };
//
//     for (int i = 0; i < maxVectorDimension; i++) {
//         const double blendFactor = blendVector.elements[(int)fmin(i, blendVector.dimension-1)];
//         const double firstValue = firstVector.elements[(int)fmin(i, firstVector.dimension-1)];
//         const double secondValue = secondVector.elements[(int)fmin(i, secondVector.dimension-1)];
//         result.elements[i] = (1.0 - blendFactor)*firstValue + blendFactor*secondValue;
//     }
//
//     return result;
// }
//
// Vector interpolateVectors(const double factor, const InterpolationType interpolationType, int count, Vector inputVectors[]) {
//     va_list args;
//     va_start(args, count);
//
//     Vector vectors[interpolationType == LINEAR ? count : count + 1];
//
//     for (int i = 0; i < count; i++) {
//         vectors[i] = inputVectors[i];
//     }
//
//     if (interpolationType == CYCLICAL) {
//         vectors[count] = vectors[0];
//         count++;
//     }
//
//     va_end(args);
//
//     int minVectorDimension, maxVectorDimension;
//     vectorDimensionsMinMax(vectors, count, &minVectorDimension, &maxVectorDimension);
//
//     const double factorDelta = 1.0 / (count - 1);
//     const double lessThanOneFactor = factor - 0.1E-10;
//     const int lowerIndex = floor(lessThanOneFactor / factorDelta);
//     const double normalizedFactor = (lessThanOneFactor / factorDelta) - lowerIndex;
//
//     const Vector blendVector = {
//         .elements = calloc(1, sizeof(double)),
//         .dimension = 1
//     };
//
//     blendVector.elements[0] = factor;
//
//     return blendVectorsElementwise(blendVector, vectors[lowerIndex], vectors[lowerIndex+1]);
// }
//
