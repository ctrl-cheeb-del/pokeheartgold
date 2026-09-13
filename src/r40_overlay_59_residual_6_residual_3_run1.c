#include "r40_overlay_59_residual_6_residual_3_private.h"

void ov59_02239428(Ov59Work *work) {
    ov59_02239408(work);
    work->bgConfig = BgConfig_Alloc(work->heapId);
    {
        GraphicsModes modes = ov59_0223C658;
        SetBothScreensModesAndDisable(&modes);
    }
    *(vu16 *)0x04000304 &= 0xFFFF7FFF;
    {
        BgTemplate t = ov59_0223C718;
        InitBgFromTemplate(work->bgConfig, 4, &t, 0);
    }
    BgClearTilemapBufferAndCommit(work->bgConfig, 4);
    {
        BgTemplate t = ov59_0223C68C;
        InitBgFromTemplate(work->bgConfig, 7, &t, 0);
    }
    BgClearTilemapBufferAndCommit(work->bgConfig, 7);
    {
        BgTemplate t = ov59_0223C6A8;
        InitBgFromTemplate(work->bgConfig, 0, &t, 0);
    }
    BgClearTilemapBufferAndCommit(work->bgConfig, 0);
    {
        BgTemplate t = ov59_0223C6FC;
        InitBgFromTemplate(work->bgConfig, 1, &t, 0);
    }
    BgClearTilemapBufferAndCommit(work->bgConfig, 1);
    {
        BgTemplate t = ov59_0223C734;
        InitBgFromTemplate(work->bgConfig, 2, &t, 0);
    }
    BgClearTilemapBufferAndCommit(work->bgConfig, 2);
    {
        BgTemplate t = ov59_0223C6E0;
        InitBgFromTemplate(work->bgConfig, 3, &t, 0);
    }
    BgClearTilemapBufferAndCommit(work->bgConfig, 3);
    BG_ClearCharDataRange(4, 0x20, 0, work->heapId);
    BG_ClearCharDataRange(7, 0x20, 0, work->heapId);
    BG_ClearCharDataRange(0, 0x20, 0, work->heapId);
    BG_ClearCharDataRange(1, 0x20, 0, work->heapId);
    BG_ClearCharDataRange(2, 0x20, 0, work->heapId);
    BG_ClearCharDataRange(3, 0x40, 0, work->heapId);
}
