#include <stdio.h>

#include "vector/vector.h"
#include "vector/vectorTests.h"
#include "linkedList/linkedList.h"

int main(void) {
    // runVectorTests();
    Node nodeA = { nullptr, nullptr, nullptr };
    Node nodeB = { nullptr, nullptr, nullptr };
    Node nodeC = { nullptr, nullptr, nullptr };

    connectNodes(&nodeA, &nodeB);
    insertBefore(&nodeB, &nodeC);

    printf("\nNode A address: %p", &nodeA);
    printf("\nNode B address: %p", &nodeB);
    printf("\nNode C address: %p", &nodeC);

    printAddresses(&nodeA);
    return 0;
}
