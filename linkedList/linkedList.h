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
void insertNodeAfter(Node* node, Node* insertion);
void insertNodeBefore(Node* node, Node* insertion);
void deleteNode(Node *node);
void connectNodes(Node *firstNode, Node *secondNode);

void printAddresses(Node *head);

#endif //LINKEDLIST_H
