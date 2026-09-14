#ifndef OVERLAY72_RESIDUAL7_PRIVATE_H
#define OVERLAY72_RESIDUAL7_PRIVATE_H

#include "global.h"

typedef void NARC;
typedef void BgConfig;

NARC *NARC_New(int, int);
void NARC_Delete(NARC *);
void GfGfxLoader_GXLoadPalFromOpenNarc(NARC *, int, int, int, int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(NARC *, int, BgConfig *, int, int, int, int, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(NARC *, int, BgConfig *, int, int, int, int, int);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void ov72_0223A3E0(void *, void *, int, int, int, int);

typedef struct Overlay72Residual7Work {
    u32 unk;
    u32 active;
    u8 pad[0x80];
    u8 pal[0x2A0];
    s16 idx;
    s8 dir;
    u8 tick;
    u32 mode;
} Overlay72Residual7Work;

void ov72_02238B18(void *arg, int variant);
void ov72_02238E3C(void *task, Overlay72Residual7Work *work);
void ov72_02238EE4(void *arg);

#endif
