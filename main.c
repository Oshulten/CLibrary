#include <stdio.h>
#include <stdlib.h>

#include "vector/vector.h"

bool approximateEqual(const double value, const double comparisonValue, const double epsilon) {
    return abs(value - comparisonValue) <= epsilon;
}

int main(void) {
    const Vector vector = createVector(3, 1.0, 2, 3);
    printf("%f %f %f", vector.elements[0], vector.elements[1], vector.elements[2]);
    return 0;
}
