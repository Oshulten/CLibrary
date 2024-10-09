//
// Created by oshul on 10/8/2024.
//

#pragma once

typedef enum {
    LINEAR = 0,
    CYCLICAL
} InterpolationType;

char *hslaToString(double color[4]);
double *hslaBlendPairByWeights(double weights[4], double firstColor[4], double secondColor[4]);
double *hslaBlendPairByFactor(double factor, double firstColor[4], double secondColor[4]);
double *hslaBlend(double weights[4], InterpolationType interpolationType, int colorCount, double **colors);
double *hslaToRgba(double hsla[4]);
