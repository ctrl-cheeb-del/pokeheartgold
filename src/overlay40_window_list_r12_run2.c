#include "overlay40_window_list_r12_private.h"

void ov40_0222F6D0(void *p, s16 value) {
    s16 old = OV40_S16(p, 8);
    OV40_S16(p, 8) += value;
    if (OV40_S16(p, 8) < 0) {
        OV40_S16(p, 8) = 0;
    }
    if (OV40_S32(p, 0x10) == OV40_S32(p, 4)) {
        OV40_S16(p, 8) = 0;
    }
    if (OV40_S16(p, 8) + OV40_S32(p, 0x10) > OV40_S32(p, 4)) {
        OV40_S16(p, 8) = OV40_S32(p, 4) - OV40_S32(p, 0x10);
    }
    if (old != OV40_S16(p, 8)) {
        PlaySE(0x572);
    }
    ov40_0222F878(p);
}
