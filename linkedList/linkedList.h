//
// Created by oshul on 10/7/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    void *data;
    struct Node *previous;
    struct Node *next;
} Node;

#endif //LINKEDLIST_H
