#include "r40_overlay_40_residual_27_unmatched_10_private.h"

void ov40_0223316C(void *work) {
    u8 *p = work;
    u8 *inner = *(u8 **)(p + 0x860);
    ov40_0223311C(work, 2);
    *(void **)(inner + 0xbc) = ov40_0222D800(work, 2);
    ov40_0222D5AC(inner + 0xb8, p + 0x14, 2);
    ov40_0222D66C(inner + 0xb8, p + 0x14, 3);
    ManagedSprite_SetPositionXY(*(void **)(inner + 0xbc), 0x80, 0xe8);
    sub_020136B4(*(void **)(inner + 0xc0), 0x24, -8);
    TextOBJ_SetSpritesDrawFlag(*(void **)(inner + 0xc0), 1);
    *(void **)(inner + 0x98) = ov40_0222D800(work, 2);
    ManagedSprite_SetPositionXY(*(void **)(inner + 0x98), 0xdc, 0xe0);
    ManagedSprite_SetAnim(*(void **)(inner + 0x98), 2);
    ManagedSprite_SetDrawFlag(*(void **)(inner + 0x98), 0);
    ov40_022330E0(work, 1);
}
