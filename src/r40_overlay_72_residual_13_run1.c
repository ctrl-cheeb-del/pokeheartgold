#include "r40_overlay_72_residual_13_private.h"

int ov72_02239638(void *p) {
    int value;

    if (ov72_02237B54(p)) {
        value = ov72_02237B74();
        U32(p, 0xFD4) = 0;
        switch (value) {
        case -1:
            U32(p, 0xF5C) = value;
            U32(p, 0x1C) = 0x35;
            break;
        case -2:
            U32(p, 0xF5C) = value;
            U32(p, 0x1C) = 0x35;
            break;
        case -3:
            U32(p, 0xF5C) = value;
            U32(p, 0x1C) = 0x35;
            break;
        case -6:
            U32(p, 0xF5C) = value;
            U32(p, 0x1C) = 0x35;
            break;
        case -7:
        case -4:
            U32(p, 0xF5C) = value;
            U32(p, 0x1C) = 0x35;
            break;
        case -5:
            U32(p, 0xF5C) = value;
            U32(p, 0x1C) = 0x35;
            ov72_0223A444(p);
            sub_020399EC();
            break;
        default:
            if (value > 0) {
                U32(p, 0x98) = value;
                U32(p, 0x1C) = U32(p, 0x20);
            }
            break;
        }
        ov72_0223A444(p);
    } else {
        U32(p, 0xFD4)
        ++;
        if (U32(p, 0xFD4) == 0xE10) {
            sub_020399EC();
        }
    }
    return 3;
}

int ov72_022396E8(void *p) {
    int value = U32(p, 0x98);

    if (value >= 100) {
        BufferIntegerAsString(PTR(p, 0xBD0), 0, value, 3, 2, 1);
        ov72_0223A280(p, PTR(p, 0xBD4), 0xB, 1, 0xF0F);
    } else {
        BufferIntegerAsString(PTR(p, 0xBD0), 0, value, 2, 2, 1);
        ov72_0223A280(p, PTR(p, 0xBD4), 0, 1, 0xF0F);
    }
    ov72_02238680(p, 0x2F, 0xE);
    return 3;
}

int ov72_02239760(void *p) {
    ov72_0223A520(p, 1, U32(p, 0x98));
    U32(p, 0x1C) = 0xF;
    ov72_0223A41C(p, 0, 1);
    return 3;
}

int ov72_02239784(void *p) {
    u8 b[12];
    u8 a[16];
    int value = ov72_0223A588(p);

    if (value != 0) {
        if (value > 0) {
            ov00_021ECB94(a, b);
            U32(p, 0x9C) = value;
            if (sub_0202D720(PTR(PTR(p, 0), 4), U32(p, 0x94), U32(p, 0x9C), a)) {
                U32(p, 0x1C) = 0x14;
            } else {
                U32(p, 0x1C) = 0x10;
            }
        } else {
            ov72_0223A41C(p, 0, 0);
            U32(p, 0x1C) = 0x15;
        }
    }
    return 3;
}

int ov72_022397E8(void *p) {
    BufferIntegerAsString(PTR(p, 0xBD0), 0, U32(p, 0x9C), 3, 2, 1);
    BufferIntegerAsString(PTR(p, 0xBD0), 1, U32(p, 0x94), 2, 2, 1);
    ov72_0223A280(p, PTR(p, 0xBD4), 1, 1, 0xF0F);
    ov72_02238680(p, 0x2F, 0x11);
    MIi_CpuClearFast(0, (u32 *)((u8 *)p + 0xA0), 0xA38);
    return 3;
}
