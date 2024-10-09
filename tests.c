//
// Created by oshul on 10/9/2024.
//

#include "unity.h"
#include "homebrew/hsla.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void hsla_should_print_correctly(void) {
    //test stuff
    TEST_ASSERT_EQUAL_STRING("[0.00, 0.00, 0.00, 0.00]", hslaToString((double[]){ 0.0, 0.0, 0.0, 0.0 }));
    TEST_ASSERT_EQUAL_STRING("[255.00, 0.00, 0.00, 0.00]", hslaToString((double[]){ 255.0, 0.0, 0.0, 0.0 }));
    TEST_ASSERT_EQUAL_STRING("[255.00, 0.00, 0.00, 0.00]", hslaToString((double[]){ 255.0, 110.0, 0.0, 110.0 }));
}

void test_function_should_doAlsoDoBlah(void) {
    //more test stuff
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(hsla_should_print_correctly);
    RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}