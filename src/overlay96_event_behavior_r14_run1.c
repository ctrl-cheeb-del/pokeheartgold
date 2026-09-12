#include "global.h"

#include "overlay96_event_behavior_r14_private.h"

void ov96_0221A00C(R123Rec *r, u8 index, void *ctx) {
    MI_CpuFill8(r, 0, sizeof(*r));
    r->ctx = ctx;
    r->flags = (r->flags & ~3) | (index & 3);
    r->flags &= ~0xc;
}

BOOL ov96_0221A034(const VecFx32 *a, const VecFx32 *b, fx32 threshold) {
    VecFx32 d;
    VEC_Subtract(b, a, &d);
    if (VEC_Mag(&d) <= threshold) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov96_0221A05C(const VecFx32 *a, const VecFx32 *b, int direction) {
    VecFx32 d;
    VEC_Subtract(b, a, &d);
    VEC_Normalize(&d, &d);
    if (ov96_02215FA0(&d) == direction) {
        return TRUE;
    }
    return FALSE;
}
