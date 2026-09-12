#ifndef POKEHEARTGOLD_MODEL_BOX_TEST_INTERNAL_H
#define POKEHEARTGOLD_MODEL_BOX_TEST_INTERNAL_H

#include <nnsys.h>

#include "global.h"

typedef struct BoxTestParams {
    s16 x;
    s16 y;
    s16 z;
    s16 width;
    s16 height;
    s16 depth;
} BoxTestParams;

typedef struct ModelBounds {
    u8 pad00[0x18];
    s16 x;
    s16 y;
    s16 z;
    s16 width;
    s16 height;
    s16 depth;
    fx32 scale;
} ModelBounds;

typedef struct SimpleBounds {
    s16 x;
    s16 y;
    s16 z;
    s16 pad06;
    fx32 scaleX;
    fx32 scaleY;
    fx32 scaleZ;
} SimpleBounds;

BOOL sub_0201FA34(const VecFx32 *translation, const SimpleBounds *bounds);
void sub_0201FAA4(s16 x, s16 y, s16 z, s16 width, s16 height, s16 depth, BoxTestParams *box);
BOOL sub_0201FAC8(const BoxTestParams *box);
int G3X_GetBoxTestResult(u32 *result);

#endif // POKEHEARTGOLD_MODEL_BOX_TEST_INTERNAL_H
