//
// Created by oshul on 10/7/2024.
//

#include "linkedList.h"

#include <stdio.h>

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

void insertAfter(Node* node, Node* insertion) {
    Node *nextNode = node -> next;
    node -> next = insertion;
    insertion -> previous = node;
    insertion -> next = nextNode;
    nextNode -> previous = node;
}

void insertBefore(Node* node, Node* insertion) {
    Node *earlierNode = node -> previous;
    node -> previous = insertion;
    insertion -> next = node;
    insertion -> previous = earlierNode;
    earlierNode -> next = insertion;
}

void connectNodes(Node *firstNode, Node *secondNode) {
    firstNode -> next = secondNode;
    secondNode -> previous = firstNode;
}

void printAddresses(Node *head) {
    Node *currentNode = head;
    do {
        printf("\n%p", currentNode);
    }
    while ((currentNode = currentNode -> next) != nullptr);
}