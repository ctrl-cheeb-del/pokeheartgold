#include "overlay70_ui_setup_residual24_private.h"

int ov70_0223E884(Ov70Work24 *work) {
    ov70_02238E44();
    sub_0203A930();
    return ov70_02246614[work->state](work);
}

int ov70_0223E8A4(Ov70Work24 *work) {
    sub_0203A914();
    ov70_0223ECA4(work);
    ov70_0224212C(work->manager11A8);
    ov70_0223ED24(work);
    ov70_0223EBD4(work);
    ov70_0223EA40(work->bgConfig);
    Sprite_SetDrawFlag(work->spriteF10, 0);
    ov70_02238E58(work);
    return 1;
}

int ov70_0223E8E8(Ov70Work24 *work, int msgId, int speed, int unused2, int unused3) {
    void *string = NewString_ReadMsgData(work->msgData, msgId);
    StringExpandPlaceholders(work->msgFmt, work->stringBBC, string);
    FillWindowPixelBuffer(work->windowF18, 0xF);
    DrawFrameAndWindow2(work->windowF18, 0, 1, 0xE);
    work->printer = AddTextPrinterParameterized(work->windowF18, 1, work->stringBBC, 0, 0, speed, 0);
    String_Delete(string);
}

void ov70_0223E954(void *bgConfig) {
    Ov70BgTemplate24 bg0;
    Ov70BgTemplate24 bg1;
    Ov70BgTemplate24 bg2;
    Ov70BgTemplate24 bg3;

    bg0 = ov70_02245970;
    InitBgFromTemplate(bgConfig, 0, &bg0, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 0);
    bg1 = ov70_0224598C;
    InitBgFromTemplate(bgConfig, 1, &bg1, 0);
    bg2 = ov70_02245954;
    InitBgFromTemplate(bgConfig, 2, &bg2, 0);
    FillBgTilemapRect(bgConfig, 2, 0, 0, 0, 0x20, 0x18, 0);
    BgCommitTilemapBufferToVram(bgConfig, 2);
    bg3 = ov70_02245938;
    InitBgFromTemplate(bgConfig, 3, &bg3, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
    BG_ClearCharDataRange(0, 0x20, 0, 0x3D);
    BG_ClearCharDataRange(3, 0x20, 0, 0x3D);
    ov70_022391F0(bgConfig, 0, 0);
}

void ov70_0223EA40(void *bgConfig) {
    ov70_022392BC(bgConfig);
    FreeBgTilemapBuffer(bgConfig, 2);
    FreeBgTilemapBuffer(bgConfig, 1);
    FreeBgTilemapBuffer(bgConfig, 0);
    FreeBgTilemapBuffer(bgConfig, 3);
}

void ov70_0223EA6C(Ov70Work24 *work) {
    void *bgConfig = work->bgConfig;
    void *narc = NARC_New(0x64, 0x3D);
    GfGfxLoader_GXLoadPal(0x64, 1, 0, 0, 0x40, 0x3D);
    LoadFontPal1(0, 0x1A0, 0x3D);
    LoadUserFrameGfx2(bgConfig, 0, 1, 0xE, (u8)Options_GetFrame(work->root->options), 0x3D);
    LoadUserFrameGfx1(bgConfig, 0, 0x1F, 0xB, 0, 0x3D);
    GfGfxLoader_LoadCharData(0x64, 0xC, bgConfig, 1, 0, 0xA00, 1, 0x3D);
    GfGfxLoader_LoadScrnData(0x64, 0x1A, bgConfig, 1, 0, 0x600, 1, 0x3D);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0xF, bgConfig, 2, 0, 0x600, 1, 0x3D);
    ov70_02239CF8(work);
    NARC_Delete(narc);
}
