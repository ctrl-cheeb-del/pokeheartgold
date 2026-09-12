#include "overlay49_menu_graphics_private.h"

void ov49_0225A56C(void *work, u32 index) {
    u32 value;
    if (index >= 20) {
        GF_AssertFail();
    }
    value = ov45_0222AAC8(ov45_0222A578(PTR_AT(work, 0x34), index));
    ov49_022653C0(PTR_AT(work, 0x3D4), index, value);
    if (index == ov45_0222A53C(PTR_AT(work, 0x34))) {
        ov45_0222AD70(PTR_AT(work, 0x34), value);
    }
}

void ov49_0225A5AC(void *work, u32 index) {
    if (index >= 20) {
        GF_AssertFail();
    }
    ov49_022653F0(PTR_AT(work, 0x3D4), index);
}

void ov49_0225A5C8(void *work) {
    ov49_0225E3AC(PTR_AT(work, 0x3E4));
    ov49_02258BE0(PTR_AT(work, 0x3E0));
    ov49_0225A840(P_AT(work, 0x3C));
}
