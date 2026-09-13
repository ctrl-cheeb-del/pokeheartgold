#include "to41_overlay_74_thumb_private.h"

void *ov74_02231048(void) {
    return OV74_PTR(ov74_0223105C(), 0x20);
}

void *ov74_02231054(void) {
    return ov74_0223C920;
}

void *ov74_0223105C(void) {
    return ov74_0223D0C4;
}

u8 ov74_02231064(void) {
    return OV74_U8(ov74_0223105C(), 0);
}

void ov74_02231070(u8 value) {
    OV74_U8(ov74_0223105C(), 0) = value;
}

u8 ov74_0223107C(void) {
    return OV74_U8(ov74_0223105C(), 1);
}

void ov74_02231088(u8 value) {
    OV74_U8(ov74_0223105C(), 1) = value;
}

u8 ov74_02231094(void) {
    return OV74_U8(ov74_0223105C(), 2);
}

void ov74_022310A0(u8 value) {
    OV74_U8(ov74_0223105C(), 2) = value;
}

u8 ov74_022310AC(void) {
    return OV74_U8(ov74_0223105C(), 3);
}

void ov74_022310B8(u16 value) {
    OV74_U16(ov74_02231054(), 0x32) = value;
}

void *ov74_022310C4(void) {
    return OV74_PTR(ov74_0223105C(), 0x24);
}

void *ov74_022310D0(void) {
    return OV74_PTR(ov74_0223105C(), 0x2C);
}

void *ov74_022310DC(void) {
    return OV74_PTR(ov74_0223105C(), 0x30);
}

void *ov74_022310E8(void) {
    return OV74_PTR(ov74_0223105C(), 0x38);
}

void *ov74_022310F4(void) {
    return OV74_PTR(ov74_0223105C(), 0x3C);
}

void *ov74_02231100(void) {
    return OV74_PTR(ov74_0223105C(), 0x28);
}

void ov74_0223110C(u16 value) {
    OV74_U16(ov74_0223105C(), 0xC) = value;
}

void *ov74_02231118(void) {
    return OV74_PTR(ov74_0223105C(), 0x14);
}

void ov74_02231124(void *value) {
    OV74_PTR(ov74_0223105C(), 0x14) = value;
}

void ov74_02231130(void *value) {
    OV74_PTR(ov74_0223105C(), 0x18) = value;
}

void ov74_0223113C(void *value) {
    OV74_PTR(ov74_0223105C(), 0x20) = value;
}

void *ov74_02231148(void) {
    return (u8 *)ov74_0223105C() + 0x90;
}

void *ov74_02231154(void) {
    return ov74_02231148();
}

void *ov74_0223115C(void) {
    return ov74_02231148();
}
