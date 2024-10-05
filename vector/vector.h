//
// Created by oshul on 10/5/2024.
//

#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    double* elements;
    int dimension;
} Vector;

typedef enum {
    ADD,
    MULTIPLY
} Operation;

Vector createVector(int dimension, ...);
void printVector(Vector vector);
void freeVector(Vector vector);

Vector operateOnVectors(Operation operation, int count, ...);

Vector copyVector(Vector vector);
Vector interpolateVectors(double factor, int count, ...);

#endif //VECTOR_H
