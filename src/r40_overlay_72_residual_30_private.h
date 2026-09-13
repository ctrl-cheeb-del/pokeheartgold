#ifndef OV72_RESIDUAL30_PRIVATE_H
#define OV72_RESIDUAL30_PRIVATE_H

#include "global.h"

typedef struct Ov72Residual30 {
    void *bgConfig;
    void *sprite;
    u8 window1[0x10];
    u8 window2[0x10];
    u32 heapId;
    u8 unk2C;
    u8 unk2D;
    u8 palette;
    u8 bgLayer;
    u8 fontPalette;
    u8 baseTile;
    u8 secondBgLayer;
} Ov72Residual30;

BOOL ov72_0223B088(Ov72Residual30 *work);
void ov72_0223B0C4(Ov72Residual30 *work);
void ov72_0223B1C8(Ov72Residual30 *work);
void ov72_0223B2C0(Ov72Residual30 *work);

#endif
