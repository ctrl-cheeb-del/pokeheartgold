#include "overlay14_box_navigation_private.h"

u32 ov14_021ED6D0(void *p) {
    u32 mode;

    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    ov14_021F2A18(PTR_AT(p, 0x34), 9, 0);
    ov14_021F5EB4(p, 0);
    ov14_021E8328(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    mode = U32_AT(PTR_AT(p, 0), 8);
    if (mode == 1) {
        ov14_021F6AC0(p, 2, 0x1e);
        return ov14_021F0234(p, ov14_021E95B4, 0x52);
    }
    if (mode == 3) {
        ov14_021F6AC0(p, 6, 0x1e);
    } else {
        ov14_021F6AC0(p, 3, 0x1e);
    }
    ov14_021E8248(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E82A8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E94BC, 0x4d);
}

u32 ov14_021ED760(void *p) {
    U8_AT(PTR_AT(p, 0x34), 0x44d) = ov14_021E7930(p, U8_AT(p, 0x25));
    ov14_021F4428(p);
    ov14_021F4530(p);
    ov14_021F459C(p);
    ov14_021F58B8(p);
    ov14_021E87BC(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021E81B4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9660, 0x40);
}

u32 ov14_021ED7B8(void *p) {
    ov14_021F6094(p);
    ov14_021E8560(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E95C8, 0x41);
}

u32 ov14_021ED7DC(void *p) {
    U32_AT(PTR_AT(p, 0x34), 0x43c) = U8_AT(PTR_AT(p, 0x34), 0x44d) % 4;
    ov14_021F6AC0(p, 0xa, U32_AT(PTR_AT(p, 0x34), 0x43c));
    ov14_021F29E4(PTR_AT(p, 0x34), 9, 0xe);
    ov14_021F6844(p, 1, 0x27);
    return 0x42;
}

u32 ov14_021ED820(void *p) {
    u32 input = GridInputHandler_HandleInput_AllowHold(PTR_AT(PTR_AT(p, 0x34), 0x2c));

    switch (input) {
    case 0:
        PlaySE(0x5dd);
        ov14_021F129C(p, 0);
        return 0x42;
    case 1:
        PlaySE(0x5dd);
        ov14_021F129C(p, 1);
        return 0x42;
    case 2:
        PlaySE(0x5dd);
        ov14_021F129C(p, 2);
        return 0x42;
    case 3:
        PlaySE(0x5dd);
        ov14_021F129C(p, 3);
        return 0x42;
    case 4:
        PlaySE(0x5dc);
        ov14_021F1228(p, -1);
        return 0x42;
    case 5:
        PlaySE(0x5dc);
        ov14_021F1228(p, 1);
        return 0x42;
    case 6:
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
        return ov14_021F131C(p);
    case -3:
        PlaySE(0x5dc);
        if (U32_AT(PTR_AT(p, 0x34), 8) != 0) {
            return ov14_021F0244(p, 0x49);
        }
        break;
    case 7:
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    case -2:
        PlaySE(0x5dc);
        return ov14_021F2270(p, 0xa, 0xa6);
    default:
        break;
    }
    return 0x42;
}

u32 ov14_021ED920(void *p) {
    ov14_021E8588(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E9604, 0x44);
}

u32 ov14_021ED940(void *p) {
    ov14_021E81D8(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    return ov14_021F0234(p, ov14_021E96A8, 0x45);
}
