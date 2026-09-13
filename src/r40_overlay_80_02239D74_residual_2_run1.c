#include "r40_overlay_80_02239D74_residual_2_private.h"

void ov80_02239ED8(void *task, TileTask *work) {
    if (work->timer < 12) {
        work->timer++;
        return;
    }
    work->timer = 0;
    BG_LoadCharTilesData(work->bgConfig, 3, work->chars + (work->index << 16), 0x10000, 0);
    BG_LoadScreenTilemapData(work->bgConfig, 3, work->screens + (work->index << 12), 0x1000);
    ScheduleBgTilemapBufferTransfer(work->bgConfig, 3);
    work->index ^= 1;
}
