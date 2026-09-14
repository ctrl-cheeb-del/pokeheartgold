#ifndef POKEHEARTGOLD_OVERLAY49_STATE_MOTION_R14_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_STATE_MOTION_R14_PRIVATE_H

#include "global.h"
#include "math_util.h"
#include "overlay_42.h"

typedef struct Ov49R14Anim {
    UnkStruct_ov42_02228110 *unk00;
    void *unk04;
    u16 unk08;
    u8 unk0A;
    u8 unk0B;
    u32 unk0C[4];
    s32 unk1C;
    s32 unk20;
} Ov49R14Anim;

typedef struct Ov49R14Spin {
    void *unk00;
    void *unk04;
    u16 unk08;
    u8 unk0A;
    u8 unk0B;
    s32 unk0C;
    VecFx32 unk10;
} Ov49R14Spin;

extern void ov45_0223089C(void *, u32);
extern void ov45_0223093C(void *, u32);
extern void ov45_02230974(void *, u32);
extern void ov45_02230908(void *, VecFx32 *);
extern void ov45_022308E4(void *, VecFx32 *);
extern void ov45_02230968(void *);
extern void ov45_02230920(void *, u32);
extern void ov49_02259320(u32 *, u32, u32, u32);
extern u32 ov49_0225932C(u32 *, s32);
extern u32 ov49_022593BC(u32 *);
extern void ov49_02258E04(void *, UnkStruct_ov44_02232914, s32);

void ov49_02259764(Ov49R14Anim *work, u32 arg1, u32 arg2);
void ov49_0225991C(Ov49R14Spin *work);

#endif
