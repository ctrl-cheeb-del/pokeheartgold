#include "to45_overlay15_prefix_r3_private.h"

void ov15_021F99A4(void *bgConfig) {
    ScreenModes modes = ov15_02200518;
    SetBothScreensModesAndDisable(&modes);
    InitBgFromTemplate(bgConfig, 1, ov15_022006CC, 0);
    InitBgFromTemplate(bgConfig, 2, ov15_022006E8, 0);
    InitBgFromTemplate(bgConfig, 3, ov15_02200704, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
    BG_ClearCharDataRange(1, 0x20, 0, 6);
    InitBgFromTemplate(bgConfig, 4, ov15_02200720, 0);
    InitBgFromTemplate(bgConfig, 5, ov15_0220073C, 0);
    InitBgFromTemplate(bgConfig, 6, ov15_02200758, 0);
    InitBgFromTemplate(bgConfig, 7, ov15_02200774, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    BgClearTilemapBufferAndCommit(bgConfig, 7);
    BG_ClearCharDataRange(4, 0x20, 0, 6);
    BG_ClearCharDataRange(7, 0x20, 0, 6);
    G2x_SetBlendAlpha_(0x04000050, 0, 8, 0, 0);
}

void ov15_021F9A8C(void *bgConfig) {
    GfGfx_EngineATogglePlanes(0x1F, 0);
    GfGfx_EngineBTogglePlanes(0x1B, 0);
    FreeBgTilemapBuffer(bgConfig, 7);
    FreeBgTilemapBuffer(bgConfig, 6);
    FreeBgTilemapBuffer(bgConfig, 5);
    FreeBgTilemapBuffer(bgConfig, 4);
    FreeBgTilemapBuffer(bgConfig, 3);
    FreeBgTilemapBuffer(bgConfig, 2);
    FreeBgTilemapBuffer(bgConfig, 1);
    Heap_FreeExplicit(6, bgConfig);
}

void ov15_021F9AE4(void *work) {
    PTR(work, 0x244) = NARC_New(0xF, 6);
    GfGfxLoader_LoadCharData(0xF, 7, PTR(work, 0), 2, 0, 0, 0, 6);
    GfGfxLoader_LoadScrnData(0xF, 0x36, PTR(work, 0), 2, 0, 0, 0, 6);
    if (U8(work, 0x615) == 0) {
        GfGfxLoader_LoadScrnData(0xF, 0x5E, PTR(work, 0), 3, 0, 0, 0, 6);
    } else {
        GfGfxLoader_LoadScrnData(0xF, 0x5D, PTR(work, 0), 3, 0, 0, 0, 6);
    }
    GfGfxLoader_GXLoadPal(0xF, 8, 0, 0, 0, 6);
    GfGfxLoader_GXLoadPal(0xF, 0x11, 0, 0x1A0, 0x20, 6);
    LoadFontPal1(0, 0x160, 6);
    LoadUserFrameGfx1(PTR(work, 0), 1, 0x3F7, 0xE, 0, 6);
    LoadUserFrameGfx2(PTR(work, 0), 1, 0x3D9, 0xC, (u8)Options_GetFrame(PTR(work, 0x240)), 6);
    GfGfxLoader_GXLoadPal(0xF, 0x26, 4, 0, 0, 6);
    LoadFontPal1(4, 0x160, 6);
    GfGfxLoader_LoadCharData(0xF, 0x2E, PTR(work, 0), 6, 0, 0, 0, 6);
    PTR(work, 0x68C) = GfGfxLoader_GetPlttData(0xF, 0x28, (u8 *)work + 0x694, 6);
    PTR(work, 0x690) = GfGfxLoader_GetPlttData(0xF, 0x29, (u8 *)work + 0x698, 6);
    GfGfxLoader_GXLoadPal(0xF, 8, 4, 0x100, 0x80, 6);
    LoadUserFrameGfx2(PTR(work, 0), 4, 0x3E2, 0xC, (u8)Options_GetFrame(PTR(work, 0x240)), 6);
}

void ov15_021F9C78(void *work, int mode) {
    if (mode == 1) {
        GfGfxLoader_LoadScrnData(0xF, 0x36, PTR(work, 0), 2, 0, 0, 0, 6);
    } else {
        GfGfxLoader_LoadScrnData(0xF, 9, PTR(work, 0), 2, 0, 0, 0, 6);
    }
}

void ov15_021F9CBC(void *work) {
    PTR(work, 0x2F0) = NewMsgDataFromNarc(0, 0x1B, 0xA, 6);
    PTR(work, 0x2EC) = MessagePrinter_New(1, 2, 0, 6);
    PTR(work, 0x2F4) = MessageFormat_New(6);
    PTR(work, 0x2F8) = NewMsgDataFromNarc(0, 0x1B, 0xDE, 6);
    PTR(work, 0x2FC) = NewMsgDataFromNarc(0, 0x1B, 0x2EE, 6);
    PTR(work, 0x5E4) = String_New(0x100, 6);
}

void ov15_021F9D28(void *work) {
    u8 i;
    U8(work, 0x614) = 0;
    for (i = 0; i < 8; i++) {
        void *entry = (u8 *)PTR(work, 0x234) + i * 12;
        if (PTR(entry, 4) != NULL) {
            U8(work, 0x614)
            ++;
        }
    }
}
