//
// Created by oshul on 10/5/2024.
//

#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    double* elements;
    int dimension;
} Vector;

Vector createVector(const int dimension, ...);
void printVector(const Vector vector);
void freeVector(const Vector vector);

Vector addVectors(const int count, ...);
Vector multiplyVectors(const int count, ...);
Vector translateVector(const Vector vector, const Vector translation);
Vector dilateVector(const Vector vector, const Vector dilation);

Vector copyVector(const Vector vector);
Vector interpolateVectors(const double factor, const int count, ...);

#endif //VECTOR_H
