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

void testCreateVector(const int dimension, double elements[]) {
    char *testTitles[] = { "Elements are correct", "Dimension is correct" };

    Vector v = createVector(dimension, elements);

    const bool testResults[] = {
        arraysAreEqual(dimension, elements, v.elements),
        v.dimension == dimension
    };

    printTest("createVector", 2, testTitles, testResults);
    freeVector(v);
}

void testVectorsAreEqual(const Vector firstVector, const Vector secondVector, const bool equals) {
    char *testTitles[] = { "Vectors are equal" };

    const bool testResults[] = {
        vectorsAreEqual(firstVector, secondVector) == equals
    };

    printTest("vectorsAreEqual", 1, testTitles, testResults);
    freeVector(firstVector);
    freeVector(secondVector);
}

void testCopyVector(const Vector vector) {
    char *testTitles[] = { "Vectors are equal" };

    const Vector copiedVector = copyVector(vector);
    const bool testResults[] = {
        vectorsAreEqual(vector, copiedVector)
    };

    printTest("copyVector", 1, testTitles, testResults);
    freeVector(copiedVector);
}

void testTranslateVector(const Vector vector, const Vector translation, const Vector result) {
    char *testTitles[] = { "Vectors are equal" };

    const bool testResults[] = {
        vectorsAreEqual(
            translateVector(vector, translation),
            result)
    };

    printTest("translateVector", 1, testTitles, testResults);
}

void runVectorTests() {
    testCreateVector(4, (double[]){1.0, 4.1, 3.0, 4.0});
    testCreateVector(3, (double[]){1.0, 2.0, 3.0});
    testCreateVector(2, (double[]){1.0, 2.0});
    testCreateVector(1, (double[]){0.0});
    testCreateVector(0, (double[]){});

    testVectorsAreEqual(
        createVector(2, (double[]){0.0, 0.0}),
        createVector(2, (double[]){0.0, 0.0}),
        true);
    testVectorsAreEqual(
        createVector(3, (double[]){0.0, 0.0, 0.0}),
        createVector(2, (double[]){0.0, 0.0}),
        false);
    testVectorsAreEqual(
        createVector(3, (double[]){0.0, 0.0, 0.0}),
        createVector(3, (double[]){0.0, 0.0, 1.0}),
        false);

    testCopyVector(createVector(0, (double[]){}));
    testCopyVector(createVector(1, (double[]){0.0}));
    testCopyVector(createVector(2, (double[]){0.0, 0.0}));

    testTranslateVector(
        createVector(2, (double[]){0.0, 0.0}),
        createVector(2, (double[]){0.0, 0.0}),
        createVector(2, (double[]){0.0, 0.0}));

    testTranslateVector(
        createVector(3, (double[]){0.0, 0.0, 0.0}),
        createVector(1, (double[]){1.0}),
        createVector(3, (double[]){1.0, 1.0, 1.0}));

    testTranslateVector(
        createVector(3, (double[]){0.0, 0.0, 0.0}),
        createVector(5, (double[]){1.0, 1.0, 1.0, 1.0, 1.0}),
        createVector(3, (double[]){1.0, 1.0, 1.0}));
}
