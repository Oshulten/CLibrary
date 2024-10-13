//
// Created by oshul on 10/12/2024.
//

#include "arrayTests.h"
#include "unity.h"
#include "array.h"
#include "toString.h"

void arrayPush_should_store_the_pushed_elements_and_reallocate_size_automatically() {
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
}

void arrayToString_should_return_correct_string() {
    Array array = arrayCreate(2);
    TEST_ASSERT_EQUAL_STRING(arrayToString(&array, intToString), "[]");
    arrayPush(&array, &(int){0});
    arrayPush(&array, &(int){1});
}

void arrayGet_should_return_the_stored_elements() {
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
}

void arraySet_should_change_the_data() {
    constexpr int numberOfElementsToPush = 22;

    Array array = arrayCreate(5);

    arrayPush(&array, &(int *){0});
    arrayPush(&array, &(int *){1});
    arrayPush(&array, &(int *){2});

    arraySet(&array, 0, &(int *){2});
    arraySet(&array, 0, &(int *){1});
    arraySet(&array, 0, &(int *){0});

    TEST_ASSERT_EQUAL(array.numberOfElements, 3);
    TEST_ASSERT_EQUAL(array.memorySize, 5);

    TEST_ASSERT_EQUAL(*(int*)arrayGet(&array, 0), 2);
    TEST_ASSERT_EQUAL(*(int*)arrayGet(&array, 1), 1);
    TEST_ASSERT_EQUAL(*(int*)arrayGet(&array, 2), 0);
}

void runArrayTests() {
    RUN_TEST(arrayPush_should_store_the_pushed_elements_and_reallocate_size_automatically);
    RUN_TEST(arrayToString_should_return_correct_string);
    // RUN_TEST(arrayGet_should_return_the_stored_elements);
    // RUN_TEST(arraySet_should_change_the_data);
}
