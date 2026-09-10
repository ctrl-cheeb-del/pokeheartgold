#include "overlay_29_helpers_internal.h"

void ov29_0225D5EC(void *unused, SysTaskPrivate *task) {
    Ov29StatePrivate *state = SysTask_GetData(task);
    ov29_0225DC34(state);
    ov29_0225D828(state);
    ov29_0225D7D4(state);
    ov29_0225D6B4(state->bgConfig);
    DestroySysTaskAndEnvironment(task);
    Heap_Destroy(8);
}

BOOL ov29_0225D61C(void) {
    return TRUE;
}

void ov29_0225D620(void) {
    vu32 *reg = (vu32 *)0x04001000;
    GX_SetBankForSubBG((GXVRamSubBG)0x80);
    GX_SetBankForSubOBJ((GXVRamSubOBJ)0x100);
    *reg = (*reg & 0xFFCFFFEF) | 0x10;
}

void ov29_0225D648(BgConfigPrivate *bgConfig) {
    BgTemplatePrivate template4;
    BgTemplatePrivate template5;
    GXS_SetGraphicsMode((GXBGMode)0);
    template4 = ov29_0225E1C8;
    InitBgFromTemplate(bgConfig, 4, &template4, 0);
    BG_ClearCharDataRange(4, 0x20, 0, 8);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    template5 = ov29_0225E200;
    InitBgFromTemplate(bgConfig, 5, &template5, 0);
}

void ov29_0225D6B4(BgConfigPrivate *bgConfig) {
    FreeBgTilemapBuffer(bgConfig, 5);
    FreeBgTilemapBuffer(bgConfig, 4);
}

void ov29_0225D6C8(Ov29StatePrivate *state, void *narc) {
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 9, state->bgConfig, 5, 0, 0, 0, 8);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 10, state->bgConfig, 5, 0, 0, 0, 8);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 8, 4, 0, 0, 8);
}
