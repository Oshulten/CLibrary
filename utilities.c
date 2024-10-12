//
// Created by oshul on 10/12/2024.
//

#include "utilities.h"

#include <tgmath.h>

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