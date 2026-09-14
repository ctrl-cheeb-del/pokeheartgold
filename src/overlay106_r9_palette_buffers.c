#include "overlay106_r9_palette_buffers_private.h"

void ov106_021E69F0(Ov106R9Work *work, int index, int member) {
    NNSG2dPaletteData *palette;
    void *buffer;
    Ov106R9PaletteBlock *block;

    buffer = GfGfxLoader_GetPlttDataFromOpenNarc(work->narc, member + 0x88, &palette, 0x99);
    block = &work->blocks[index];
    block->size = palette->szByte;
    MIi_CpuCopy32(palette->pRawData, (u32 *)block->data, block->size);
    Heap_Free(buffer);
}

void ov106_021E6A34(Ov106R9Work *work) {
    u32 i;

    for (i = 0; i < 3; i++) {
        if (work->blocks[i].size != 0) {
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(work->blocks[i].data, i * 0x2000, work->blocks[i].size);
            GX_EndLoadBGExtPltt();
            work->blocks[i].size = 0;
        }
    }
}
