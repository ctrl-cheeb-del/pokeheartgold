#include "global.h"

#include "r40_overlay_103_residual_8_private.h"

#define APPLY_PALETTE(palette)                                                                                            \
    do {                                                                                                                  \
        if (!anim->isBg) {                                                                                                \
            ManagedSprite_SetPaletteOverride(*(void **)(work->ctx + 0x258 + anim->target * 4), (palette));                \
        } else {                                                                                                          \
            BgTilemapRectChangePalette(*(void **)work->ctx, anim->target, anim->x, anim->y, anim->w, anim->h, (palette)); \
            ScheduleBgTilemapBufferTransfer(*(void **)work->ctx, anim->target);                                           \
        }                                                                                                                 \
    } while (0)

BOOL ov103_021ED144(R40Ov103Work8 *work) {
    R40PalAnim *anim = (R40PalAnim *)(work->ctx + 0x2E4);
    switch (anim->state) {
    case 0:
        APPLY_PALETTE(anim->pal0);
        anim->state++;
        break;
    case 1:
        anim->timer++;
        if (anim->timer == 4) {
            APPLY_PALETTE(anim->pal1);
            anim->timer = 0;
            anim->state++;
        }
        break;
    case 2:
        anim->timer++;
        if (anim->timer == 2) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}
