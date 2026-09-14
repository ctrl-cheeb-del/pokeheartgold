#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_POSITION_LOOKUP_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_POSITION_LOOKUP_PRIVATE_H

#include "global.h"

extern const VecFx32 ov96_0221C98C[];

void ov96_0220404C(u32 x, u32 y, float *xOut, float *yOut);
void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *mtx, VecFx32 *result);
u8 ov96_022031A8(void *unused, int angle, u32 x, u32 y, VecFx32 *out);

#endif
