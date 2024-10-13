//
// Created by oshul on 10/13/2024.
//

#include "toString.h"

#include <stdio.h>

char *intToString(void *ptr) {
    static char string[50];
    sprintf(string, "%d", *(int*)ptr);
    return string;
}

char *doubleToString(void *ptr) {
    static char string[50];
    sprintf(string, "%.3f", *(double*)ptr);
    return string;
}

