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
    HEAD,
    TAIL
} LeafType;

typedef enum {
    BEFORE,
    AFTER
} Direction;

Node *findLeaf(Node *member, LeafType leafType);
Node *findNode(Node *startNode, void *data, bool (*equalityFunction)(void *, void *), Direction direction);

void insertNode(Node* node, Node* insertion, Direction direction);
void deleteNode(Node *node);
void connectNodes(Node *firstNode, Node *secondNode);

void printAddresses(Node *head);
char *nodeToString(Node *node, char * (*dataToString)(void *), int maxDataStringLength);

#endif //LINKEDLIST_H
