//
// Created by oshul on 10/9/2024.
//

#include "animation.h"
#include "stack.h"

typedef double (*TimeFunction)(double);

typedef enum {
    ONE_SHOT,
    REPEAT,
    PING_PONG
} RepetitionType;

typedef struct {
    TimeFunction timeFunction;
    RepetitionType repetitionType;
    int iterations;
    double startTime;
} Animation;

typedef struct {
    Array animations;
    double startTime;
} AnimationEngine;

AnimationEngine initializeAnimationEngine(double startTime) {
    AnimationEngine engine = {
        .animations = createArray(),
        .startTime = startTime
    };

    return engine;
}

int AddAnimation(TimeFunction time_function, RepetitionType repetitionType, int iterations, )