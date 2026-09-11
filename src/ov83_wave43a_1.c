#include "ov83_wave42_private.h"

void ov83_0223F804(void *bg) {
    SolModes modes;
    SolBgTemplate t1, t0, t2, t3, t4, t5, t6, t7;
    modes = ov83_02247D38;
    SetBothScreensModesAndDisable(&modes);
    t1 = ov83_02247DA0;
    InitBgFromTemplate(bg, 1, &t1, 0);
    BG_ClearCharDataRange(1, 0x20, 0, 0x6b);
    BgClearTilemapBufferAndCommit(bg, 1);
    t0 = ov83_02247DBC;
    InitBgFromTemplate(bg, 0, &t0, 0);
    BG_ClearCharDataRange(0, 0x20, 0, 0x6b);
    BgClearTilemapBufferAndCommit(bg, 0);
    t2 = ov83_02247DF4;
    InitBgFromTemplate(bg, 2, &t2, 0);
    BG_ClearCharDataRange(2, 0x20, 0, 0x6b);
    BgClearTilemapBufferAndCommit(bg, 2);
    t3 = ov83_02247E10;
    InitBgFromTemplate(bg, 3, &t3, 0);
    BG_ClearCharDataRange(3, 0x20, 0, 0x6b);
    BgClearTilemapBufferAndCommit(bg, 3);
    t4 = ov83_02247E2C;
    InitBgFromTemplate(bg, 4, &t4, 0);
    BgClearTilemapBufferAndCommit(bg, 4);
    t5 = ov83_02247E48;
    InitBgFromTemplate(bg, 5, &t5, 0);
    BG_ClearCharDataRange(5, 0x20, 0, 0x6b);
    BgClearTilemapBufferAndCommit(bg, 5);
    t6 = ov83_02247D84;
    InitBgFromTemplate(bg, 6, &t6, 0);
    BG_ClearCharDataRange(6, 0x20, 0, 0x6b);
    BgClearTilemapBufferAndCommit(bg, 6);
    t7 = ov83_02247DD8;
    InitBgFromTemplate(bg, 7, &t7, 0);
    BG_ClearCharDataRange(7, 0x20, 0, 0x6b);
    BgClearTilemapBufferAndCommit(bg, 7);
    G2_SetBG0Priority(0);
    GfGfx_EngineATogglePlanes(2, 1);
    GfGfx_EngineBTogglePlanes(4, 0);
    GfGfx_EngineBTogglePlanes(8, 0);
}
