//
// Created by oshul on 10/5/2024.
//

#include "vector.h"
#include "vectorTests.h"

#include <float.h>
#include <stdio.h>
#include <tgmath.h>

bool almostEqual(const double value, const double comparisonValue, const double epsilon) {
    return fabs(value - comparisonValue) <= epsilon;
}

bool arraysAreEqual(const int count, const double array[count], const double comparison[count]) {
    for (int i = 0; i < count; i++) {
        if (!(almostEqual(array[i], comparison[i], DBL_MIN)))
            return false;
    }
    return true;
}

void runTest(char *testTitle, const int testCount, const char* testTitles[], const bool testResults[]) {
    printf("Test: %s\n", testTitle);
    int passingTests = 0;
    for (int i = 0; i < testCount; i++) {
        printf("\t%s: %s\n", testTitles[i], testResults[i] ? "Pass" : "Fail");
        passingTests += testResults[i];
    }
    printf("Result: %d/%d", passingTests, testCount);
}

void shouldCreateVectorWithCorrectElementsAndDimension(const int dimension, const double elements[]) {
    char *testTitles[] = { "Elements are correct", "Dimension is correct" };

    Vector v = createVector(dimension, elements);
    printVector(v);
    bool testResults[] = {
        arraysAreEqual(3, elements, v.elements),
        v.dimension == dimension
    };

    runTest("Should create vector with correct elements and dimension", 2, testTitles, testResults);

    freeVector(v);
}

void runVectorTests() {
    shouldCreateVectorWithCorrectElementsAndDimension(4, (double[4]){1.0f, 2.0f, 3.0f, 4.0f});
}
