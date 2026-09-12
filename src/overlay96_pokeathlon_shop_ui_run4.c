#include "overlay96_pokeathlon_shop_ui_private.h"

u32 ov96_021F218C(void *a, void *b) {
    VecFx32 diff;
    VecFx32 v1;
    VecFx32 v2;
    s32 rA;
    s32 rB;
    fx32 thresh;
    ov96_021EAF78(PTR(a, 0), U32(a, 0x28), U32(a, 0x2c), &v1.x, &v1.y, &rA);
    ov96_021EAF78(PTR(b, 0), U32(b, 0x28), U32(b, 0x2c), &v2.x, &v2.y, &rB);
    thresh = (rA + rB) << FX32_SHIFT;
    v1.z = 0;
    v2.z = 0;
    VEC_Subtract(&v1, &v2, &diff);
    if (VEC_Mag(&diff) > thresh) {
        return 0;
    }
    return 1;
}
