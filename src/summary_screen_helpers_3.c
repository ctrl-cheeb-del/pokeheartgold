#include "summary_screen_helpers_internal.h"

void sub_0208877C(BgConfig *bg) {
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    FreeBgTilemapBuffer(bg, 6);
    FreeBgTilemapBuffer(bg, 5);
    FreeBgTilemapBuffer(bg, 4);
    FreeBgTilemapBuffer(bg, 3);
    FreeBgTilemapBuffer(bg, 2);
    FreeBgTilemapBuffer(bg, 1);
    Heap_FreeExplicit(0x13, bg);
}
