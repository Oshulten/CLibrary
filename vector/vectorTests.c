//
// Created by oshul on 10/5/2024.
//

#include "vector.h"
#include "vectorTests.h"

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

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
