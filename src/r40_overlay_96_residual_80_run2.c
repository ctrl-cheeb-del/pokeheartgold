#include "r40_overlay_96_residual_80_private.h"

void ov96_02200D7C(void *resources, void *work) {
    u32 ids[2] = { ov96_0221C728[6], ov96_0221C728[7] };
    u8 i;

    for (i = 0; i < 2; i++) {
        u32 offset = i * 4;
        u32 id = *(u32 *)((u8 *)ids + offset);
        void *character = *ov96_021EB5EC(resources, id, 0);
        void *palette = *ov96_021EB5EC(resources, id, 1);
        void *charProxy = SpriteTransfer_GetCharProxy(character);
        void *paletteProxy = SpriteTransfer_GetPaletteProxy(palette, charProxy);
        u8 *cursor = (u8 *)work + offset;

        U32_AT(cursor, 0x140) = NNS_G2dGetImageLocation(charProxy, NNS_G2D_VRAM_TYPE_2DSUB);
        U32_AT(cursor, 0x148) = NNS_G2dGetImagePaletteLocation(paletteProxy, NNS_G2D_VRAM_TYPE_2DSUB);
    }
}

void ov96_02200DF8(void *work) {
    AddWindow(PTR(work, 8), (u8 *)work + 0xc, ov96_0221C760);
    AddWindow(PTR(work, 8), (u8 *)work + 0x1c, ov96_0221C768);
    BG_FillCharDataRange(PTR(work, 8), 4, 0, 1, 0);
    LoadFontPal0(4, 0x1e0, U32_AT(work, 0));
}

void *ov96_02200E3C(u32 heapId, u8 count) {
    u8 *work = Heap_Alloc(heapId, 0x3e8);

    MI_CpuFill8(work, 0, 0x3e8);
    work[0x3e0] = count;
    work[0x3e5] = 4 - count;
    work[0x3e4] = work[0x3e5];
    work[0x3e3] = 10;
    work[0x3e2] = work[0x3e3];
    return work;
}
