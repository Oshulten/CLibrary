//
// Created by oshul on 10/9/2024.
//

#include "unity.h"
#include "hslaTests.h"
#include "arrayTests.h"
#include "stringTests.h"

int main(void) {
    UNITY_BEGIN();
    runHslaTests();
    // runArrayTests();
    runStringTests();
    return UNITY_END();
}
