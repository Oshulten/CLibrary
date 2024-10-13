//
// Created by oshul on 10/13/2024.
//

#include "stringTests.h"

#include <stdlib.h>

#include "string.h"
#include "unity.h"
#include "unity_internals.h"

void **intArrayToGenericPointer(int numberOfElements, int values[]) {
    void **elements = calloc(numberOfElements, sizeof(int));
    for (int i = 0; i < numberOfElements; i++) {
        elements[i] = &values[i];
    }
    return elements;
}

void **doubleArrayToGenericPointer(int numberOfElements, double values[]) {
    void **elements = calloc(numberOfElements, sizeof(double));
    for (int i = 0; i < numberOfElements; i++) {
        elements[i] = &values[i];
    }
    return elements;
}

void **stringArrayToGenericPointer(int numberOfElements, char *values[]) {
    void **elements = calloc(numberOfElements, sizeof(char*));
    for (int i = 0; i < numberOfElements; i++) {
        elements[i] = &values[i];
    }
    return elements;
}

void intToString_should_cast_int_to_string() {
    TEST_ASSERT_EQUAL_STRING(intToString(&(int){0}), "0");
    TEST_ASSERT_EQUAL_STRING(intToString(&(int){15}), "15");
    TEST_ASSERT_EQUAL_STRING(intToString(&(int){12345}), "12345");
}

void doubleToString_should_cast_double_to_string() {
    TEST_ASSERT_EQUAL_STRING(doubleToString(&(double){0.0}), "0.000");
    TEST_ASSERT_EQUAL_STRING(doubleToString(&(double){15.12345}), "15.123");
    TEST_ASSERT_EQUAL_STRING(doubleToString(&(double){12345.54321}), "12345.543");
}

void concatenateStrings_should_concatenate_strings() {
    TEST_ASSERT_EQUAL_STRING(concatenateStrings(3, (char *[]){ "abc", "123", "xyz"}), "abc123xyz");
    TEST_ASSERT_EQUAL_STRING(concatenateStrings(0, (char *[]){}), "");
}

void joinStrings_should_join_strings_with_delimiter() {
    TEST_ASSERT_EQUAL_STRING(joinStrings(3, (char *[]){ "abc", "123", "xyz"}, ", "), "abc, 123, xyz");
    TEST_ASSERT_EQUAL_STRING(joinStrings(1, (char *[]){ "abc"}, ", "), "abc");
}

void wrapStrings_should_join_strings_with_delimiter_and_terminators() {
    TEST_ASSERT_EQUAL_STRING(wrapStrings(3, (char *[]){ "abc", "123", "xyz"}, ", ", '[', ']'), "[abc, 123, xyz]");
    TEST_ASSERT_EQUAL_STRING(wrapStrings(3, (char *[]){ "abc", "123", "xyz"}, nullptr, '[', ']'), "[abc123xyz]");
    TEST_ASSERT_EQUAL_STRING(wrapStrings(3, (char *[]){ "abc", "123", "xyz"}, nullptr, 0, 0), "abc123xyz");
    TEST_ASSERT_EQUAL_STRING(wrapStrings(3, (char *[]){ "abc", "123", "xyz"}, ", ", '[', ']'), "[abc, 123, xyz]");
    TEST_ASSERT_EQUAL_STRING(wrapStrings(1, (char *[]){ "abc"}, ", ", '(', ')'), "(abc)");
}

void wrapElements_should_cast_elements_to_strings_and_join_strings_with_delimiter_and_terminators() {
    TEST_ASSERT_EQUAL_STRING(
        "[1, 2, 3]",
        wrapElements(
            3,
            intArrayToGenericPointer(3, (int[]) { 1, 2, 3} ),
            intToString,
            ", ", '[', ']'));

    TEST_ASSERT_EQUAL_STRING(
        "*1.000 - 2.000 - 3.000*",
        wrapElements(
            3,
            doubleArrayToGenericPointer(3, (double[]) { 1.0, 2.0, 3.0 } ),
            doubleToString,
            " - ", '*', '*'));
}

void runStringTests() {
    RUN_TEST(intToString_should_cast_int_to_string);
    RUN_TEST(doubleToString_should_cast_double_to_string);
    RUN_TEST(concatenateStrings_should_concatenate_strings);
    RUN_TEST(joinStrings_should_join_strings_with_delimiter);
    RUN_TEST(wrapStrings_should_join_strings_with_delimiter_and_terminators);
    RUN_TEST(wrapElements_should_cast_elements_to_strings_and_join_strings_with_delimiter_and_terminators);
}
