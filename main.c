#include <stdio.h>
#include <stdlib.h>

#include "vector/vector.h"

bool approximateEqual(const double value, const double comparisonValue, const double epsilon) {
    return abs(value - comparisonValue) <= epsilon;
}

int main(void) {
    const Vector vector = createVector(3, 1.0, 2.0, 3.0);
    printVector(vector);
    return 0;
}
