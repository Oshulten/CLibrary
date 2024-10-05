#include "vector/vector.h"

int main(void) {
    const Vector vector = createVector(3, 0.0, 0.0, 0.0);
    const Vector vector2 = createVector(3, 1.0, 1.0, 1.0);
    const Vector vector3 = interpolateVectors(1.0, LINEAR, 2, vector, vector2);
    printVector(vector3);
    return 0;
}
