#include "to41_overlay_96_residual_93_private.h"

void ov96_0220A0E0(u8 *p) {
    s32 i, j;
    u8 *w;
    u8 *q;
    for (i = 0, w = p + 0x54; i < 4; i++, w += 0x70) {
        if (!PTR(w, 4)) {
            GF_AssertFail();
        }
        Sprite_DeleteAndFreeResources(PTR(w, 4));
        if (!PTR(w, 8)) {
            GF_AssertFail();
        }
        Sprite_DeleteAndFreeResources(PTR(w, 8));
        for (j = 0, q = w; j < 0x14; j++, q += 4) {
            if (!PTR(q, 0xc)) {
                GF_AssertFail();
            }
            Sprite_DeleteAndFreeResources(PTR(q, 0xc));
        }
        q = 0;
        j = (s32)w;
        do {
            if (!PTR((u8 *)j, 0x5c)) {
                GF_AssertFail();
            }
            Sprite_DeleteAndFreeResources(PTR((u8 *)j, 0x5c));
            q++;
            j += 4;
        } while ((s32)q < 5);
    }
}
