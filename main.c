#include <float.h>
#include <stdio.h>
#include <tgmath.h>

#include "vector/vector.h"
#include "vector/vectorTests.h"
#include "linkedList/linkedList.h"

bool doubleEquals(void *term1, void *term2) {
    double value1 = *((double*)term1);
    double value2 = *((double*)term2);
    return fabs(value1 - value2) <= DBL_MIN;
}

char *doubleToString(void *ptr) {
    static char string[50];
    snprintf(string, 50, "%.5f", *(double*)ptr);
    return string;
}

int main(void) {
    // runVectorTests();
    Node nodeA = { &(double){1.0}, nullptr, nullptr };
    Node nodeB = { &(double){2.0}, nullptr, nullptr };
    Node nodeC = { &(double){3.0}, nullptr, nullptr };

    connectNodes(&nodeA, &nodeB);
    connectNodes(&nodeB, &nodeC);

    printf("\nA address: %p, A value: %f", &nodeA, *(double*)nodeA.data);
    printf("\nB address: %p, B value: %f", &nodeB, *(double*)nodeB.data);
    printf("\nC address: %p, C value: %f", &nodeC, *(double*)nodeC.data);

    printf("\n%s", doubleToString(nodeB.data));
    printf("\n%s", nodeToString(&nodeB, doubleToString, 50));
    return 0;
}
