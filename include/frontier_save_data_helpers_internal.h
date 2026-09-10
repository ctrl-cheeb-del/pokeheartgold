#ifndef PRIVATE_OVERLAY_80_022357B4_H
#define PRIVATE_OVERLAY_80_022357B4_H

#include "global.h"

typedef struct Overlay80Bits {
    u8 padding[0x10];
    u8 unused : 1;
    u8 value : 2;
} Overlay80Bits;

typedef struct Overlay80Counter {
    u8 padding_00[0xD];
    u8 count;
    u8 padding_0E[0xC];
    u16 base;
} Overlay80Counter;

u32 ov80_0222A30C(u8 value);
u32 sub_020674A4(u32 value);
void ov80_02236450(void *data, void *array, u32 value, u32 count, void *values1, void *values2, u32 zero, u32 word);
void ov80_02236698(void *saveData, void *array, u32 index);

void ov80_022357B4(void *data, void *saveData);
u32 ov80_02235898(void *data, u32 index);
void ov80_022358B0(void *data, u32 value);
u32 ov80_022358C4(void *data);
u32 ov80_022358E8(void *data);

#endif
