#ifndef POKEHEARTGOLD_OVERLAY49_OBJECT_CONTROLS_R7_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_OBJECT_CONTROLS_R7_PRIVATE_H
#include "global.h"

#include "overlay_42.h"
typedef struct R7Holder {
    UnkStruct_ov42_02228110 *unk0;
} R7Holder;
typedef struct R7State {
    u8 pad0[8];
    u16 unk8;
    u8 unkA;
    u8 unkB;
    u8 data[0x18];
    void *callback;
} R7State;
extern void GF_AssertFail(void);
extern void ov49_0225927C(void *, s32, s32, s32);
void ov49_02258DB4(R7Holder *, UnkStruct_ov44_02232914);
void ov49_02258E04(R7Holder *, UnkStruct_ov44_02232914, s32);
void ov49_02258E60(R7Holder *, s32);
void ov49_02258E7C(void *, R7Holder *, s32, s32);
void ov49_02258EAC(R7Holder *, R7Holder *, u16, u8);
#endif
