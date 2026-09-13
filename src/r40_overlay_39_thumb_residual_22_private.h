#ifndef OV39_RESIDUAL22_PRIVATE_H
#define OV39_RESIDUAL22_PRIVATE_H

#include "global.h"

typedef struct Ov39Residual22App {
    void *unk00;
    void *unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[4];
    void *unk24;
    u8 pad28[0x40 - 0x28];
    u32 unk40;
    u8 pad44[0x64 - 0x44];
    u8 unk64[0x2C];
    u32 unk90;
    u32 unk94;
    s32 unk98;
} Ov39Residual22App;

BOOL ov39_02228EC8(Ov39Residual22App *app);
BOOL ov39_02228F18(Ov39Residual22App *app);
BOOL ov39_02228F54(Ov39Residual22App *app);
BOOL ov39_02228FC8(Ov39Residual22App *app);

#endif
