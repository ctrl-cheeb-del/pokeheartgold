#include "to45_overlay96_r59b_private.h"

void ov96_021F584C(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate bg2;
    BgTemplate bg1;
    BgTemplate bg3;
    BgTemplate bg4;
    BgTemplate bg5;
    BgTemplate bg6;

    modes = ov96_0221C100;
    SetBothScreensModesAndDisable(&modes);
    bg2 = ov96_0221C124;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &bg2, 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    bg1 = ov96_0221C140;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &bg1, 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    bg3 = ov96_0221C15C;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &bg3, 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    bg4 = ov96_0221C178;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &bg4, 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    bg5 = ov96_0221C194;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &bg5, 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    bg6 = ov96_0221C1B0;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &bg6, 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
    GfGfx_EngineATogglePlanes(8, 0);
}

void ov96_021F5980(void *arg) {
    u8 *work = arg;

    GfGfxLoader_LoadCharData((NarcId)0xa8, 7, PTR_AT(work, 0), (GFBgLayer)2, 0, 0, 0, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_LoadCharData((NarcId)0xa8, 5, PTR_AT(work, 0), (GFBgLayer)1, 0, 0, 0, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_LoadCharData((NarcId)0xa8, 10, PTR_AT(work, 0), (GFBgLayer)4, 0, 0, 0, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_LoadCharData((NarcId)0xa8, 12, PTR_AT(work, 0), (GFBgLayer)5, 0, 0, 0, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_LoadScrnData((NarcId)0xa8, 8, PTR_AT(work, 0), (GFBgLayer)2, 0, 0, 0, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_LoadScrnData((NarcId)0xa8, 6, PTR_AT(work, 0), (GFBgLayer)1, 0, 0, 0, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_LoadScrnData((NarcId)0xa8, 11, PTR_AT(work, 0), (GFBgLayer)4, 0, 0, 0, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_LoadScrnData((NarcId)0xa8, 13, PTR_AT(work, 0), (GFBgLayer)5, 0, 0, 0, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_GXLoadPal((NarcId)0xa8, 4, (enum GFPalLoadLocation)0, (enum GFPalSlotOffset)0, 0x20, (enum HeapID)U32_AT(work, 0x54));
    GfGfxLoader_GXLoadPal((NarcId)0xa8, 9, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0, 0x40, (enum HeapID)U32_AT(work, 0x54));
    PTR_AT(work, 0x58) = GfGfxLoader_GetScrnData((NarcId)0xa8, 14, 0, (NNSG2dScreenData **)(work + 0x5c), (enum HeapID)U32_AT(work, 0x54));
}
