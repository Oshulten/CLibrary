//
// Created by oshul on 10/12/2024.
//

#include "arrayTests.h"
#include "unity.h"
#include "array.h"

void testArrayPush() {
    constexpr int numberOfElementsToPush = 22;

    Array array = arrayCreate(5);

    int values[numberOfElementsToPush];

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < numberOfElementsToPush; i++) {
            switch (j) {
                case 0:
                    values[i] = i;
                    break;
                case 1:
                    arrayPush(&array, &values[i]);
                    break;
                default:
                    TEST_ASSERT_EQUAL(*(int*)array.elements[i], values[i]);
                    break;
            }
        }
    }

    TEST_ASSERT_EQUAL(array.numberOfElements, numberOfElementsToPush);
    TEST_ASSERT_EQUAL(array.memorySize, 25);
}

void testArrayGet() {
    constexpr int numberOfElementsToPush = 22;

    Array array = arrayCreate(5);

    int values[numberOfElementsToPush];

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < numberOfElementsToPush; i++) {
            switch (j) {
                case 0:
                    values[i] = i;
                break;
                case 1:
                    arrayPush(&array, &values[i]);
                break;
                default:
                    TEST_ASSERT_EQUAL(*(int*)arrayGet(&array, i), values[i]);
                break;
            }
        }
    }

    TEST_ASSERT_EQUAL(array.numberOfElements, numberOfElementsToPush);
    TEST_ASSERT_EQUAL(array.memorySize, 25);
}

void runArrayTests() {
    RUN_TEST(testArrayPush);
    RUN_TEST(testArrayGet);
}
