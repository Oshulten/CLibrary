//
// Created by oshul on 10/13/2024.
//

#include "string.h"
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(int numberOfStrings, char **strings) {
    int stringLengths[numberOfStrings];
    int totalStringLengths = 0;

    for (int i = 0; i < numberOfStrings; i++) {
        stringLengths[i] = strlen(strings[i]);
        totalStringLengths += stringLengths[i];
    }

    char *returnString = calloc(totalStringLengths+1, sizeof(char));

    int currentPosition = 0;
    for (int i = 0; i < numberOfStrings; i++) {
        for (int j = 0; j < stringLengths[i]; j++) {
            char currentLetter = strings[i][j];
            returnString[currentPosition] = currentLetter;
            currentPosition++;
        }
    }
    returnString[currentPosition] = '\0';

    return returnString;
}

char *joinStrings(int numberOfStrings, char **strings, char *delimiter) {
    int stringLengths[numberOfStrings];
    int delimiterLength = strlen(delimiter);
    int totalStringLengths = 0;

    for (int i = 0; i < numberOfStrings; i++) {
        stringLengths[i] = strlen(strings[i]);
        totalStringLengths += stringLengths[i];
    }

    int totalStringLength = totalStringLengths + 1 + delimiterLength*(numberOfStrings - 1);

    char *returnString = calloc(totalStringLength, sizeof(char));

    int currentPosition = 0;
    for (int i = 0; i < numberOfStrings; i++) {
        for (int j = 0; j < stringLengths[i]; j++) {
            returnString[currentPosition] = strings[i][j];
            currentPosition++;
        }

        if (i < numberOfStrings - 1) {
            for (int k = 0; k < delimiterLength; k++) {
                returnString[currentPosition] = delimiter[k];
                currentPosition++;
            }
        }
    }

    returnString[currentPosition] = '\0';

    return returnString;
}

char *wrapStrings(int numberOfStrings, char **strings, char *delimiter, char beginning, char end) {
    int stringLengths[numberOfStrings];
    int delimiterLength = strlen(delimiter);
    int totalStringLengths = 0;

    for (int i = 0; i < numberOfStrings; i++) {
        stringLengths[i] = strlen(strings[i]);
        totalStringLengths += stringLengths[i];
    }

    int totalStringLength = totalStringLengths + 3 + delimiterLength*(numberOfStrings - 1);

    char *returnString = calloc(totalStringLength, sizeof(char));

    returnString[0] = beginning;

    int currentPosition = 1;
    for (int i = 0; i < numberOfStrings; i++) {
        for (int j = 0; j < stringLengths[i]; j++) {
            returnString[currentPosition] = strings[i][j];
            currentPosition++;
        }

        if (i < numberOfStrings - 1) {
            for (int k = 0; k < delimiterLength; k++) {
                returnString[currentPosition] = delimiter[k];
                currentPosition++;
            }
        }
    }

    returnString[currentPosition] = end;
    returnString[currentPosition+1] = '\0';

    return returnString;
}
