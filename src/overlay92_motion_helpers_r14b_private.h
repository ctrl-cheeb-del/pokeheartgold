#ifndef POKEHEARTGOLD_OVERLAY92_MOTION_HELPERS_R14B_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY92_MOTION_HELPERS_R14B_PRIVATE_H
#include "global.h"
typedef struct ManagedSprite ManagedSprite;
typedef struct Ov92Motion {
    ManagedSprite *sprite;
    s32 state;
    s16 angle;
    u8 pad0A[6];
    s32 cycles;
    s16 baseX;
    s16 baseY;
    fx32 radiusX;
    fx32 radiusY;
    u8 tweenX[0x18];
    u8 tweenY[0x18];
} Ov92Motion;
void ManagedSprite_GetPositionFxXYWithSubscreenOffset(ManagedSprite *, fx32 *, fx32 *, fx32);
void ManagedSprite_SetPositionFxXYWithSubscreenOffset(ManagedSprite *, fx32, fx32, fx32);
s32 ov92_022619C4(s32);
void ov92_02260860(void *, s32, s32, s32);
BOOL ov92_02260870(void *);
fx32 GF_SinDeg(u16);
fx32 GF_CosDeg(u16);
BOOL ov92_02261E88(Ov92Motion *, s32, s32, s32);
BOOL ov92_02261F60(Ov92Motion *, s32, s32, s32);
BOOL ov92_02262018(Ov92Motion *, s32, s32, s32);
BOOL ov92_022620D0(Ov92Motion *, s32, s32, s32);
#endif
