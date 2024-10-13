//
// Created by oshul on 10/13/2024.
//

#include "stringTests.h"

#include "string.h"
#include "unity.h"
#include "unity_internals.h"

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
    TEST_ASSERT_EQUAL_STRING(wrapStrings(1, (char *[]){ "abc"}, ", ", '(', ')'), "(abc)");
}

void runStringTests() {
    RUN_TEST(concatenateStrings_should_concatenate_strings);
    RUN_TEST(joinStrings_should_join_strings_with_delimiter);
    RUN_TEST(wrapStrings_should_join_strings_with_delimiter_and_terminators);
}
