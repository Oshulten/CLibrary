#include <stdio.h>

#include "vector/vector.h"
#include "vector/vectorTests.h"
#include "linkedList/linkedList.h"

int main(void) {
    // runVectorTests();
    double nodeData = 3.42;
    double nodeData2 = 1.0;

    Node nodes[10];
    for (int i = 0; i < 10; i++) {
        Node node = {
            .data = nullptr,
            .previous = nullptr,
            .next = nullptr
        };
        nodes[i] = node;
    }

    for (int i = 0; i < 9; i++) {
        connectNodes(&nodes[i], &nodes[i+1]);
    }


    printf("\nNode 1 address: %p, beginning of list: %p", &nodes[0], startOfLinkedList(&nodes[9]));
    printf("\nNode 2 address: %p, end of list: %p", &nodes[9], endOfLinkedList(&nodes[0]));
    return 0;
}
