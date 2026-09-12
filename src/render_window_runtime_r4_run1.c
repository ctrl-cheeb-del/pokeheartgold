#include "render_window_runtime_r4_private.h"

void sub_0200EB80(BgConfig *bgConfig, u8 bgId, u16 baseTile, u8 color, u8 type, enum HeapID heapId) {
    NNSG2dCharacterData *charData;
    void *raw = GfGfxLoader_GetCharData((NarcId)0x26, (s32)sub_0200E63C((void *)(u32)type), FALSE, &charData, heapId);
    u8 *tiles = Heap_Alloc(heapId, 0x240);
    u32 i;

    memcpy(tiles, charData->pRawData, 0x240);
    for (i = 0; i < 0x240; i++) {
        u8 high = tiles[i] >> 4;
        u8 low = tiles[i] & 0xf;
        if (high == 0) {
            high = color;
        }
        if (low == 0) {
            low = color;
        }
        tiles[i] = (high << 4) | low;
    }
    BG_LoadCharTilesData(bgConfig, bgId, tiles, 0x240, baseTile);
    Heap_Free(raw);
    Heap_Free(tiles);
}
