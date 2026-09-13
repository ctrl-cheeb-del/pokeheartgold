#ifndef OV48_RESIDUAL3_PRIVATE_H
#define OV48_RESIDUAL3_PRIVATE_H

#include "global.h"

typedef struct Ov48R3Flags {
    u32 unk00;
    u32 enabled : 1;
    u32 languageFlag : 1;
    u32 remainingFlags : 30;
} Ov48R3Flags;

typedef struct Ov48R3Record {
    u16 value;
    u8 unk02;
    u8 kindAndFlags;
} Ov48R3Record;

BOOL ov48_022593B4(u8 *work, u16 a1, u16 a2);
void ov48_022593F4(Ov48R3Flags *state, Ov48R3Record **records);
void ov48_02259464(u8 *work, void *config, u32 heapId);

#endif
