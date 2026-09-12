#include "overlay96_pokeathlon_shop_ui_private.h"

void ov96_021F208C(int x, int y, const VecFx32 *p, fx32 thresh, VecFx32 *out) {
    VecFx32 v;
    v.x = x << FX32_SHIFT;
    v.y = y << FX32_SHIFT;
    v.z = 0;
    VEC_Subtract(&v, p, &v);
    if (VEC_Mag(&v) > thresh) {
        out->x = x << FX32_SHIFT;
        out->y = y << FX32_SHIFT;
        out->z = 0;
    }
}
