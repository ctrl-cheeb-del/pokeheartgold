#include "to46_overlay108_gap06_private.h"

int ov108_021E9528(void *arg, u32 selection) {
    u8 result;

    if (selection >= 6) {
        PlaySE(0x5DC);
        ov108_021E9F20(arg, 1);
        U32(arg, 0xC) = 3;
        return 3;
    }

    U8(arg, 0x432) = U8(arg, 0x431) + 6 * U8(arg, 0x430);
    if (U8(arg, 0x432) >= U8(arg, 0x42D)) {
        return 0;
    }

    result = ov108_021EA52C(arg, U8(arg, 0x432));
    if (result != 0) {
        PlaySE(0x5F3);
        ov108_021EA418(arg, result - 1);
        return 2;
    }

    PlaySE(0x5DC);
    U8(arg, 0x433) = U8(PTR(arg, 0x334), U8(arg, 0x432) * 5);
    return 1;
}
