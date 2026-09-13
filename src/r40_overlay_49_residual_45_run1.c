#include "r40_overlay_49_residual_45_private.h"

void ov49_0225D57C(s32 *value, void *angle, s32 amount) {
    s32 limit = sub_020181A4(angle);
    s32 next = *value + amount;

    if (next < limit) {
        *value = next;
    } else {
        *value = next % limit;
    }
}

BOOL ov49_0225D5A0(s32 *value, void *angle, s32 amount) {
    s32 limit = sub_020181A4(angle);
    s32 next = *value + amount;

    if (next < limit) {
        *value = next;
        return FALSE;
    }
    *value = limit - 0x800;
    return TRUE;
}

void ov49_0225D5C8(s32 *value, void *angle, s32 amount) {
    s32 limit = sub_020181A4(angle);
    s32 next = *value - amount;

    if (next >= 0) {
        *value = next;
    } else {
        *value = limit + next;
    }
}
