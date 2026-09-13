#include "to41_overlay_74_thumb_private.h"

void *ov74_02231184(void) {
    return (u8 *)ov74_0223105C() + 0x254;
}

void ov74_02231194(void) {
    OV74_U8(ov74_02231184(), 0x18) = 0;
}

void *ov74_022311A0(void) {
    return OV74_PTR(ov74_0223105C(), 4);
}

u8 ov74_022311AC(void) {
    return OV74_U32(ov74_0223105C(), 0x40);
}

u32 ov74_022311BC(void) {
    return (OV74_U32(ov74_0223105C(), 0x40) << 20) >> 28;
}

u32 ov74_022311CC(void) {
    return OV74_U32(ov74_0223105C(), 0x44) >> 16;
}

u32 ov74_022311D8(void) {
    return 0x38;
}

void *ov74_022311DC(void) {
    return (u8 *)ov74_0223105C() + 0x40;
}

void *ov74_022311E8(void) {
    return (u8 *)ov74_0223105C() + 0x78;
}
