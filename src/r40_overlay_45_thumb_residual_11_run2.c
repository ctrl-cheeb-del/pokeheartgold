#include "global.h"

#include "r40_overlay_45_thumb_residual_11_private.h"

u8 ov45_0222AAC8(void *p) {
    u8 v = *((u8 *)p + 0x41);
    if (v == 0xFF) {
        return 0;
    }
    if (v >= 0x1B) {
        return 0;
    }
    return v;
}

BOOL ov45_0222AADC(void *p) {
    return *((u8 *)p + 0x41) == 0xFF ? FALSE : TRUE;
}
