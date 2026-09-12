#include "overlay70_graphics_lifecycle_private.h"

int ov70_02238FF4(Ov70R8 *work) {
    volatile u16 *power = (volatile u16 *)0x04000304;

    ov70_02239614(work);
    *power = *power & 0xffff7fff;
    ov70_02239134(work->bgConfig);
    ov70_02239330(work);
    ov70_022394B8(work);
    ov70_02239414(work);
    ov70_02245124(work);
    ov70_02239B00(work);
    Sound_SetSceneAndPlayBGM(0x17, 0x484, 1);
    if (work->initialized == 0) {
        ov70_02239304(work);
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x3d);
        work->state = 0;
        work->initialized = 1;
        ov70_02240EF4(work, PlayerProfile_GetTrainerGender(*(void **)((u8 *)work->root + 0x1c)));
    } else {
        if (work->mode11FC == 1 && GXx_GetMasterBrightness_((volatile u16 *)0x0400106c) != 0) {
            ov70_02241358(work);
            BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x3d);
        } else {
            BeginNormalPaletteFade(3, 1, 1, 0, 6, 1, 0x3d);
        }
        work->state = 5;
    }
    work->mode11FC = 0;
    return 2;
}

int ov70_022390DC(Ov70R8 *work) {
    ov70_02238E44(work);
    sub_0203A930();
    return ov70_02246464[work->state](work);
}

int ov70_022390FC(Ov70R8 *work) {
    sub_0203A914();
    ov70_022394A8(work);
    ov70_0223963C(work);
    ov70_022395C4(work);
    ov70_022392E0(work->bgConfig);
    Sprite_SetDrawFlag(work->spriteF10, 0);
    ov70_02238E58(work);
    return 1;
}

void ov70_02239134(void *bgConfig) {
    Ov70GraphicsModes8 modes;
    Ov70BgTemplate8 bg0;
    Ov70BgTemplate8 bg1;
    Ov70BgTemplate8 bg2;

    modes = ov70_0224525C;
    SetBothScreensModesAndDisable(&modes);
    bg0 = ov70_022452F4;
    InitBgFromTemplate(bgConfig, 0, &bg0, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 0);
    bg1 = ov70_022452D8;
    InitBgFromTemplate(bgConfig, 1, &bg1, 0);
    bg2 = ov70_02245310;
    InitBgFromTemplate(bgConfig, 2, &bg2, 0);
    ov70_022391F0(bgConfig, 0, 0);
    BG_ClearCharDataRange(0, 0x20, 0, 0x3d);
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
}

void ov70_022391F0(void *bgConfig, int value, int preserveBg6) {
    Ov70BgTemplate8 bg4;
    Ov70BgTemplate8 bg6;
    Ov70BgTemplate8 bg5;
    Ov70BgTemplate8 bg7;

    bg4 = ov70_022452A0;
    InitBgFromTemplate(bgConfig, 4, &bg4, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    bg6 = ov70_02245284;
    InitBgFromTemplate(bgConfig, 6, &bg6, 0);
    if (!preserveBg6) {
        BgClearTilemapBufferAndCommit(bgConfig, 6);
    }
    bg5 = ov70_022452BC;
    bg5.words[1] = value;
    InitBgFromTemplate(bgConfig, 5, &bg5, 0);
    BG_ClearCharDataRange(4, 0x20, 0, 0x3d);
    bg7 = ov70_0224532C;
    InitBgFromTemplate(bgConfig, 7, &bg7, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 7);
}
