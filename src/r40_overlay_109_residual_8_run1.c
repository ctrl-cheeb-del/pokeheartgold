#include "global.h"

#include "r40_overlay_109_residual_8_private.h"

void ov109_021E6AFC(R40PhotoApp8 *app) {
    vu16 *reg = (vu16 *)0x04000304;
    BgSetPosTextAndCommit(app->bg, 7, (enum BgPosAdjustOp)0, 0);
    FreeBgTilemapBuffer(app->bg, 3);
    FreeBgTilemapBuffer(app->bg, 2);
    FreeBgTilemapBuffer(app->bg, 1);
    FreeBgTilemapBuffer(app->bg, 0);
    FreeBgTilemapBuffer(app->bg, 6);
    FreeBgTilemapBuffer(app->bg, 7);
    FreeBgTilemapBuffer(app->bg, 4);
    Heap_Free(app->bg);
    *reg |= (u32)reg >> 11;
}

void ov109_021E6B5C(R40PhotoApp8 *app) {
    NARC *narc = NARC_New((NarcId)0xAB, (enum HeapID)app->heapId);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 4, (enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0, 0, (enum HeapID)app->heapId);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 4, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0, 0, (enum HeapID)app->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 9, app->bg, (GFBgLayer)6, 0, 0, 0, (enum HeapID)app->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 5, app->bg, (GFBgLayer)7, 0, 0, 0, (enum HeapID)app->heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 10, app->bg, (GFBgLayer)6, 0, 0, 0, (enum HeapID)app->heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 5, app->bg, (GFBgLayer)3, 0, 0, 0, (enum HeapID)app->heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 6, app->bg, (GFBgLayer)3, 0, 0, 0, (enum HeapID)app->heapId);
    app->rawB0 = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 8, 0, &app->scrnAC, (enum HeapID)app->heapId);
    app->rawB8 = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 8, 0, &app->scrnB4, (enum HeapID)app->heapId);
    app->rawC0 = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 7, 0, &app->scrnBC, (enum HeapID)app->heapId);
    NARC_Delete(narc);
    LoadFontPal1((enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0x180, (enum HeapID)app->heapId);
    LoadUserFrameGfx2(app->bg, (GFBgLayer)0, 1, 0xD, app->frame, (enum HeapID)app->heapId);
}
