#include "r40_overlay_45_thumb_residual_32_private.h"

u32 ov45_0222E5A0(void *p, u32 index) {
    if (*(u32 *)((u8 *)p + 8) <= index) {
        return 20;
    }
    return *(u16 *)((u8 *)p + 0x20 + index * 2);
}

BOOL ov45_0222E5B4(u32 kind, u32 value) {
    if (kind <= 1) {
        if (value < 1 || value > 4) {
            return FALSE;
        }
    } else {
        if (value < 2 || value > 4) {
            return FALSE;
        }
    }
    return TRUE;
}
