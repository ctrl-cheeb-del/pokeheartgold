#include "to41_overlay_96_residual_93_private.h"

void ov96_02209BB0(u8 *p) {
    s32 i;
    u16 v;
    if (!p) {
        GF_AssertFail();
    }
    v = ov96_0220AD4C(PTR(p, 0x40));
    for (i = 0; i < 3; i++) {
        Sprite_SetAnimCtrlSeq(PTR((u8 *)p + ((2 - i) << 2), 0x2c), (u16)(v % 10) + 1);
        if (v < 10) {
            break;
        }
        v = (u16)(v / 10);
    }
}

void ov96_02209BF8(u8 *p) {
    s32 i;
    for (i = 0; i < 2; i++, p += 4) {
        ManagedSprite_SetAnimateFlag(PTR(p, 0x24), 0);
    }
}
