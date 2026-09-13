#include "r40_overlay_81_residual_4_middle_private.h"

void ov81_02240230(BgConfig *bg) {
    {
        GraphicsModes m = ov81_02243480;
        SetBothScreensModesAndDisable(&m);
    }
    {
        BgTemplate t = ov81_022434A8;
        InitBgFromTemplate(bg, 1, &t, 0);
    }
    BG_ClearCharDataRange(1, 0x20, 0, (enum HeapID)0x64);
    BgClearTilemapBufferAndCommit(bg, 1);
    {
        BgTemplate t = ov81_022434C4;
        InitBgFromTemplate(bg, 2, &t, 0);
    }
    BgClearTilemapBufferAndCommit(bg, 2);
    {
        BgTemplate t = ov81_022434FC;
        InitBgFromTemplate(bg, 3, &t, 0);
    }
    BgClearTilemapBufferAndCommit(bg, 3);
    {
        BgTemplate t = ov81_02243518;
        InitBgFromTemplate(bg, 4, &t, 0);
    }
    BG_ClearCharDataRange(4, 0x20, 0, (enum HeapID)0x64);
    BgClearTilemapBufferAndCommit(bg, 4);
    {
        BgTemplate t = ov81_022434E0;
        InitBgFromTemplate(bg, 5, &t, 0);
    }
    BG_ClearCharDataRange(5, 0x20, 0, (enum HeapID)0x64);
    BgClearTilemapBufferAndCommit(bg, 5);
    {
        BgTemplate t = ov81_02243534;
        InitBgFromTemplate(bg, 6, &t, 0);
    }
    BgClearTilemapBufferAndCommit(bg, 6);
    {
        BgTemplate t = ov81_02243550;
        InitBgFromTemplate(bg, 7, &t, 0);
    }
    BgClearTilemapBufferAndCommit(bg, 7);
    {
        u16 *reg = (u16 *)0x04000008;
        u16 value = *reg;
        value &= ~3;
        *reg = value;
    }
    GfGfx_EngineATogglePlanes(1, 1);
}
