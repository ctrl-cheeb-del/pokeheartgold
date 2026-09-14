#include "to45_overlay96_r58_gap2_private.h"

void ov96_021F480C(Ov96R58Work *work, BgConfig *bgConfig) {
    u8 i;

    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG0, TRUE);
    for (i = 0; i < 2; i++) {
        ov96_021EB52C(work->spritesBC[i], TRUE, TRUE);
    }
    for (i = 0; i < 4; i++) {
        ov96_021EB52C(work->spritesC8[i], TRUE, TRUE);
    }
    BG_LoadScreenTilemapData(bgConfig, GF_BG_LYR_SUB_2, work->resourceA4->data, work->resourceA4->size);
    ov96_021F4EF8(work, bgConfig);
    BgTilemapRectChangePalette(bgConfig, GF_BG_LYR_SUB_2, 0, 0, 0x20, 0x18, 3);
    ScheduleBgTilemapBufferTransfer(bgConfig, GF_BG_LYR_SUB_2);
    work->callback = ov96_021F4A9C;
    work->phase = 1;
    work->state = 1;
}

void ov96_021F48A8(Ov96R58Work *work, BgConfig *bgConfig, int arg2) {
    ov96_021F4E5C(work, arg2);
    BG_LoadScreenTilemapData(bgConfig, GF_BG_LYR_SUB_2, work->resourceAC->data, work->resourceAC->size);
    BgTilemapRectChangePalette(bgConfig, GF_BG_LYR_SUB_2, 0, 0, 0x20, 0x20, 3);
    ScheduleBgTilemapBufferTransfer(bgConfig, GF_BG_LYR_SUB_2);
    work->callback = ov96_021F4AE0;
    work->phase = 2;
    work->state = 1;
}

void ov96_021F48FC(Ov96R58Work *work, BgConfig *bgConfig) {
    MtxFx22 matrix;

    ov96_021F4CAC(work);
    matrix._00 = FX32_ONE;
    matrix._01 = 0;
    matrix._10 = 0;
    matrix._11 = FX32_ONE;
    OS_WaitVBlankIntr();
    SetBgAffine(bgConfig, GF_BG_LYR_SUB_3, &matrix, 0x80, 0x60);
    BG_LoadScreenTilemapData(bgConfig, GF_BG_LYR_SUB_2, work->resourceA8->data, work->resourceA8->size);
    BgTilemapRectChangePalette(bgConfig, GF_BG_LYR_SUB_2, 0, 0, 0x20, 0x18, 3);
    ScheduleBgTilemapBufferTransfer(bgConfig, GF_BG_LYR_SUB_2);
    BG_LoadScreenTilemapData(bgConfig, GF_BG_LYR_SUB_3, work->resource9C->data, work->resource9C->size);
    ScheduleBgTilemapBufferTransfer(bgConfig, GF_BG_LYR_SUB_3);
    work->callback = ov96_021F4B34;
    work->phase = 3;
    work->state = 1;
}
