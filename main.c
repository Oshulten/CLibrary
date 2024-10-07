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

int main(void) {
    double d1 = 3.2;
    double d2 = 3.2;
    printf("\n%d", doubleEquals(&d1, &d2));
    // runVectorTests();
    Node nodeA = { &(double){1.0}, nullptr, nullptr };
    Node nodeB = { &(double){2.0}, nullptr, nullptr };
    Node nodeC = { &(double){3.0}, nullptr, nullptr };

    connectNodes(&nodeA, &nodeB);
    connectNodes(&nodeB, &nodeC);

    printf("\nA address: %p, A value: %f", &nodeA, *(double*)nodeA.data);
    printf("\nB address: %p, B value: %f", &nodeB, *(double*)nodeB.data);
    printf("\nC address: %p, C value: %f", &nodeC, *(double*)nodeC.data);

    Node *searchResult = findAfter(&nodeA, &(double){2.5}, doubleEquals);
    if (searchResult)
        printf("\nfind address: %p, find value: %f", searchResult, *(double*)searchResult->data);

    return 0;
}
