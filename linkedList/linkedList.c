//
// Created by oshul on 10/7/2024.
//

#include "linkedList.h"

Node *endOfLinkedList(Node *member) {
    const Node *currentNode = member;
    while (currentNode -> next != nullptr) {
        currentNode = currentNode -> next;
    }
    return currentNode;
}

Node *startOfLinkedList(Node *member) {
    Node *currentNode = member;
    while (currentNode -> previous != nullptr) {
        currentNode = currentNode -> previous;
    }
    return currentNode;
}

void connectNodes(Node *firstNode, Node *secondNode) {
    firstNode -> next = secondNode;
    secondNode -> previous = firstNode;
}