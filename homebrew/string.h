//
// Created by oshul on 10/13/2024.
//

#ifndef STRING_H
#define STRING_H

typedef char*(*anyToString)(void*);

char *intToString(void *ptr);
char *doubleToString(void *ptr);
char *concatenateStrings(int numberOfStrings, char **strings);
char *joinStrings(int numberOfStrings, char **strings, char *delimiter);
char *wrapStrings(int numberOfStrings, char **strings, char *delimiter, char beginning, char end);
char *concatenateElements(int numberOfElements, void **elements, anyToString elementToString);
char *joinElements(int numberOfElements, void **elements, anyToString elementToString, char *delimiter);
char *wrapElements(int numberOfElements, void **elements, anyToString elementToString, char *delimiter, char beginning, char end);

#endif //STRING_H
