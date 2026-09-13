#include "r40_overlay_64_residual_3_candidate_private.h"

void ov64_021E5B10(Ov64InitWork *work) {
    GraphicsModes modes;
    BgTemplate bg0;
    BgTemplate bg1;
    BgTemplate bg4;
    BgTemplate bg5;
    NARC *narc;
    work->bgConfig = BgConfig_Alloc(HEAP_ID_59);
    modes = ov64_021E6E88;
    SetBothScreensModesAndDisable(&modes);
    bg0 = ov64_021E6F50;
    InitBgFromTemplate(work->bgConfig, 0, &bg0, 0);
    BgClearTilemapBufferAndCommit(work->bgConfig, 0);
    BG_ClearCharDataRange(0, 0x20, 0, HEAP_ID_59);
    bg1 = ov64_021E6EFC;
    InitBgFromTemplate(work->bgConfig, 1, &bg1, 0);
    bg4 = ov64_021E6F18;
    InitBgFromTemplate(work->bgConfig, 4, &bg4, 0);
    BgClearTilemapBufferAndCommit(work->bgConfig, 4);
    BG_ClearCharDataRange(4, 0x20, 0, HEAP_ID_59);
    bg5 = ov64_021E6F34;
    InitBgFromTemplate(work->bgConfig, 5, &bg5, 0);
    narc = NARC_New((NarcId)0x61, HEAP_ID_59);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0, work->bgConfig, (GFBgLayer)1, 0, 0, 1, HEAP_ID_59);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, work->bgConfig, (GFBgLayer)1, 0, 0, 1, HEAP_ID_59);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 2, (enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0, 0x20, HEAP_ID_59);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 3, work->bgConfig, (GFBgLayer)5, 0, 0, 1, HEAP_ID_59);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 4, work->bgConfig, (GFBgLayer)5, 0, 0, 1, HEAP_ID_59);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 5, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0, 0x20, HEAP_ID_59);
    NARC_Delete(narc);
    LoadFontPal0((enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0x1E0, HEAP_ID_59);
    LoadFontPal0((enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0x1E0, HEAP_ID_59);
}
