#include "summary_screen_helpers_internal.h"

int sub_02089608(void *data) {
    u8 *p = data;
    if (*(const u32 *)(gSystem + 0x48) & 3) {
        u8 bits = p[0x7BE];
        u8 i = 0;
        do {
            u32 mask = 1 << i;
            if (bits & mask) {
                sub_0208DDA0(data, i);
                p[0x7BE] ^= mask;
                if (p[0x7BE] == 0) {
                    return 0x12;
                }
                break;
            }
            i = (u8)(i + 1);
        } while (i < 5);
    }
    return 0x11;
}

int sub_02089658(void) {
    if (*(const u32 *)(gSystem + 0x48) & 3) {
        return 0x15;
    }
    return 0x12;
}

int sub_02089670(void) {
    sub_020880CC(1, 0x13);
    return 0x16;
}

u8 sub_02089680(void) {
    return IsPaletteFadeFinished() == 1;
}
