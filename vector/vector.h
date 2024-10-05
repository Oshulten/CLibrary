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

typedef enum {
    LINEAR,
    CYCLICAL
} InterpolationType;

Vector createVector(int dimension, ...);
void printVector(Vector vector);
void freeVector(Vector vector);
Vector copyVector(Vector vector);

Vector translateVector(Vector vector, Vector translation);
Vector dilateVector(Vector vector, Vector dilation);

Vector operateOnVectors(Operation operation, int count, ...);
Vector interpolateVectors(double factor, int count, ...);

#endif //VECTOR_H
