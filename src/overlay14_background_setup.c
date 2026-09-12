#include "overlay14_background_setup_private.h"

void ov14_021E5A70(void *p) {
    R11GraphicsModes modes;
    R11BgTemplate bg0;
    R11BgTemplate bg1;
    R11BgTemplate bg2;
    R11BgTemplate bg3;
    R11BgTemplate bg4;
    R11BgTemplate bg5;
    R11BgTemplate bg6;

    PTR_AT(PTR_AT(p, 0x34), 0x14) = BgConfig_Alloc(0xa);
    modes = ov14_021F7BC8;
    SetBothScreensModesAndDisable(&modes);

    bg0 = ov14_021F7C20;
    InitBgFromTemplate(PTR_AT(PTR_AT(p, 0x34), 0x14), 0, &bg0, 0);
    BgClearTilemapBufferAndCommit(PTR_AT(PTR_AT(p, 0x34), 0x14), 0);
    BG_ClearCharDataRange(0, 0x20, 0, 0xa);

    bg1 = ov14_021F7C3C;
    InitBgFromTemplate(PTR_AT(PTR_AT(p, 0x34), 0x14), 1, &bg1, 0);
    BgClearTilemapBufferAndCommit(PTR_AT(PTR_AT(p, 0x34), 0x14), 1);
    BG_ClearCharDataRange(1, 0x20, 0, 0xa);

    bg2 = ov14_021F7C74;
    InitBgFromTemplate(PTR_AT(PTR_AT(p, 0x34), 0x14), 2, &bg2, 0);

    bg3 = ov14_021F7C90;
    InitBgFromTemplate(PTR_AT(PTR_AT(p, 0x34), 0x14), 3, &bg3, 0);

    bg4 = ov14_021F7C58;
    InitBgFromTemplate(PTR_AT(PTR_AT(p, 0x34), 0x14), 4, &bg4, 0);
    BgClearTilemapBufferAndCommit(PTR_AT(PTR_AT(p, 0x34), 0x14), 4);
    BG_ClearCharDataRange(4, 0x20, 0, 0xa);

    bg5 = ov14_021F7CAC;
    InitBgFromTemplate(PTR_AT(PTR_AT(p, 0x34), 0x14), 5, &bg5, 0);

    bg6 = ov14_021F7CC8;
    InitBgFromTemplate(PTR_AT(PTR_AT(p, 0x34), 0x14), 6, &bg6, 0);
    BgClearTilemapBufferAndCommit(PTR_AT(PTR_AT(p, 0x34), 0x14), 6);
    BG_ClearCharDataRange(6, 0x20, 0, 0xa);
}

void ov14_021E5C00(void *p) {
    FreeBgTilemapBuffer(PTR_AT(PTR_AT(p, 0x34), 0x14), 6);
    FreeBgTilemapBuffer(PTR_AT(PTR_AT(p, 0x34), 0x14), 5);
    FreeBgTilemapBuffer(PTR_AT(PTR_AT(p, 0x34), 0x14), 4);
    FreeBgTilemapBuffer(PTR_AT(PTR_AT(p, 0x34), 0x14), 3);
    FreeBgTilemapBuffer(PTR_AT(PTR_AT(p, 0x34), 0x14), 2);
    FreeBgTilemapBuffer(PTR_AT(PTR_AT(p, 0x34), 0x14), 1);
    FreeBgTilemapBuffer(PTR_AT(PTR_AT(p, 0x34), 0x14), 0);
    Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0x14));
}

void ov14_021E5C54(void *p) {
    GfGfxLoader_LoadCharData(0x13, 0xe, PTR_AT(PTR_AT(p, 0x34), 0x14), 0, 0, 0, 1, 0xa);
    GfGfxLoader_LoadCharData(0x13, 0xe, PTR_AT(PTR_AT(p, 0x34), 0x14), 1, 0, 0, 1, 0xa);
    GfGfxLoader_LoadCharData(0x13, 3, PTR_AT(PTR_AT(p, 0x34), 0x14), 2, 0, 0, 1, 0xa);
    GfGfxLoader_LoadScrnData(0x13, 2, PTR_AT(PTR_AT(p, 0x34), 0x14), 2, 0, 0, 1, 0xa);
    GfGfxLoader_LoadCharData(0x13, 1, PTR_AT(PTR_AT(p, 0x34), 0x14), 3, 0, 0, 1, 0xa);
    GfGfxLoader_LoadScrnData(0x13, 0, PTR_AT(PTR_AT(p, 0x34), 0x14), 3, 0, 0, 1, 0xa);
    GfGfxLoader_GXLoadPal(0x13, 4, 0, 0, 0x80, 0xa);
    GfGfxLoader_LoadCharData(0x13, 6, PTR_AT(PTR_AT(p, 0x34), 0x14), 5, 0, 0, 1, 0xa);
    GfGfxLoader_LoadScrnData(0x13, 5, PTR_AT(PTR_AT(p, 0x34), 0x14), 5, 0, 0, 1, 0xa);
    GfGfxLoader_GXLoadPal(0x13, 7, 4, 0, 0, 0xa);
    GfGfxLoader_LoadCharData(0x13, 6, PTR_AT(PTR_AT(p, 0x34), 0x14), 6, 0, 0, 1, 0xa);
}

void ov14_021E5D78(void *p) {
    PTR_AT(PTR_AT(p, 0x34), 0x20) = NewMsgDataFromNarc(0, 0x1b, 0x18, 0xa);
    PTR_AT(PTR_AT(p, 0x34), 0x1c) = MessagePrinter_New(1, 2, 0, 0xa);
    PTR_AT(PTR_AT(p, 0x34), 0x24) = MessageFormat_New(0xa);
    PTR_AT(PTR_AT(p, 0x34), 0x28) = String_New(0x400, 0xa);
}

void ov14_021E5DB8(void *p) {
    String_Delete(PTR_AT(PTR_AT(p, 0x34), 0x28));
    MessageFormat_Delete(PTR_AT(PTR_AT(p, 0x34), 0x24));
    MessagePrinter_Delete(PTR_AT(PTR_AT(p, 0x34), 0x1c));
    DestroyMsgData(PTR_AT(PTR_AT(p, 0x34), 0x20));
}

void ov14_021E5DE0(void *p) {
    void *work = PTR_AT(p, 0x34);
    GfGfxLoader_LoadCharData(0x13, 0x40, PTR_AT(work, 0x14), 0, 0x3e8, 0x300, 1, 0xa);
    GfGfxLoader_LoadCharData(0x13, 0x40, PTR_AT(work, 0x14), 1, 0x3e8, 0x300, 1, 0xa);
    GfGfxLoader_GXLoadPal(0x13, 0x41, 0, 0x180, 0x40, 0xa);
    LoadUserFrameGfx2(PTR_AT(work, 0x14), 0, 0x38e, 0xa, (u8)Options_GetFrame(PTR_AT(p, 0x10)), 0xa);
    LoadFontPal1(0, 0x160, 0xa);
    LoadFontPal0(4, 0x1e0, 0xa);
}

void ov14_021E5E74(void *p) {
    void *palette = PaletteData_Init(0xa);
    PTR_AT(PTR_AT(p, 0x34), 0x18) = palette;
    PaletteData_AllocBuffers(PTR_AT(PTR_AT(p, 0x34), 0x18), 0, 0x200, 0xa);
}
