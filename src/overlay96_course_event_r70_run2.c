#include "overlay96_course_event_r70_private.h"

BOOL ov96_021F9CA4(void *course) {
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021FC314(*(void **)(work + 0x228));
    ov96_021EB5BC(*(void **)(work + 0x224));
    return TRUE;
}

BOOL ov96_021F9CC4(void *course) {
    void *graphics;
    u8 *work;
    int i;
    int value;
    int quotient;

    work = PokeathlonCourse_GetHeapAllocPtr4(course);
    graphics = PokeathlonCourse_GetGraphicsSystem(course);
    ov96_021E9510(graphics);
    for (i = 0; i < 4; i++) {
        value = PokeathlonCourse_GetField5F0_AtIndex(course, i);
        quotient = value / 30;
        ov96_021E966C(course, graphics, i, (u16)value, quotient, (value % 30) * 10 / 30, 0, 1, 3, 1, 0x123);
    }
    ov96_021E93B4(graphics, 2);
    ov96_0221A56C(graphics, 0);
    ov96_021E952C(graphics);
    ov96_021E9570(graphics, 0);
    return TRUE;
}

BOOL ov96_021F9D58(void *course) {
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    sub_0203A914();
    ov96_021E87B0(PokeathlonCourse_GetSystem(course), 0);
    ov96_021FC1A8(*(void **)(work + 0x228));
    PokeathlonCourse_ResetField3A4(course);
    ov96_021FC690(*(void **)(work + 0xDC));
    ov96_021FC05C(*(void **)(work + 0xD8));
    FreeBgTilemapBuffer(*(BgConfig **)(work + 4), 0);
    FreeBgTilemapBuffer(*(BgConfig **)(work + 4), 1);
    FreeBgTilemapBuffer(*(BgConfig **)(work + 4), 2);
    FreeBgTilemapBuffer(*(BgConfig **)(work + 4), 3);
    FreeBgTilemapBuffer(*(BgConfig **)(work + 4), 4);
    FreeBgTilemapBuffer(*(BgConfig **)(work + 4), 5);
    FreeBgTilemapBuffer(*(BgConfig **)(work + 4), 6);
    FreeBgTilemapBuffer(*(BgConfig **)(work + 4), 7);
    RemoveWindow((Window *)(work + 8));
    Heap_Free(*(void **)(work + 4));
    ov96_021EA894(*(void **)(work + 0x3A4));
    ov96_021E9C0C(*(void **)(work + 0x3A0));
    ov96_021EB21C(*(void **)(work + 0x224));
    ov96_021E92D0();
    FontID_Release(4);
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreePtr4HeapAlloc(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    Heap_Destroy(HEAP_ID_138);
    return TRUE;
}

void ov96_021F9E3C(void) {
    GraphicsBanks banks = ov96_0221C534;
    GfGfx_SetBanks(&banks);
}

void ov96_021F9E5C(BgConfig *bgConfig) {
    GraphicsModes modes = ov96_0221C434;
    SetBothScreensModesAndDisable(&modes);
    {
        BgTemplate bg = ov96_0221C48C;
        InitBgFromTemplate(bgConfig, 0, &bg, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 0);
    }
    {
        BgTemplate bg = ov96_0221C4A8;
        InitBgFromTemplate(bgConfig, 1, &bg, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 1);
    }
    {
        BgTemplate bg = ov96_0221C4C4;
        InitBgFromTemplate(bgConfig, 2, &bg, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 2);
    }
    {
        BgTemplate bg = ov96_0221C4E0;
        InitBgFromTemplate(bgConfig, 3, &bg, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 3);
    }
    {
        BgTemplate bg = ov96_0221C454;
        InitBgFromTemplate(bgConfig, 4, &bg, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 4);
    }
    {
        BgTemplate bg = ov96_0221C470;
        InitBgFromTemplate(bgConfig, 5, &bg, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 5);
    }
    {
        BgTemplate bg = ov96_0221C518;
        InitBgFromTemplate(bgConfig, 6, &bg, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 6);
    }
    {
        BgTemplate bg = ov96_0221C4FC;
        InitBgFromTemplate(bgConfig, 7, &bg, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 7);
    }
    GfGfx_EngineATogglePlanes(8, 0);
}

void ov96_021F9FE8(BgConfig *bgConfig, enum HeapID heapId) {
    GfGfxLoader_LoadCharData(NARC_a_1_5_6, 1, bgConfig, (GFBgLayer)0, 0, 0, 0, heapId);
    GfGfxLoader_LoadCharData(NARC_a_1_5_6, 1, bgConfig, (GFBgLayer)4, 0, 0, 0, heapId);
}

void ov96_021FA020(BgConfig *bgConfig, enum HeapID heapId) {
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 2, bgConfig, (GFBgLayer)0, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 3, bgConfig, (GFBgLayer)1, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 4, bgConfig, (GFBgLayer)2, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 2, bgConfig, (GFBgLayer)4, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 3, bgConfig, (GFBgLayer)5, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 4, bgConfig, (GFBgLayer)6, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnData(NARC_a_1_5_6, 5, bgConfig, (GFBgLayer)7, 0, 0, 0, heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_5_6, 0, (enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0, 0x20, heapId);
    GfGfxLoader_GXLoadPal(NARC_a_1_5_6, 0, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0, 0x20, heapId);
}
