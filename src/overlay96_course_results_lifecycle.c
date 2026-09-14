#include "overlay96_course_results_lifecycle_private.h"

void ov96_02209C14(BgConfig *bgConfig, u32 heapId) {
    GraphicsModes modes = ov96_0221CC0C;
    s32 i;

    SetBothScreensModesAndDisable(&modes);
    {
        Ov96BgTemplates6 templates = ov96_0221CCF8;

        for (i = 0; i < 6; i++) {
            InitBgFromTemplate(bgConfig, (u8)ov96_0221CC48[i], &templates.templates[i], 0);
            BgClearTilemapBufferAndCommit(bgConfig, (u8)ov96_0221CC48[i]);
            BG_ClearCharDataRange((u8)ov96_0221CC48[i], 0x20, 0, (enum HeapID)heapId);
        }
        FontID_Alloc(4, heapId);
        GfGfx_EngineATogglePlanes(4, 0);
        BgSetPosTextAndCommit(bgConfig, 0, (enum BgPosAdjustOp)3, 0x10);
    }
}

void ov96_02209CA8(u8 *work) {
    s32 i;
    u8 *cursor;

    for (i = 0, cursor = work; i < 3; i++, cursor += 4) {
        String_Delete(PTR(cursor, 0x18));
    }
    MessageFormat_Delete(PTR(work, 0x25c));
    DestroyMsgData(PTR(work, 0x258));
    for (i = 0; i < 4; i++) {
        RemoveWindow((Window *)(work + 0x218 + i * 0x10));
    }
    for (i = 0; i < 6; i++) {
        FreeBgTilemapBuffer(PTR(work, 4), (u8)ov96_0221CC48[i]);
    }
    FontID_Release(4);
    Heap_Free(PTR(work, 4));
}

void ov96_02209D14(u8 *work) {
    GfGfxLoader_LoadCharData(0xea, 1, PTR(work, 4), 0, 0, 0, 1, U32(work, 0));
    GfGfxLoader_LoadScrnData(0xea, 2, PTR(work, 4), 0, 0, 0, 1, U32(work, 0));
    GfGfxLoader_GXLoadPal(0xea, 0, 0, 0, 0, U32(work, 0));
    LoadFontPal0(0, 0x1e0, U32(work, 0));
    GfGfxLoader_LoadCharData(0xea, 4, PTR(work, 4), 4, 0, 0, 1, U32(work, 0));
    GfGfxLoader_LoadCharData(0xea, 4, PTR(work, 4), 5, 0, 0, 1, U32(work, 0));
    GfGfxLoader_LoadScrnData(0xea, 5, PTR(work, 4), 4, 0, 0, 1, U32(work, 0));
    GfGfxLoader_LoadScrnData(0xea, 6, PTR(work, 4), 5, 0, 0, 1, U32(work, 0));
    GfGfxLoader_GXLoadPal(0xea, 3, 4, 0, 0, U32(work, 0));
}
