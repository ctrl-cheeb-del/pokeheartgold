#include "r40_overlay_45_thumb_residual_6_private.h"

extern int ov45_0222EC68(void *valueSource);
extern void *ov45_0222E9E0(u8 *state);

void ov45_0222A43C(u8 *state) {
    MIi_CpuClear32(0, (u32 *)(state + 0x3E0), 4);
}

void ov45_0222A450(u8 *state, void *valueSource, u32 index) {
    int value;

    GF_ASSERT(index < 4);
    value = ov45_0222EC68(valueSource);
    GF_ASSERT(value != -1);
    state[0x3E0 + index] = value;
}

void ov45_0222A480(u8 *state, u32 index) {
    void *valueSource = ov45_0222E9E0(state);

    ov45_0222A450(state, valueSource, index);
}
