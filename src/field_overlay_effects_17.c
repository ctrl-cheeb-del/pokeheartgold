#include "field_overlay_effects_internal.h"

void ov01_021F1210(void *p) {
    void *bg = *(void **)((u8 *)p + 8);
    FreeBgTilemapBuffer(bg, 2);
    Thunk_BgConfig_Init(*(void **)((u8 *)p + 8));
}
