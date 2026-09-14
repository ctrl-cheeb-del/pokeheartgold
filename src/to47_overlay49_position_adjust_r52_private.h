#ifndef TO47_OVERLAY49_POSITION_ADJUST_R52_PRIVATE_H
#define TO47_OVERLAY49_POSITION_ADJUST_R52_PRIVATE_H

#include "global.h"

typedef struct Ov49PositionR52 {
    s16 x;
    s16 y;
} Ov49PositionR52;

Ov49PositionR52 ov49_0225D1EC(void *context);
void ov49_0225D1C4(void *context, Ov49PositionR52 position);
extern const s32 ov49_02269A74[];

void ov49_0225EE4C(void *context, int kind);

#endif
