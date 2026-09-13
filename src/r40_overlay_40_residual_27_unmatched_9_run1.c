#include "r40_overlay_40_residual_27_unmatched_9_private.h"

void ov40_02233044(void *work) {
    u8 *raw = work;
    u8 *inner = *(u8 **)(raw + 0x860);
    ov40_0222D6EC(work, 2);
    *(void **)(inner + 0x15c) = ov40_0222D800(work, 2);
    ov40_0222D5AC(inner + 0x158, raw + 0x14, 2);
    ov40_0222D66C(inner + 0x158, raw + 0x14, 3);
    ManagedSprite_SetAnim(*(void **)(inner + 0x15c), 0);
    ManagedSprite_SetPositionXY(*(void **)(inner + 0x15c), 0x50, 0xe8);
    sub_020136B4(*(void **)(inner + 0x160), 0x24, -8);
    TextOBJ_SetSpritesDrawFlag(*(void **)(inner + 0x160), 1);
}
