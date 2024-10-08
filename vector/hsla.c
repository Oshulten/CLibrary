//
// Created by oshul on 10/8/2024.
//

#include "hsla.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

char *hslaToString(double const color[4]) {
    char *string = calloc(24, sizeof(char));
    snprintf(string, 24, "[%f, %f, %f, %f]", color[0], color[1], color[2], color[3]);
    return string;
}

double *hslaBlendPairByWeights(double const weights[4], double const firstColor[4], double const secondColor[4]) {
    static double blend[4] = { 0.0 };

    for (int i = 0; i < 4; i++) {
        blend[i] = (1.0 - weights[i])*firstColor[i] + weights[i]*secondColor[i];
    }

    return blend;
}

double *hslaBlendPairByFactor(double const factor, double const firstColor[4], double const secondColor[4]) {
    static double blend[4] = { 0.0 };

    for (int i = 0; i < 4; i++) {
        blend[i] = (1.0 - factor)*firstColor[i] + factor*secondColor[i];
    }

    return blend;
}

double *hslaBlend(double const weights[4], const InterpolationType interpolationType, int colorCount, double colors[0][4]) {
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

    const int shift = (int)hsla[0] / 60;
    const double cycle[] = { C + m, X + m, m, m, X + m, C + m };

    static double rgba[4] = {
        cycle[shift],
        cycle[(shift+4) % 6],
        cycle[(shift + 2) % 6],
        hsla[3]
    };

    return rgba;
}