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

typedef enum {
    BEFORE,
    AFTER
} Direction;

Node *endOfLinkedList(Node *member);
Node *startOfLinkedList(Node *member);
Node *findAfter(Node *startNode, void *data, bool (*equalityFunction)(void*, void*));

void insertNode(Node* node, Node* insertion, Direction direction);
void deleteNode(Node *node);
void connectNodes(Node *firstNode, Node *secondNode);

void printAddresses(Node *head);

#endif //LINKEDLIST_H
