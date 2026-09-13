#ifndef OV39_RESIDUAL20_PRIVATE_H
#define OV39_RESIDUAL20_PRIVATE_H

#include "global.h"

typedef struct Ov39Residual20App {
    void *unk00;
    void *unk04;
    u32 unk08;
    u32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[8];
    void *unk28;
    void *unk2C;
    u8 pad30[0x40 - 0x30];
    u32 unk40;
    u8 pad44[0x84 - 0x44];
    void *unk84;
    void *unk88;
    u8 pad8C[4];
    u32 unk90;
    u32 unk94;
} Ov39Residual20App;

BOOL ov39_02228BAC(Ov39Residual20App *app);
BOOL ov39_02228C78(Ov39Residual20App *app);
BOOL ov39_02228D0C(Ov39Residual20App *app);

#endif
