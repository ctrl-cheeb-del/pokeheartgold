#include "overlay40_pc_box_grid_private.h"

void ov40_02230D20(void *p) {
    switch (S32(p, 0x514)) {
    case 0:
        if (S32(p, 0x518) < 8) {
            S32(p, 0x518) = S32(p, 0x518) + 1;
        } else {
            ov40_0222DED0(p, S32(p, 0x510));
            S32(p, 0x514) = S32(p, 0x514) + 1;
        }
        break;
    case 1:
        if (System_GetTouchNew()) {
            ov40_0222DFB0(p);
            S32(p, 0x514) = S32(p, 0x514) + 1;
        }
        break;
    default:
        if (S32(p, 0x518) > 0) {
            S32(p, 0x518) = S32(p, 0x518) - 1;
        } else {
            WORD(PTR(p, 0x10), 0) = WORD(p, 0x50C);
        }
        break;
    }
}
