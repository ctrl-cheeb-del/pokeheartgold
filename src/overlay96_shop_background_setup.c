#include "overlay96_shop_transition_private.h"

void ov96_021F0BD4(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate t0;
    BgTemplate t1;
    BgTemplate t2;
    BgTemplate t3;
    BgTemplate t4;
    BgTemplate t5;
    BgTemplate t7;
    BgTemplate t6;

    modes = ov96_0221BC7C;
    SetBothScreensModesAndDisable(&modes);
    t0 = ov96_0221BCE8;
    InitBgFromTemplate(bgConfig, 0, &t0, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 0);
    t1 = ov96_0221BD04;
    InitBgFromTemplate(bgConfig, 1, &t1, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    t2 = ov96_0221BD3C;
    InitBgFromTemplate(bgConfig, 2, &t2, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    t3 = ov96_0221BD58;
    InitBgFromTemplate(bgConfig, 3, &t3, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
    t4 = ov96_0221BD74;
    InitBgFromTemplate(bgConfig, 4, &t4, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    t5 = ov96_0221BD90;
    InitBgFromTemplate(bgConfig, 5, &t5, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 5);
    t7 = ov96_0221BCCC;
    InitBgFromTemplate(bgConfig, 7, &t7, 1);
    BgClearTilemapBufferAndCommit(bgConfig, 7);
    t6 = ov96_0221BD20;
    InitBgFromTemplate(bgConfig, 6, &t6, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 6);
    GfGfx_EngineATogglePlanes(8, 0);
}
