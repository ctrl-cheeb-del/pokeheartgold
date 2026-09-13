#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

void ov96_021F5F34(int x, int y, const VecFx32 *a, VecFx32 *b) {
    VecFx32 t;
    t.x = x << FX32_SHIFT;
    t.y = (y << FX32_SHIFT) + 0xc0000;
    t.z = 0;
    VEC_Subtract(&t, a, b);
    if (b->y > 0x70000) {
        b->y = 0x70000;
    }
}
