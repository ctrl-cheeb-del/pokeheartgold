#ifndef TO45_SOL_R12_OVERLAY106_R9_PALETTE_BUFFERS_PRIVATE_H
#define TO45_SOL_R12_OVERLAY106_R9_PALETTE_BUFFERS_PRIVATE_H

#include "global.h"

typedef struct Ov106R9PaletteBlock {
    u8 data[0x2000];
    u32 size;
} Ov106R9PaletteBlock;

typedef struct Ov106R9Work {
    u8 pad000[4];
    void *narc;
    u8 pad008[0x2C];
    Ov106R9PaletteBlock blocks[3];
} Ov106R9Work;

void *GfGfxLoader_GetPlttDataFromOpenNarc(void *, int, NNSG2dPaletteData **, int);
void Heap_Free(void *);
void GX_BeginLoadBGExtPltt(void);
void GX_LoadBGExtPltt(const void *, u32, u32);
void GX_EndLoadBGExtPltt(void);

void ov106_021E69F0(Ov106R9Work *, int, int);
void ov106_021E6A34(Ov106R9Work *);

#endif
