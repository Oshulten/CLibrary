//
// Created by oshul on 10/8/2024.
//

#include "hsla.h"
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

char *hslaToString(double color[4]) {
    constexpr int stringLength = 35;
    char *string = calloc(stringLength, sizeof(char));
    snprintf(string, stringLength, "[%3.2f, %3.2f, %3.2f, %0.2f]", color[0], color[1], color[2], color[3]);
    return string;
}

double *hslaBlendPairByWeights(double weights[4], double firstColor[4], double secondColor[4]) {
    static double blend[4] = { 0.0 };

    for (int i = 0; i < 4; i++) {
        blend[i] = (1.0 - weights[i])*firstColor[i] + weights[i]*secondColor[i];
    }

    return blend;
}

double *hslaBlendPairByFactor(double factor, double firstColor[4], double secondColor[4]) {
    static double blend[4] = { 0.0 };

    for (int i = 0; i < 4; i++) {
        blend[i] = (1.0 - factor)*firstColor[i] + factor*secondColor[i];
    }

    return blend;
}

double *hslaBlend(double weights[4], InterpolationType interpolationType, int colorCount, double colors[0][4]) {
    colorCount += (interpolationType == CYCLICAL);

    static double blend[4];

    for (int i = 0; i < 4; i++) {
        const double factorDelta = 1.0 / (colorCount - 1);
        const double lessThanOneFactor = weights[i] - 0.1E-10;
        const int pairIndex = floor(lessThanOneFactor / factorDelta);
        const double normalizedFactor = (lessThanOneFactor / factorDelta) - pairIndex;

        blend[i] =
            (1.0 - normalizedFactor) * colors[pairIndex][i] +
            normalizedFactor * colors[(pairIndex+1)%colorCount][i];
    }

    return blend;
}

double *hslaToRgba(double hsla[4]) {
    const double S = hsla[1] / 100;
    const double L = hsla[2] / 100;

    const double C = (1.0 - fabs(2.0*L - 1.0)) * S;
    const double X = (1.0 - fabs((int)(hsla[0] / 60) % 2 - 1.0));
    const double m = L - C*0.5;

    const auto shift = (int)hsla[0] / 60;
    double *cycle = ((double[6]){ C + m, X + m, m, m, X + m, C + m });

    static double rgba[4];
    rgba[0] = cycle[shift];
    rgba[1] = cycle[(shift+4) % 6];
    rgba[2] = cycle[(shift + 2) % 6];
    rgba[3] = hsla[3];

    return rgba;
}