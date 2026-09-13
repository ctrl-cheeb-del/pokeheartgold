#include "r40_overlay_96_residual_46_private.h"

void ov96_021EEECC(void) {
    GraphicsBanks banks = ov96_0221B9E8;
    GfGfx_SetBanks(&banks);
}

void ov96_021EEEEC(void *work) {
    volatile u32 *base = (volatile u32 *)0x027e0000;
    DoScheduledBgGpuUpdates(PTR(work, 4));
    base[0x3ff8 / 4] |= 1;
}

void ov96_021EEF0C(BgConfig *bgConfig, enum HeapID heapId) {
    GraphicsModes modes = ov96_0221B9BC;
    SetBothScreensModesAndDisable(&modes);
    {
        BgTemplate template = ov96_0221B9CC;
        InitBgFromTemplate(bgConfig, 0, &template, 0);
        BgClearTilemapBufferAndCommit(bgConfig, 0);
        BG_ClearCharDataRange(0, 0x40, 0, heapId);
        GfGfx_EngineATogglePlanes(8, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(2, 0);
        GfGfx_EngineATogglePlanes(1, 1);
        BG_SetMaskColor(0, 0);
        BG_SetMaskColor(4, 0);
    }
}
