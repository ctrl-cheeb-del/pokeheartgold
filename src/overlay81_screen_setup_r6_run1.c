#include "overlay81_screen_setup_r6_private.h"

void ov81_022405F0(void *work) {
    u32 value = U32(work, 0x14);
    if ((value & 3) == 0) {
        if ((value >> 2) >= 4) {
            U32(work, 0x14) = 0;
        }
        ov81_02240628(work, 7, (u8)((U32(work, 0x14) >> 2) + 2), 0x20, 0x20);
    }
    U32(work, 0x14)
    ++;
}

void ov81_02240628(void *work, int layer, u8 x, u8 y, u8 width) {
    BgTilemapRectChangePalette(PTR(work, 0x4c), layer, 0, 0, y, width, x);
    ScheduleBgTilemapBufferTransfer(PTR(work, 0x4c), layer);
}

void ov81_02240658(void *work, int kind) {
    int value;
    switch (kind) {
    case 0:
        value = 1;
        break;
    case 1:
        value = 2;
        break;
    case 4:
        value = 1;
        break;
    case 5:
        value = 2;
        break;
    default:
        value = 4;
        break;
    }
    U32(work, 0x380) = ov81_02241340(work, value);
}

void ov81_02240698(void *work, int layer) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(work, 0x3dc), 0x81, PTR(work, 0x4c), layer, 0, 0, 1, 0x64);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x3dc), 0x82, PTR(work, 0x4c), layer, 0, 0, 1, 0x64);
}

void ov81_022406E0(void *work, int layer) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(work, 0x3dc), 0x92, PTR(work, 0x4c), layer, 0, 0, 1, 0x64);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x3dc), 0x91, PTR(work, 0x4c), layer, 0, 0, 1, 0x64);
}

void ov81_02240728(void *work, int layer) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(work, 0x3dc), 4, PTR(work, 0x4c), layer, 0, 0, 1, 0x64);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x3dc), 8, PTR(work, 0x4c), layer, 0, 0, 1, 0x64);
}

void ov81_02240770(void) {
    void *data;
    void *resource = GfGfxLoader_GetPlttData(0xb7, 0xc1, &data, 0x64);
    DC_FlushRange(PTR(data, 0xc), 0x160);
    GX_LoadBGPltt(PTR(data, 0xc), 0, 0x160);
    Heap_Free(resource);
}

void ov81_022407A8(void *work, int layer) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(work, 0x3dc), 4, PTR(work, 0x4c), layer, 0, 0, 1, 0x64);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(work, 0x3dc), 7, PTR(work, 0x4c), layer, 0, 0, 1, 0x64);
    GfGfxLoader_GXLoadPalFromOpenNarc(PTR(work, 0x3dc), 0x95, 4, 0, 0x160, 0x64);
}
