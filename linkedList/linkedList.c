//
// Created by oshul on 10/7/2024.
//

#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>

Node *endOfLinkedList(Node *member) {
    Node *currentNode = member;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

Node *startOfLinkedList(Node *member) {
    Node *currentNode = member;
    while (currentNode->previous != nullptr) {
        currentNode = currentNode->previous;
    }
    return currentNode;
}

Node *findLeaf(Node *member, LeafType leafType) {
    switch (leafType) {
        case HEAD:
            return startOfLinkedList(member);
        default:
            return endOfLinkedList(member);
    }
}

void insertNodeAfter(Node *node, Node *insertion) {
    Node *nextNode = node->next;
    node->next = insertion;
    insertion->previous = node;
    insertion->next = nextNode;
    nextNode->previous = node;
}

void insertNodeBefore(Node *node, Node *insertion) {
    Node *earlierNode = node->previous;
    node->previous = insertion;
    insertion->next = node;
    insertion->previous = earlierNode;
    earlierNode->next = insertion;
}

void insertNode(Node *node, Node *insertion, Direction direction) {
    switch (direction) {
        case BEFORE:
            insertNodeBefore(node, insertion);
            return;
        default:
            insertNodeAfter(node, insertion);
    }
}

Node *findNode(Node *startNode, void *data, bool (*equalityFunction)(void *, void *), Direction direction) {
    Node *currentNode = startNode;

    do {
        if (equalityFunction(currentNode->data, data))
            return currentNode;
    } while ((currentNode = (
                  direction == AFTER
                      ? currentNode->next
                      : currentNode->previous)) != nullptr);

    return nullptr;
}

void deleteNode(Node *node) {
    node->previous->next = node->next;
    node->next->previous = node->previous;
}

void connectNodes(Node *firstNode, Node *secondNode) {
    firstNode->next = secondNode;
    secondNode->previous = firstNode;
}

void printAddresses(Node *head) {
    Node *currentNode = head;
    do {
        printf("\n%p", currentNode);
    } while ((currentNode = currentNode->next) != nullptr);
}
