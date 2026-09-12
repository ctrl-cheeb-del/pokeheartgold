#include "overlay102_ui_layout_r20_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov102_021EA80C(u8 *work, void *narc) {
    void *paletteData;
    void *allocation;

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 6, 0, 0, 0x1C0, 0x23);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0xD, 4, 0, 0x60, 0x23);
    allocation = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 0x10, &paletteData, 0x23);
    MIi_CpuCopy16(PTR(paletteData, 0xC), (u16 *)(work + 0xA0), 0x140);
    DC_FlushRange(work + 0xA0, 0x140);
    Heap_Free(allocation);
}

void ov102_021EA874(u8 *work) {
    if (ov102_021E8F6C(PTR(work, 4)) == 2) {
        u32 bank = ov102_021E8F84(PTR(work, 4)) + 1;
        work += 0xA0;
        u32 offset = bank << 5;
        GX_LoadBGPltt(work + offset, 0, 0x20);
        GXS_LoadBGPltt(work + offset, 0, 0x20);
    } else {
        GX_LoadBGPltt(work + 0xA0, 0, 0x20);
        work += 0xA0;
        GXS_LoadBGPltt(work, 0, 0x20);
    }
}

void ov102_021EA8C0(u8 *work) {
    switch (ov102_021E8F6C(PTR(work, 4))) {
    case 0:
        U16(work, 0x84) = 0x68;
        U16(work, 0x86) = 0x10;
        U32(work, 0x8C) = 1;
        break;
    case 1:
        U16(work, 0x84) = 0x30;
        U16(work, 0x86) = 0x10;
        U16(work, 0x88) = 0xA0;
        U16(work, 0x8A) = 0x10;
        U32(work, 0x8C) = 2;
        break;
    case 2:
        U32(work, 0x8C) = 0;
        break;
    }
}
