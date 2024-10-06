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

bool almostEqual(const double value, const double comparisonValue, const double epsilon);
bool arraysAreEqual(const int count, const double array[count], const double comparison[count]);
void printArray(int count, double elements[], const char delimiters[]);

Vector createVector(const int dimension, double elements[]);
void printVector(Vector vector);
void freeVector(Vector vector);
bool vectorsAreEqual(const Vector firstVector, const Vector secondVector);
Vector copyVector(Vector vector);
//
// Vector translateVector(Vector vector, Vector translation);
// Vector dilateVector(Vector vector, Vector dilation);
//
// Vector operateOnVectors(Operation operation, int count, Vector vectors[]);
// Vector interpolateVectors(double factor, InterpolationType interpolationType, int count, Vector vectors[]);

#endif //VECTOR_H
