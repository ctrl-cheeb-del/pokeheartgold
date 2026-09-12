#include "overlay70_pokegear_phone_ui_private.h"

void ov70_0223D058(Ov70Work *work);
void ov70_0223D208(Ov70Work *work);
void ov70_0223D26C(Ov70Work *work);
void ov70_0223D378(Ov70Work *work);
void ov70_0223D3BC(Ov70Work *work);
void ov70_0223D414(Ov70Work *work);
int ov70_0223D44C(Ov70Work *work);
void ov70_0223D490(Ov70Work *work);
void ov70_0223D588(Ov70Work *work);
int ov70_0223D680(void);
void ov70_0223D690(Ov70Work *work, int code);
int ov70_0223D6C8(Ov70Work *work);
void ov70_0223D808(Ov70Work *work);
void ov70_0223D8E8(void *sprite, int index);

int ov70_0223C930(Ov70Work *work) {
    ov70_0223CAC4(work, 0x98, 1, 0, 0xf0f);
    ov70_02238D84(work, 0x15, 1);
    return 3;
}

int ov70_0223C958(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)work->printerBF0)) {
        work->state2c = work->field30;
    }
    return 3;
}

int ov70_0223C978(Ov70Work *work) {
    if (!TextPrinterCheckActive((u8)work->printerBF0)) {
        work->field11C0++;
        if (work->field11C0 > 0x2d) {
            work->field11C0 = 0;
            work->state2c = work->field30;
        }
    }
    return 3;
}

int ov70_0223C9AC(Ov70Work *work) {
    work->valueF14++;
    if (IsPaletteFadeFinished()) {
        *(vu16 *)0x04000304 |= 0x8000;
        work->valueF14 = -16;
        if (work->field11DE != 0) {
            Sprite_SetAnimCtrlSeq(work->spritesEE4[1], 0x10);
            work->state2c = 2;
            ov70_02238E50(work, 3, 0x10);
            work->field12C = 0;
        }
        Sprite_SetDrawFlag(work->spriteF10, 0);
    }
    return 3;
}

int ov70_0223CA18(Ov70Work *work) {
    work->valueF14--;
    if (IsPaletteFadeFinished()) {
        work->valueF14 = 0;
        work->state2c = 1;
    }
    return 3;
}

int ov70_0223CA40(Ov70Work *work) {
    int index;

    if (gSystem.newKeys & 1) {
        BeginNormalPaletteFade(0, 0, 0, 0, 0x10, 1, 0x3d);
    } else {
        index = ov70_02241164(work->field128);
        if (work->field11DE != 0 && index >= 0) {
            Sprite_SetAnimCtrlSeq(work->spritesEE4[index + 1], index * 4 + 0x10);
            work->state2c = 2;
            ov70_02238E50(work, 3, 0);
            work->field12C = index;
            PlaySE(0x5dc);
        }
    }
    return 3;
}

void ov70_0223CAC4(Ov70Work *work, int msgId, int color, int a, int b) {
    ReadMsgDataIntoString(work->msgDataBA0, msgId, work->strBBC);
    FillWindowPixelBuffer(work->windowF18, 0xf);
    DrawFrameAndWindow2(work->windowF18, 0, 1, 0xe);
    work->printerBF0 = AddTextPrinterParameterized(work->windowF18, 1, work->strBBC, 0, 0, color, 0);
}

void ov70_0223CB1C(void *a, void *b, void *msgData) {
    void *str;

    str = NewString_ReadMsgData(msgData, 0x3d);
    ov70_02245084(a, str, 0, 0, 0, 0xf0200);
    String_Delete(str);
    str = NewString_ReadMsgData(msgData, 0x3f);
    ov70_02245084((u8 *)a + 0x20, str, 0, 0, 0, 0xf0200);
    String_Delete(str);
    str = NewString_ReadMsgData(msgData, 0x41);
    ov70_02245084((u8 *)a + 0x40, str, 0, 0, 0, 0xf0200);
    String_Delete(str);
    str = NewString_ReadMsgData(msgData, 0xab);
    ov70_02245084(b, str, 0, 0, 0, 0xf0200);
    String_Delete(str);
    str = NewString_ReadMsgData(msgData, 0x43);
    ov70_022450B8((u8 *)a + 0x60, str, 0, 0, 0, 0xf0200);
    String_Delete(str);
    str = NewString_ReadMsgData(msgData, 0xee);
    ov70_022450B8((u8 *)a + 0x70, str, 0, 0, 0, 0xf0200);
    String_Delete(str);
}

void ov70_0223CC04(void *bgConfig, void *window, void *msgData, int flag) {
    u32 color = 0x10200;
    int pal;
    void *str;

    if (flag) {
        color = 0xf0200;
        pal = 0;
    } else {
        pal = 2;
    }
    BgTilemapRectChangePalette(bgConfig, 1, 0x12, 2, 0xe, 4, pal);
    BgCommitTilemapBufferToVram(bgConfig, 1);
    str = NewString_ReadMsgData(msgData, 0x45);
    ov70_022450B8(window, str, 0, 0, 0, color);
    String_Delete(str);
}

int ov70_0223CC68(const Ov70Key *a, const Ov70Key *b, int c, int d) {
    if (a->field00 == b->field00 && a->field02 == b->field02 && a->field03 == b->field03 && a->field04 == b->field04 && c == d) {
        return 1;
    }
    return 0;
}

void ov70_0223CCA4(Ov70Work *work) {
    BgSetPosTextAndCommit(work->bgConfig, 0, 3, work->valueF14);
    BgSetPosTextAndCommit(work->bgConfig, 1, 3, work->valueF14);
    BgSetPosTextAndCommit(work->bgConfig, 2, 3, work->valueF14);
    BgSetPosTextAndCommit(work->bgConfig, 3, 3, work->valueF14);
    BgSetPosTextAndCommit(work->bgConfig, 4, 3, -work->valueF14);
    BgSetPosTextAndCommit(work->bgConfig, 5, 3, -work->valueF14);
    BgSetPosTextAndCommit(work->bgConfig, 6, 3, -work->valueF14);
    BgSetPosTextAndCommit(work->bgConfig, 7, 3, -work->valueF14);
}

void ov70_0223CD28(int value) {
    if (value != 0) {
        G2x_SetBlendBrightness_((vu16 *)0x04000050, 0xa, value);
    } else {
        *(vu16 *)0x04000050 = 0;
    }
}

int ov70_0223CD44(Ov70Work *work) {
    ov70_0223D3BC(work);
    *(vu16 *)0x04000304 &= 0xffff7fff;
    ov70_0223CE44(work->bgConfig);
    ov70_0223CF74(work);
    ov70_0223D26C(work);
    ov70_0223D058(work);
    ov70_02241358(work);
    if (GXx_GetMasterBrightness_((volatile u16 *)0x0400106C) == 0) {
        BeginNormalPaletteFade(3, 1, 1, 0, 6, 1, 0x3d);
    } else {
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x3d);
    }
    ov70_0223E264(work, work->field120);
    ov70_02245124(work);
    work->state2c = 0;
    return 2;
}

void ov70_0223CDD8(Ov70Work *work) {
    ov70_02238E44(work);
    sub_0203A930();
    ov70_022465A8[work->state2c](work);
}

int ov70_0223CDF8(Ov70Work *work) {
    sub_0203A914();
    if (GXx_GetMasterBrightness_((volatile u16 *)0x0400106C)) {
        ov70_02241380(work);
    }
    ov70_0223D208(work);
    ov70_0223D414(work);
    ov70_0223D378(work);
    ov70_0223CF48(work->bgConfig);
    Sprite_SetDrawFlag(work->spriteF10, 0);
    ov70_02238E58(work);
    return 1;
}

void ov70_0223CE44(void *bgConfig) {
    Ov70Gm graphicsModes;
    Ov70Bt template0;
    Ov70Bt template1;
    Ov70Bt template2;
    Ov70Bt template3;

    graphicsModes = ov70_022456F0;
    SetBothScreensModesAndDisable(&graphicsModes);
    GfGfx_EngineBTogglePlanes(0x16, 1);
    template0 = ov70_02245768;
    InitBgFromTemplate(bgConfig, 0, &template0, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 0);
    template1 = ov70_02245730;
    InitBgFromTemplate(bgConfig, 1, &template1, 0);
    template2 = ov70_0224574C;
    InitBgFromTemplate(bgConfig, 2, &template2, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    template3 = ov70_02245714;
    InitBgFromTemplate(bgConfig, 3, &template3, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
    ov70_022391F0(bgConfig, 0, 0);
    BG_ClearCharDataRange(0, 0x20, 0, 0x3d);
    BG_ClearCharDataRange(3, 0x20, 0, 0x3d);
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
}

void ov70_0223CF48(void *bgConfig) {
    ov70_022392BC(bgConfig);
    FreeBgTilemapBuffer(bgConfig, 2);
    FreeBgTilemapBuffer(bgConfig, 1);
    FreeBgTilemapBuffer(bgConfig, 0);
    FreeBgTilemapBuffer(bgConfig, 3);
}

void ov70_0223CF74(Ov70Work *work) {
    void *bgConfig = work->bgConfig;
    void *narc = NARC_New(0x64, 0x3d);

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 2, 0, 0, 0x60, 0x3d);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 5, 4, 0, 0x100, 0x3d);
    LoadFontPal1(0, 0x1a0, 0x3d);
    LoadUserFrameGfx2(bgConfig, 0, 1, 0xe, (u8)Options_GetFrame(work->unk00->unk24), 0x3d);
    LoadUserFrameGfx1(bgConfig, 0, 0x1f, 0xb, 0, 0x3d);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0xd, bgConfig, 1, 0, 0xa00, 1, 0x3d);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x1b, bgConfig, 1, 0, 0x600, 1, 0x3d);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x26, bgConfig, 2, 0, 0x600, 1, 0x3d);
    ov70_02239C6C(work);
    ov70_02239CF8(work);
    NARC_Delete(narc);
}
