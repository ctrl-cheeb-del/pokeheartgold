#include "palette_fade_effects_internal.h"

int sub_02010A54(int angle, int value) {
    return FX_Div((value / 2) << 12, sub_020109BC(angle));
}

int sub_02010A6C(int start, int end, int divisor) {
    return ((end - start) << 7) / divisor;
}

int sub_02010A7C(int value, int increment) {
    value += increment;
    if (value < 0) {
        value = 0;
    }
    if (value > 0xFF) {
        value = 0xFF;
    }
    return value;
}

void sub_02010A8C(IntVector4 *dst, const IntVector4 *src) {
    dst->values[0] += src->values[0];
    dst->values[1] += src->values[1];
    dst->values[2] += src->values[2];
    dst->values[3] += src->values[3];
}
