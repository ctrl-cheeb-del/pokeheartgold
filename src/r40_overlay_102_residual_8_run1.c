#include "r40_overlay_102_residual_8_private.h"
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

int ov102_021E8C3C(void *state) {
    u16 value = U16(state, 0);
    if (value != 0) {
        if (value >= 5) {
            U16(state, 0) = value - 5;
            S32(state, 8) = -5;
        } else {
            S32(state, 8) = -value;
            U16(state, 0) = 0;
        }
        return 2;
    }
    return 4;
}
