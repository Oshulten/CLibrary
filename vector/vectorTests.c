//
// Created by oshul on 10/5/2024.
//

#include <stdlib.h>

#include "vector.h"
#include "vectorTests.h"

#include <float.h>
#include <stdio.h>

bool almostEqual(const double value, const double comparisonValue, const double epsilon) {
    return abs(value - comparisonValue) <= epsilon;
}

bool arraysAreEqual(int count, double array[count], double comparison[count]) {
    for (int i = 0; i < count; i++) {
        if (!(almostEqual(array[i], comparison[i], DBL_MIN)))
            return false;
    }
    return true;
}

void shouldCreateVectorWithCorrectElementsAndDimension() {
    printf("shouldCreateVectorWithCorrectElementsAndDimension\n");
    char *testTitles[] = { "Elements are correct", "Dimension is correct" };

    Vector v = createVector(3, 1.0, 2.0, 3.0);
    double comparison[] = { 1.0, 2.0, 3.0 };

    bool testResults[] = {
        arraysAreEqual(3, comparison, v.elements),
        v.dimension == 3
    };

    for (int i = 0; i < 2; i++) {
        printf("%s: %s\n", testTitles[i], testResults[i] ? "Pass" : "Fail");
    }

    printVector(v);
}

void runVectorTests() {
    shouldCreateVectorWithCorrectElementsAndDimension();
}
