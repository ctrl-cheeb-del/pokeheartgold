#include "global.h"

#include "r40_overlay_83_residual_16_private.h"

void ov83_0224143C(void *p, u16 value, u16 other) {
    *(u16 *)((u8 *)p + 0x7AC) = value;
    *(u16 *)((u8 *)p + 0x7AE) = other;
    if (sub_0203769C() == 0 && *((u8 *)p + 0x12) == 0xFF) {
        *((u8 *)p + 0x12) = other;
    }
    *(u16 *)((u8 *)p + 0x7B0) = *((u8 *)p + 0x12);
    *(u16 *)((u8 *)p + 0x7B4) = *(u16 *)((u8 *)p + 0x10);
    *(u16 *)((u8 *)p + 0x7B6) = *((u8 *)p + 0x13);
}
