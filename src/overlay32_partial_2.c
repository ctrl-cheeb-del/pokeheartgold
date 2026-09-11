#include "overlay32_partial_internal.h"

void ov32_0225D634(BgConfig *bgConfig) {
    BgTemplate bg4;
    BgTemplate bg5;
    BgTemplate bg6;
    GXS_SetGraphicsMode(GX_BGMODE_0);
    bg4 = ov32_0225E1A4;
    InitBgFromTemplate(bgConfig, 4, &bg4, GF_BG_TYPE_TEXT);
    BG_ClearCharDataRange(4, 0x20, 0, HEAP_ID_8);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    bg5 = ov32_0225E1C0;
    InitBgFromTemplate(bgConfig, 5, &bg5, GF_BG_TYPE_TEXT);
    bg6 = ov32_0225E188;
    InitBgFromTemplate(bgConfig, 6, &bg6, GF_BG_TYPE_TEXT);
}

void ov32_0225D6C4(BgConfig *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, 6);
    FreeBgTilemapBuffer(bgConfig, 5);
    FreeBgTilemapBuffer(bgConfig, 4);
}

void ov32_0225D6E0(u8 *work, NARC *narc) {
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, *(BgConfig **)work, GF_BG_LYR_SUB_1, 0, 0, TRUE, HEAP_ID_8);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 1, *(BgConfig **)work, GF_BG_LYR_SUB_1, 0, 0, TRUE, HEAP_ID_8);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0, *(BgConfig **)work, GF_BG_LYR_SUB_2, 0, 0, TRUE, HEAP_ID_8);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, HEAP_ID_8);
}

void ov32_0225D748(u8 *work) {
    *(void **)(work + 0x144) = NewMsgDataFromNarc(0, 27, 196, 8);
    *(void **)(work + 0x148) = MessageFormat_New(8);
}

void ov32_0225D76C(u8 *work) {
    MessageFormat_Delete(*(void **)(work + 0x148));
    DestroyMsgData(*(void **)(work + 0x144));
}
