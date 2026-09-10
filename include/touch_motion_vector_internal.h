#ifndef POKEHEARTGOLD_TOUCH_MOTION_VECTOR_INTERNAL_H
#define POKEHEARTGOLD_TOUCH_MOTION_VECTOR_INTERNAL_H
#include "global.h"
fx32 FX_Sqrt(fx32 x);
typedef struct Vec2f {
    float x;
    float y;
} Vec2f;

BOOL sub_020872DC(s16 x, s16 y, float fx, float fy, float *outX, float *outY, float speed, s16 minDist);

#endif
