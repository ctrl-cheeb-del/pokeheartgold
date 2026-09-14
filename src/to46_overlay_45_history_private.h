#ifndef POKEHEARTGOLD_TO46_OVERLAY_45_HISTORY_PRIVATE_H
#define POKEHEARTGOLD_TO46_OVERLAY_45_HISTORY_PRIVATE_H

#include "global.h"

typedef struct Ov45History {
    s32 values[13];
    u8 ids[13];
    u8 oldest;
    u8 next;
    void *saveData;
    u16 crc;
    u16 corrupt;
} Ov45History;

void ov45_0222CB44(Ov45History *history, void *saveData);
void ov45_0222CB74(Ov45History *history, u8 id, s32 value);
BOOL ov45_0222CBD0(Ov45History *history, s32 oldValue, s32 newValue);
u8 ov45_0222CC00(Ov45History *history);
u8 ov45_0222CC50(Ov45History *history, u32 index);
s32 ov45_0222CC7C(Ov45History *history, u32 index);
void ov45_0222CCA4(Ov45History *history);
void ov45_0222CCB8(Ov45History *history);

#endif // POKEHEARTGOLD_TO46_OVERLAY_45_HISTORY_PRIVATE_H
