#include "ov80_3a00c_partial_internal.h"

void ov80_0223A8C4(MotionR21 *motion, s32 start, s32 end, s32 duration) {
    motion->value = start;
    motion->start = start;
    motion->delta = end - start;
    motion->duration = duration;
    motion->step = 0;
}

int ov80_0223A8D4(MotionR21 *motion) {
    s64 value = (s64)motion->delta * (motion->step << 12);
    s32 result;
    s32 step;
    s32 duration;
    value = (value + 0x800) >> 12;
    result = FX_Div((s32)value, motion->duration << 12);
    result += motion->start;
    motion->value = result;
    step = motion->step;
    duration = motion->duration;
    step++;
    if (step <= duration) {
        motion->step = step;
        return 0;
    }
    motion->step = duration;
    return 1;
}

void ov80_0223A91C(Vec3R21 *out, s32 x, s32 y, s32 z) {
    Vec3R21 v = { x, y, z };
    *out = v;
}
