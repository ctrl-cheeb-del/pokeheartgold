#include "overlay70_storage_ui_residual16_private.h"

int ov70_0223AA90(Ov70Work *work) {
    int ret = ov70_022464CC[work->state](work);
    int i = 0;
    u8 *walker = (u8 *)work;
    for (; i < 8; i++, walker += 4) {
        ov70_02238F9C(*(void **)(walker + 0xEE4), *(s16 *)(walker + 0x120C),
            work->offsetF14 + *(s16 *)(walker + 0x120E) + 0x20);
    }
    {
        void *sprite = work->spriteEE0;
        ov70_02238F9C(sprite, 0xD0, 0x3A - work->offsetF14);
    }
    ov70_02241330(work, work->selected, work->offsetF14);
    return ret;
}

int ov70_0223AB00(Ov70Work *work) {
    work->callback1208 = NULL;
    ov70_0223ACE4(work);
    ov70_0223AF30(work);
    ov70_0223AE40(work);
    ov70_0223ABD8(work->bgConfig);
    Sprite_SetDrawFlag(work->spriteF10, 0);
    ov70_02238E58(work);
    return 1;
}

void ov70_0223AB3C(void *bgConfig, int value) {
    Ov70BgTemplate high;
    Ov70BgTemplate low;
    high = ov70_022454D0;
    InitBgFromTemplate(bgConfig, 0, &high, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 0);
    low = ov70_022454B4;
    InitBgFromTemplate(bgConfig, 1, &low, 0);
    BG_ClearCharDataRange(0, 0x20, 0, 0x3D);
    if (GXx_GetMasterBrightness_((volatile u16 *)0x0400106C) == 0) {
        ov70_022391F0(bgConfig, value, 1);
    } else {
        ov70_022391F0(bgConfig, value, 0);
    }
    GfGfx_EngineATogglePlanes(4, 0);
    GfGfx_EngineATogglePlanes(8, 0);
}
