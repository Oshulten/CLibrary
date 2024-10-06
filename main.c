#include <stdio.h>

#include "vector/vector.h"
#include "vector/vectorTests.h"
#include "linkedList/linkedList.h"

int main(void) {
    // runVectorTests();
    double nodeData = 3.42;

    const Node node = {                 
        .data = &nodeData,
        .previous = nullptr,
        .next = nullptr
    };

    printf("%f", *(double*)node.data);
    return 0;
}
