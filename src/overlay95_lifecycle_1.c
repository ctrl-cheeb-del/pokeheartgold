#include "overlay95_lifecycle_internal.h"

void ov95_021E5954(void) {
    GF_3DVramMan_Create(0x46, 0, 2, 0, 2, ov95_021E5974);
}

void ov95_021E5974(void) {
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, 1);
    G2_SetBG0Priority(1);
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(FALSE);
    G3X_SetFog(FALSE, GX_FOGBLEND_COLOR_ALPHA, GX_FOGSLOPE_0x8000, 0);
    G3X_SetClearColor(0, 0, 0x7FFF, 0x3F, FALSE);
    G3_ViewPort(0, 0, 255, 191);
}

void ov95_021E59F8(void) {
    u32 tex = NNS_GfdDefaultFuncAllocTexVram(0x8000, FALSE, 0);
    u32 pltt = NNS_GfdDefaultFuncAllocPlttVram(0x80, FALSE, 0);
    if (tex == 0) {
        GF_AssertFail();
    }
    if (pltt == 0) {
        GF_AssertFail();
    }
    sub_02014DA0();
}

void ov95_021E5A38(void *bgConfig) {
    GraphicsBanks banks;
    GraphicsModes modes;
    Ov95BgTemplates templates;

    GfGfx_DisableEngineAPlanes();
    banks = ov95_021E75B4;
    GfGfx_SetBanks(&banks);
    MI_CpuClear32((void *)0x06000000, 0x80000);
    MI_CpuClear32((void *)0x06200000, 0x20000);
    MI_CpuClear32((void *)0x06400000, 0x40000);
    MI_CpuClear32((void *)0x06600000, 0x20000);
    modes = ov95_021E7538;
    SetBothScreensModesAndDisable(&modes);
    templates = ov95_021E767C;
    InitBgFromTemplate(bgConfig, 1, &templates.item[0], 0);
    InitBgFromTemplate(bgConfig, 2, &templates.item[1], 0);
    InitBgFromTemplate(bgConfig, 3, &templates.item[2], 0);
    BgClearTilemapBufferAndCommit(bgConfig, 1);
    BgClearTilemapBufferAndCommit(bgConfig, 2);
    BgClearTilemapBufferAndCommit(bgConfig, 3);
    G2_SetBG0Priority(1);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, 1);
    GfGfx_BothDispOn();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, 1);
}
