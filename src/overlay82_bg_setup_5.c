#include "overlay82_bg_setup_5_private.h"

void ov82_0223EC68(BgConfig *bgConfig) {
    GraphicsModes modes = ov82_0223FE28;
    SetBothScreensModesAndDisable(&modes);

    {
        BgTemplate bg = ov82_0223FE54;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_0, &bg, GF_BG_TYPE_TEXT);
        BG_ClearCharDataRange(GF_BG_LYR_MAIN_0, 0x20, 0, HEAP_ID_105);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_0);
    }

    {
        BgTemplate bg = ov82_0223FE70;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &bg, GF_BG_TYPE_TEXT);
        BG_ClearCharDataRange(GF_BG_LYR_MAIN_1, 0x20, 0, HEAP_ID_105);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    }

    {
        BgTemplate bg = ov82_0223FE8C;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);
    }

    {
        BgTemplate bg = ov82_0223FEA8;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    }

    {
        BgTemplate bg = ov82_0223FE38;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &bg, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    }

    G2_SetBG0Priority(0);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, TRUE);
}

void ov82_0223ED94(Ov82R5Work *work) {
    if (ov80_0223792C(work->mode) != FALSE) {
        vu32 *dispCnt = (vu32 *)0x04000000;

        *dispCnt &= 0xFFFF1FFF;
        G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, FALSE);
        G2_SetWndOutsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, TRUE);
        G2_SetWnd0Position(0xF0, 0, 0, 0x10);
        GX_SetVisibleWnd(GX_WNDMASK_W0);
    }
}

void ov82_0223EDF0(Ov82R5Work *work, u8 bgId) {
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 0x17, work->bgConfig, (GFBgLayer)bgId, 0, 0, TRUE, HEAP_ID_105);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 0x18, work->bgConfig, (GFBgLayer)bgId, 0, 0, TRUE, HEAP_ID_105);
}
