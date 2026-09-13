#include "overlay89_r4_private.h"

void ov89_02259D50(void *data) {
    int i;
    Window *windows;

    RemoveWindow((Window *)((u8 *)data + 0xB4));
    windows = (Window *)((u8 *)data + 0x34);
    for (i = 0; i < 8; i++) {
        RemoveWindow(&windows[i]);
    }
}

void *ov89_02259D70(int heapId) {
    return GF_3DVramMan_Create(heapId, 0, 2, 0, 2, ov89_02259D8C);
}

void ov89_02259D8C(void) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, TRUE);
    G2_SetBG0Priority(1);
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(FALSE);
    G3X_SetFog(FALSE, GX_FOGBLEND_COLOR_ALPHA, GX_FOGSLOPE_0x8000, 0);
    G3X_SetClearColor(0, 0, 0x7FFF, 0x3F, FALSE);
    *(vu32 *)0x04000580 = 0xBFFF0000;
}
