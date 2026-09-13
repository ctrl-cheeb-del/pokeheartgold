#include "r40_overlay_96_residual_29_private.h"

BOOL ov96_021EB0CC(Ov96PositionObject *obj, fx32 x, fx32 y, s32 targetX, s32 targetY) {
    VecFx32 delta;
    VecFx32 position;
    VecFx32 target;
    target.x = targetX << FX32_SHIFT;
    target.y = targetY << FX32_SHIFT;
    target.z = 0;
    position.x = x;
    position.y = y;
    position.z = 0;
    VEC_Subtract(&target, &position, &delta);
    if (VEC_Mag(&delta) < (obj->radius << FX32_SHIFT)) {
        return TRUE;
    }
    return FALSE;
}
