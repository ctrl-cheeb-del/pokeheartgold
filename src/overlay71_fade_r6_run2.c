#include "overlay71_fade_r6_private.h"
void ov71_02247230(void *work, int type, int bgId, int palette, int x, int y) {
    void *screen;
    void *buffer;
    int member;
    if (type == 0) {
        member = 0x10a;
    } else if (*(void **)((u8 *)work + 0x148) != NULL) {
        member = 0x10b;
    } else {
        member = 0x10a;
    }
    buffer = GfGfxLoader_GetScrnData(7, member, 0, &screen, 0x38);
    if (buffer != NULL) {
        CopyToBgTilemapRect(*(void **)((u8 *)work + 8), bgId, x, y, 10, 10, (u8 *)screen + 0xc, 0, 0, 0x20, 0x20);
        BgTilemapRectChangePalette(*(void **)((u8 *)work + 8), bgId, x, y, 10, 10, palette);
        Heap_Free(buffer);
    }
}

void ov71_022472C4(void *dst, s32 narcId, s32 cellId, s32 animId) {
    *(void **)dst = GfGfxLoader_GetCellBank(narcId, cellId, 1, (void **)((u8 *)dst + 8), 0x39);
    *(void **)((u8 *)dst + 4) = GfGfxLoader_GetAnimBank(narcId, animId, 1, (void **)((u8 *)dst + 0xc), 0x39);
}
