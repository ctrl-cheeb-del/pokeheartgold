#include "summary_graphics_init_internal.h"

void sub_02088630(BgConfig *bgConfig) {
    GraphicsModes modes;
    BgTemplate bg1;
    BgTemplate bg2;
    BgTemplate bg3;
    BgTemplate bg4;
    BgTemplate bg5;
    BgTemplate bg6;

    modes = _021038C4;
    SetBothScreensModesAndDisable(&modes);
    bg1 = _021038E8;
    InitBgFromTemplate(bgConfig, 1, &bg1, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    bg2 = _02103904;
    InitBgFromTemplate(bgConfig, 2, &bg2, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    ScheduleSetBgPosText(bgConfig, 2, BG_POS_OP_SET_X, 0);
    ScheduleSetBgPosText(bgConfig, 2, BG_POS_OP_SET_Y, 0);
    bg3 = _02103920;
    InitBgFromTemplate(bgConfig, 3, &bg3, GF_BG_TYPE_TEXT);
    bg4 = _0210393C;
    InitBgFromTemplate(bgConfig, 4, &bg4, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
    bg5 = _02103958;
    InitBgFromTemplate(bgConfig, 5, &bg5, GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, 5);
    bg6 = _02103974;
    InitBgFromTemplate(bgConfig, 6, &bg6, GF_BG_TYPE_TEXT);
    BG_ClearCharDataRange(1, 0x20, 0, HEAP_ID_19);
    BG_ClearCharDataRange(4, 0x20, 0, HEAP_ID_19);
}
