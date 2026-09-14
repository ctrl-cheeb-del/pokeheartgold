#include "overlay96_sprite_resource_load_r14_private.h"

void ov96_021E8BB4(u8 *desc, int heapId, void *dst) {
    void *resource;
    u8 *palette;

    resource = AllocAndReadWholeNarcMemberByIdPair((NarcId)0x51, ov96_021E91B8(U16_AT(desc, 0), U16_AT(desc, 2), U8_AT(desc, 7)), (enum HeapID)heapId);
    palette = (u8 *)NNS_G3dGetTex((const NNSG3dResFileHeader *)resource);
    palette += U32_AT(palette, 0x38);
    if (U8_AT(desc, 6) != 0) {
        palette += 0x20;
    }
    MI_CpuCopy8(palette, dst, 0x20);
    Heap_Free(resource);
}

void ov96_021E8BF4(u8 *gfx, int index, int screen, void *palette) {
    BOOL loadMain = FALSE;
    BOOL loadSub = FALSE;
    void *paletteProxy;

    if (screen == 3) {
        loadMain = TRUE;
        loadSub = TRUE;
    } else if (screen == 1) {
        loadMain = TRUE;
    } else {
        loadSub = TRUE;
    }
    index *= 0x2C;
    paletteProxy = SpriteTransfer_GetPaletteProxy(
        PTR_AT((u8 *)PTR_AT(gfx, 0x154) + index, 4),
        SpriteTransfer_GetCharProxy(PTR_AT((u8 *)PTR_AT(gfx, 0x154) + index, 0)));
    DC_FlushRange(palette, 0x20);
    if (loadMain) {
        GX_LoadOBJPltt(palette, NNS_G2dGetImagePaletteLocation(paletteProxy, NNS_G2D_VRAM_TYPE_2DMAIN), 0x20);
    }
    if (loadSub) {
        GXS_LoadOBJPltt(palette, NNS_G2dGetImagePaletteLocation(paletteProxy, NNS_G2D_VRAM_TYPE_2DSUB), 0x20);
    }
}
