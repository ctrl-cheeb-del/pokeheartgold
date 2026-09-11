#include "overlay49_state_internal.h"
#pragma require_prototypes off
void ov49_0225D224(Ov49DParent *, Ov49DState *, s32, s32, u32);
void ov49_0225D328(Ov49DParent *, Ov49DState *, s32);
u32 ov49_0225D450(Ov49DState *, s32);

void ov49_0225D1C4(void *p, VecS16Sol v) {
    VecFx32 out;
    ov49_02258800(&v, &out);
    sub_020182A8((u8 *)p + 4, out.x, out.y, out.z);
}

u32 ov49_0225D1EC(void *p) {
    VecFx32 in;
    u16 out[2];
    u32 result;
    sub_020182B0((u8 *)p + 4, &in.x, &in.y, &in.z);
    ov49_02258814(&in, out);
    result = out[1];
    result <<= 16;
    result |= out[0];
    return result;
}

void ov49_0225D214(Ov49DParent *p, Ov49DState *s, s32 i, s32 type) {
    ov49_0225D224(p, s, i, type, 0);
}
