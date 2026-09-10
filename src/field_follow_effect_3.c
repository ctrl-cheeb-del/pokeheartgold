#include "field_follow_effect_internal.h"

void ov01_022039BC(u32 dir, void *pos, void **out) {
    switch (dir) {
    case 0:
    case 1:
        *out = (u8 *)pos + 8;
        break;
    case 2:
    case 3:
        *out = pos;
        break;
    }
}

s32 ov01_022039E0(u32 dir) {
    switch (dir) {
    case 0:
        return -1;
    case 1:
        return 1;
    case 2:
        return -10;
    case 3:
        return 10;
    default:
        GF_AssertFail();
        return 0;
    }
}
