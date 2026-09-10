#include "overlay68_helpers_internal.h"

void ov68_021E5CD8(BgConfig *bgConfig) {
    GfGfx_EngineBTogglePlanes(0x1d, 0);
    FreeBgTilemapBuffer(bgConfig, 7);
    FreeBgTilemapBuffer(bgConfig, 6);
    FreeBgTilemapBuffer(bgConfig, 4);
    FreeBgTilemapBuffer(bgConfig, 3);
    FreeBgTilemapBuffer(bgConfig, 2);
    Heap_FreeExplicit(HEAP_ID_66, bgConfig);
    reg_GX_POWCNT |= 0x8000;
}
