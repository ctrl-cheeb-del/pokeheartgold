#include "overlay115_palette_blend_private.h"

void ov115_02260254(void *sprite, int heapID, void *narc, u8 amount, u16 color) {
    struct PaletteData {
        u32 pad[3];
        u16 *pRawData;
    } *raw;
    void *paletteAllocation;
    void *proxy;
    u16 *buffer = Heap_Alloc(heapID, 0x20);

    paletteAllocation = GfGfxLoader_GetPlttData(0x6D, narc, (void **)&raw, heapID);
    BlendPalette(raw->pRawData, buffer, 0x10, amount, color);
    proxy = Sprite_GetPaletteProxy(sprite);
    DC_FlushRange(buffer, 0x20);
    GX_LoadOBJPltt(buffer, NNS_G2dGetImagePaletteLocation(proxy, (NNS_G2D_VRAM_TYPE)1), 0x20);
    Heap_Free(buffer);
    Heap_Free(paletteAllocation);
}
