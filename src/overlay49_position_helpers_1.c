#include "overlay49_position_helpers_private.h"

void ov49_022599F8(Ov49R14Work *work)
{
    u32 pos[3];
    ov45_0223089C(work->obj, 1);
    ov45_02230908(work->obj, pos);
    pos[1] = 0;
    ov45_022308E4(work->obj, pos);
}

void ov49_02259A20(Ov49R14Out *out, void *obj, u8 value)
{
    out->b = value;
    out->c = value;
    out->d = 0;
    out->e = 0;
    out->f = 0;
    out->a = 0;
    ov45_02230700(obj, value);
}
