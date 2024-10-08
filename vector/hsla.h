//
// Created by oshul on 10/8/2024.
//

#ifndef COLOR_H
#define COLOR_H

/*
 *
 *
 *
 */
typedef enum {
    LINEAR,
    CYCLICAL
} InterpolationType;

char *hslaToString(double color[static 4]);


#endif //COLOR_H
