#ifndef OVERLAY_92_RESIDUAL_18_RESIDUAL_1_PRIVATE_H
#define OVERLAY_92_RESIDUAL_18_RESIDUAL_1_PRIVATE_H

#include "global.h"

typedef struct ManagedSprite ManagedSprite;

typedef struct Ov92AnimState {
    s32 state;
    s32 active;
    ManagedSprite *sprites[8];
    s32 unk28;
    u8 pad2C[0x20];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
} Ov92AnimState;

typedef struct Ov92DoneFlags {
    s32 v[4];
} Ov92DoneFlags;

extern const u16 ov92_02263E04[];
extern const Ov92DoneFlags ov92_02263E3C;

void ManagedSprite_GetPositionXY(ManagedSprite *, s16 *, s16 *);
void ManagedSprite_SetPositionXY(ManagedSprite *, s16, s16);
void ManagedSprite_TickTwoFrames(ManagedSprite *);
void sub_02018198(void *, s32);
void sub_020182A0(ManagedSprite *, int);

void ov92_02261208(Ov92AnimState *);
void ov92_0226135C(Ov92AnimState *);

#endif
