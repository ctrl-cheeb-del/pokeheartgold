#include "global.h"

#include "r40_overlay_83_residual_31_private.h"

void ov83_0224517C(void *p, u16 value, u16 other) {
    *(u16 *)((u8 *)p + 0x564) = value;
    *(u16 *)((u8 *)p + 0x566) = other;
    if (sub_0203769C() == 0 && *((u8 *)p + 0x11) == 0xFF) {
        *((u8 *)p + 0x11) = other;
    }
    *(u16 *)((u8 *)p + 0x568) = *((u8 *)p + 0x11);
    *(u16 *)((u8 *)p + 0x56C) = *((u8 *)p + 0x12);
    *(u16 *)((u8 *)p + 0x56E) = *((u8 *)p + 0x13);
}
