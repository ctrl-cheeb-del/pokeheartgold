#include "r40_overlay_72_residual_10_private.h"

int ov72_02239198(void *p) {
    int result = ov72_0223AF48((u8 *)p + 0x136C);
    if (result != 0) {
        if (result == 2) {
            if (ov00_021EC5B4() == 0) {
                U32(p, 0x1C) = 0;
            } else {
                U32(p, 0x1C) = 0x29;
            }
        } else {
            if (ov00_021EC5B4() == 0) {
                ov72_022387D0(p, 0, 0);
                U32(p, 0x1C) = 0x2E;
            } else {
                U32(p, 0x1C) = 0x29;
            }
            U32(PTR(p, 0), 0x20) = 1;
        }
    }
    return 3;
}

int ov72_022391E8(void *p) {
    sub_02039418(PTR(PTR(p, 0), 0xC));
    Sys_SetSleepDisableFlag(4);
    ov72_0223A414(p);
    ov00_021EC3F0((u8 *)p + 0x2C, 2, 1, 0x14);
    ov00_021EC454(2);
    ov00_021EC4A4();
    U32(p, 0x1C) = 3;
    return 3;
}

int ov72_02239220(void *p) {
    u8 buf[0x44];
    ov00_021EC60C();
    if (ov00_021EC5B4() != 0) {
        switch (ov00_021EC724()) {
        case 7:
            PTR(p, 0xF50) = ov00_021EC0FC(buf + 4);
            U32(p, 0xF54) = U32(buf, 4);
            ov00_021EC210();
            ov00_021EC8D8();
            ov72_0223A444(p);
            U32(p, 0x1C) = 0x37;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 8:
        default:
            ov00_021EC0FC(buf);
            ov72_0223A444(p);
            U32(p, 0x1C) = 0x35;
            U32(p, 0xF5C) = -2;
            break;
        case 4:
            ov00_021EC9E0(buf + 8);
            U32(p, 0x1C) = 4;
            break;
        }
    }
done:
    return 3;
}
