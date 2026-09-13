#include "global.h"

#include "r40_overlay_45_thumb_residual_11_private.h"

int ov45_0222AA5C(void *p) {
    int r = ov45_0222CD04(*(u16 *)((u8 *)p + 0x3A));
    if (r == 0xFFFF) {
        if (ov45_0222A9CC(p) == 0) {
            return 3;
        }
        return 6;
    }
    return r;
}
