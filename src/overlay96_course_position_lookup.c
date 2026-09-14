#include "global.h"

#include "overlay96_course_position_lookup_private.h"

u8 ov96_022031A8(void *unused, int angle, u32 x, u32 y, VecFx32 *out) {
    float xf;
    float yf;
    VecFx32 position;
    MtxFx43 rotation;
    VecFx32 relative;
    VecFx32 rotated;
    VecFx32 diff;
    int i;

#pragma unused(unused)
    ov96_0220404C(x, y + 0x120, &xf, &yf);
    position.x = (fx32)(xf * FX32_ONE);
    position.z = (fx32)(yf * FX32_ONE);
    position.y = 0;
    if (angle != 0) {
        relative = position;
        relative.x -= 33 * FX32_ONE;
        relative.z -= 33 * FX32_ONE;
        MTX_RotY43(&rotation, FX_SinIdx(angle << 14), FX_CosIdx(angle << 14));
        MTX_MultVec43(&relative, &rotation, &rotated);
        rotated.x += 33 * FX32_ONE;
        rotated.z += 33 * FX32_ONE;
        position = rotated;
    }
    *out = position;
    for (i = angle * 3; i < (angle + 1) * 3; i++) {
        VEC_Subtract(&ov96_0221C98C[i], &position, &diff);
        if (VEC_Mag(&diff) <= 4 * FX32_ONE) {
            return (u8)i;
        }
    }
    return 12;
}
