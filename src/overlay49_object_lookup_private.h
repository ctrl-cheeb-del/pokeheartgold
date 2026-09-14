#ifndef OVERLAY_49_RESIDUAL_9_PRIVATE_H
#define OVERLAY_49_RESIDUAL_9_PRIVATE_H

#include "global.h"

#include "overlay_42.h"

typedef struct Ov49Residual9Entry {
    UnkStruct_ov42_02228110 *object;
    u8 rest[0x24];
} Ov49Residual9Entry;

typedef struct Ov49Residual9Context {
    UnkStruct_ov42_022280A8 *objects;
    u32 unk04;
    u8 *volatile entries;
    volatile u16 count;
    u8 unk0E[6];
    void *map;
} Ov49Residual9Context;

extern const u8 ov49_02269654[4];
int ov49_022589AC(void *map, u16 x, u16 y);
int ov49_022589C4(void *map, u16 x, u16 y);

Ov49Residual9Entry *ov49_02258F7C(Ov49Residual9Context *ctx, s32 x, s32 y);
BOOL ov49_02258FDC(Ov49Residual9Context *ctx, s32 x, s32 y);
BOOL ov49_0225904C(Ov49Residual9Context *ctx, Ov49Residual9Entry *entry, s32 *direction, UnkStruct_ov44_02232914 *position);

#endif
