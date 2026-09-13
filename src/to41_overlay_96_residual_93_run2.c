#include "to41_overlay_96_residual_93_private.h"

void ov96_022099EC(u8 *p) {
    s32 i;
    if (!p) {
        GF_AssertFail();
    }
    for (i = 0; i < 2; i++, p += 4) {
        if (!PTR(p, 0x24)) {
            GF_AssertFail();
        }
        Sprite_DeleteAndFreeResources(PTR(p, 0x24));
    }
}
