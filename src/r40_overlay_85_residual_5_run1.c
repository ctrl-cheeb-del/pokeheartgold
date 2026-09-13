#include "r40_overlay_85_residual_5_private.h"

int ov85_021E5EB4(u8 *ctx) {
    int i = 0;
    int complete = 0;
    int count = *(int *)(ctx + 0x30);
    u8 *entry = ctx + 0x190;
    do {
        if (*(int *)(entry + 0x148) == 1) {
            complete++;
        }
        i++;
        entry += 0xb0;
    } while (i < count);
    if (complete == count) {
        *(int *)ctx = 0x13;
        return 1;
    }
    return 0;
}

int ov85_021E5EE8(u8 *ctx) {
    if (++*(int *)(ctx + 0xc) > 30) {
        *(int *)(ctx + 0xc) = 0;
        if (sub_0203769C() == 0) {
            *(int *)ctx = 0x14;
        } else {
            *(int *)ctx = 0x15;
        }
    }
    return 0;
}
