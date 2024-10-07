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

Node *endOfLinkedList(Node *member);
Node *startOfLinkedList(Node *member);
void connectNodes(Node *firstNode, Node *secondNode);

#endif //LINKEDLIST_H
