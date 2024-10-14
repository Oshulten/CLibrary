//
// Created by oshul on 10/13/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string.h"

char *intToString(void *ptr) {
    char *string = calloc(50, sizeof(char));
    sprintf(string, "%d", *(int *)ptr);
    return string;
}

char *doubleToString(void *ptr) {
    char *string = calloc(50, sizeof(char));
    sprintf(string, "%.3f", *(double *) ptr);
    return string;
}


char *concatenateStrings(int numberOfStrings, char **strings) {
    return wrapStrings(numberOfStrings, strings, nullptr, 0, 0);
}

char *joinStrings(int numberOfStrings, char **strings, char *delimiter) {
    return wrapStrings(numberOfStrings, strings, delimiter, 0, 0);
}

char *wrapStrings(int numberOfStrings, char **strings, char *delimiter, char beginning, char end) {
    return wrapElements(numberOfStrings, strings, nullptr, delimiter, beginning, end);
}

char *concatenateElements(int numberOfElements, void **elements, anyToString elementToString) {
    return wrapElements(numberOfElements, elements, elementToString, nullptr, 0, 0);
}

char *joinElements(int numberOfElements, void **elements, anyToString elementToString, char *delimiter) {
    return wrapElements(numberOfElements, elements, elementToString, delimiter, 0, 0);
}

char *wrapElements(int numberOfElements, void **elements, anyToString elementToString, char *delimiter, char beginning, char end) {
    size_t stringLengths[numberOfElements];
    char *elementStrings[numberOfElements];
    const size_t delimiterLength = delimiter == nullptr ? 0 : strlen(delimiter);
    const size_t wrappingLength = (beginning != 0) + (end != 0);

    size_t totalStringLengths = 0;

    for (int i = 0; i < numberOfElements; i++) {
        elementStrings[i] = elementToString != nullptr ? elementToString(elements[i]) : elements[i];
        stringLengths[i] = strlen(elementStrings[i]);
        totalStringLengths += stringLengths[i];
    }

    const size_t totalStringLength = totalStringLengths + 1 + wrappingLength + delimiterLength * (numberOfElements - 1);

    char *returnString = calloc(totalStringLength, sizeof(char));

    int currentPosition = 0;
    if (beginning != 0) {
        returnString[0] = beginning;
        currentPosition++;
    }

    for (int i = 0; i < numberOfElements; i++) {
        for (int j = 0; j < stringLengths[i]; j++) {
            returnString[currentPosition] = elementStrings[i][j];
            currentPosition++;
        }

        if (i < numberOfElements - 1 && delimiterLength > 0) {
            for (int k = 0; k < delimiterLength; k++) {
                returnString[currentPosition] = delimiter[k];
                currentPosition++;
            }
        }
    }

    if (end != 0) {
        returnString[currentPosition] = end;
        currentPosition++;
    }
    returnString[currentPosition] = '\0';

    return returnString;
}