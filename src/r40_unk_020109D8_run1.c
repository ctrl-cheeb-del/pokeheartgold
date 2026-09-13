#include "r40_unk_020109D8_private.h"

int sub_020109D8(int angle, int value) {
    return FX_Mul(sub_020109BC(angle), value << FX32_SHIFT) >> FX32_SHIFT;
}

void sub_02010A00(int angle, s32 *dest, int end, int start) {
    int i;
    int tangent = sub_020109BC(angle);

    for (i = start; i < end; i++) {
        dest[i] = FX_Mul(tangent, i << FX32_SHIFT) >> FX32_SHIFT;
    }
}
