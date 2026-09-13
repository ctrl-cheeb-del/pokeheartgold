#include "r40_overlay_102_residual_13_private.h"

void ov102_021E93E0(void *unused, u8 *ctx) {
    volatile u32 *base = (volatile u32 *)0x027e0000;
    DoScheduledBgGpuUpdates(*(void **)(ctx + 0x20));
    SpriteList_RenderAndAnimateSprites(*(void **)(ctx + 0x24));
    OamManager_ApplyAndResetBuffers();
    base[0x3ff8 / 4] |= 1;
}
