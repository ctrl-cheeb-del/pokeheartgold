#include "overlay102_graphics_r14_private.h"

#define PTR(base, off) (*(void **)((u8 *)(base) + (off)))
#define U32(base, off) (*(u32 *)((u8 *)(base) + (off)))

void ov102_021E978C(void *state) {
    int i;
    u8 *work = PTR(state, 0);

    *(volatile u16 *)0x04000304 &= 0xFFFF7FFF;
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    GfGfx_SetBanks(ov102_021EC760);
    SetBothScreensModesAndDisable(ov102_021EC6A8);
    InitBgFromTemplate(PTR(work, 0x20), 0, ov102_021EC728, 0);
    InitBgFromTemplate(PTR(work, 0x20), 1, ov102_021EC6D4, 0);
    InitBgFromTemplate(PTR(work, 0x20), 2, ov102_021EC6B8, 0);
    InitBgFromTemplate(PTR(work, 0x20), 3, ov102_021EC70C, 0);
    InitBgFromTemplate(PTR(work, 0x20), 4, ov102_021EC744, 0);
    InitBgFromTemplate(PTR(work, 0x20), 5, ov102_021EC6F0, 0);
    for (i = 0; i < 6; i++) {
        BgClearTilemapBufferAndCommit(PTR(work, 0x20), i);
    }
    FontID_Alloc(2, 0x23);
}

void ov102_021E983C(void *task, void *state) {
#pragma unused(task)
    u8 *p = state;

    switch (U32(p, 0x14)) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0, 5, 1, 0x23);
        U32(p, 0x14)
        ++;
        return;
    case 1:
        if (IsPaletteFadeFinished()) {
            U32(p, 0x14)
            ++;
        }
        return;
    default:
        ov102_021E94A4(p);
        return;
    }
}
