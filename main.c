#include "vector/vector.h"
#include "vector/vectorTests.h"

int main(void) {
    runVectorTests();
    const Vector vector = createVector(3, 0.0, 0.0, 0.0);
    const Vector vector2 = createVector(3, 1.0, 1.0, 1.0);
    const Vector vector3 = interpolateVectors(0.5, CYCLICAL, 2, vector, vector2);
    printVector(vector3);
    return 0;
}
