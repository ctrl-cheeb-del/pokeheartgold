#include "to41_overlay_96_residual_59_private.h"

#if 0
#endif

#if 0
#endif

BOOL ov96_021F6060(const VecFx32 *a, fx32 ra, const VecFx32 *b, fx32 rb) {
    VecFx32 d;
    VEC_Subtract(a, b, &d);
    if (VEC_Mag(&d) > ra + rb) {
        return FALSE;
    }
    return TRUE;
}
