//
// Created by oshul on 10/9/2024.
//

#include <tgmath.h>

#include "unity.h"

#include <float.h>

#include "homebrew/hsla.h"

bool almostEqual(const double value, const double comparisonValue, const double epsilon) {
    return (fabs(value - comparisonValue)) <= epsilon;
}

bool arraysAreEqual(const int count, const double array[count], const double comparison[count]) {
    for (int i = 0; i < count; i++) {
        if (!(almostEqual(array[i], comparison[i], 0.1E-4)))
            return false;
    }
    return true;
}

void setUp() {
}

void tearDown() {
}

void testHslaToString(void) {
    TEST_ASSERT_EQUAL_STRING("[0.00, 0.00, 0.00, 0.00]", hslaToString((double[]){ 0.0, 0.0, 0.0, 0.0 }));
    TEST_ASSERT_EQUAL_STRING("[255.00, 0.00, 0.00, 0.00]", hslaToString((double[]){ 255.0, 0.0, 0.0, 0.0 }));
    TEST_ASSERT_EQUAL_STRING("[255.00, 110.00, 0.00, 110.00]", hslaToString((double[]){ 255.0, 110.0, 0.0, 110.0 }));
}

void testHslaBlendPairByWeights(void) {
    TEST_ASSERT(arraysAreEqual(
        4,
        (double[]){1.0, 1.0, 1.0, 1.0},
        hslaBlendPairByWeights(
            (double[]){1.0, 1.0, 1.0, 1.0},
            (double[]){0.0, 0.0, 0.0, 0.0},
            (double[]){1.0, 1.0, 1.0, 1.0}
        )
    ));

    TEST_ASSERT(arraysAreEqual(
        4,
        (double[]){0.0, 0.2, 0.8, 1.0},
        hslaBlendPairByWeights(
            (double[]){0.0, 0.2, 0.8, 1.0},
            (double[]){0.0, 0.0, 0.0, 0.0},
            (double[]){1.0, 1.0, 1.0, 1.0}
        )
    ));
}

void testHslaBlendPairByFactor() {
    TEST_ASSERT(arraysAreEqual(
        4,
        (double[]){0.5, 0.5, 0.5, 0.5},
        hslaBlendPairByFactor(
            0.5,
            (double[]){0.0, 0.0, 0.0, 0.0},
            (double[]){1.0, 1.0, 1.0, 1.0}
        )
    ));
}

void testHslaBlend() {
    TEST_ASSERT(arraysAreEqual(
        4,
        (double[]){1.0, 1.0, 1.0, 1.0},
        hslaBlend(
            (double[]){0.0, 1.0/3.0, 2.0/3.0, 1.0},
            LINEAR,
            4,
            (double*[]) {
            (double[]){1.0, 0.0, 0.0, 0.0},
            (double[]){0.0, 1.0, 0.0, 0.0},
            (double[]){0.0, 0.0, 1.0, 0.0},
            (double[]){0.0, 0.0, 0.0, 1.0}
            }
        )
    ));

    TEST_ASSERT(arraysAreEqual(
        4,
        (double[]){1.0, 1.0, 1.0, 0.0},
        hslaBlend(
            (double[]){0.0, 1.0/3.0, 2.0/3.0, 1.0},
            CYCLICAL,
            3,
            (double*[]) {
            (double[]){1.0, 0.0, 0.0, 0.0},
            (double[]){0.0, 1.0, 0.0, 0.0},
            (double[]){0.0, 0.0, 1.0, 0.0},
            }
        )
    ));
}

void testHslaToRgba() {
    TEST_ASSERT(
        arraysAreEqual(
            4,
            (double[]){191.0, 64.0, 64.0, 100.0},
            hslaToRgba((double[]){0.0, 50.0, 50.0, 1.0 })
        )
    );
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testHslaToString);
    RUN_TEST(testHslaBlendPairByWeights);
    RUN_TEST(testHslaBlendPairByFactor);
    RUN_TEST(testHslaBlend);
    // RUN_TEST(testHslaToRgba);
    return UNITY_END();
}
