//
// Created by oshul on 10/5/2024.
//

#include "vector.h"
#include "vectorTests.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

void printArray(int count, double elements[]) {
    constexpr int DIGITS_PER_ELEMENT = 8;

    char *printString = calloc(
        count * (2 + DIGITS_PER_ELEMENT),
        sizeof(char)
    );

    for (int i = 0; i < count; i++) {
        const bool isLast = (i == count - 1);

        const auto valueString = (char *) calloc(
            DIGITS_PER_ELEMENT + isLast * 2,
            sizeof(char)
        );

        sprintf(
            valueString,
            isLast ? "%f" : "%f, ",
            elements[i]
        );

        strncat(printString, valueString, DIGITS_PER_ELEMENT + 2);
        free(valueString);
    }

    printf("[%s]\n", printString);

    free(printString);
}

bool almostEqual(const double value, const double comparisonValue, const double epsilon) {
    return (fabs(value - comparisonValue)) <= epsilon;
}

bool arraysAreEqual(const int count, const double array[count], const double comparison[count]) {
    for (int i = 0; i < count; i++) {
        if (!(almostEqual(array[i], comparison[i], 0.01)))
            return false;
    }
    return true;
}

void printTest(char *testTitle, const int testCount, const char* testTitles[], const bool testResults[]) {
    printf("Test: %s\n", testTitle);
    int passingTests = 0;
    for (int i = 0; i < testCount; i++) {
        printf("\t%s: %s\n", testTitles[i], testResults[i] ? "Pass" : "Fail");
        passingTests += testResults[i];
    }
    printf("Result: %d/%d\n\n", passingTests, testCount);
}

void shouldCreateVectorWithCorrectElementsAndDimension(const int dimension, double elements[]) {
    char *testTitles[] = { "Elements are correct", "Dimension is correct" };

    Vector v = createVector(dimension, elements);

    const bool testResults[] = {
        arraysAreEqual(dimension, elements, v.elements),
        v.dimension == dimension
    };

    printTest("Should create vector with correct elements and dimension", 2, testTitles, testResults);
    freeVector(v);
}

void runVectorTests() {
    shouldCreateVectorWithCorrectElementsAndDimension(4, (double[]){1.0, 4.1, 3.0, 4.0});
    shouldCreateVectorWithCorrectElementsAndDimension(3, (double[]){1.0, 2.0, 3.0});
    shouldCreateVectorWithCorrectElementsAndDimension(2, (double[]){1.0, 2.0});
    shouldCreateVectorWithCorrectElementsAndDimension(1, (double[]){0.0});
    shouldCreateVectorWithCorrectElementsAndDimension(0, (double[]){});
}
