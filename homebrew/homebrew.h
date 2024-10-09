//
// Created by oshul on 10/9/2024.
//

#ifndef HOMEBREW_H
#define HOMEBREW_H

typedef enum {
    LINEAR,
    CYCLICAL
} InterpolationType;

char *hslaToString(double color[4]);
double *hslaBlendPairByWeights(double weights[4], double firstColor[4], double secondColor[4]);
double *hslaBlendPairByFactor(double factor, double firstColor[4], double secondColor[4]);
double *hslaBlend(double weights[4], InterpolationType interpolationType, int colorCount, double colors[0][4]);
double *hslaToRgba(double hsla[4]);

#endif //HOMEBREW_H
