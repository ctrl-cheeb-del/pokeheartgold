#include "overlay96_course_collision_r87_private.h"

fx32 ov96_02207390(const Ov96Vec3 *a, const Ov96Vec3 *b, const Ov96Vec3 *direction, fx32 radius) {
    Ov96Vec3 delta;
    fx32 magnitude;
    fx32 dot;
    fx32 length;
    fx32 root;
    fx32 first;
    fx32 second;
    VEC_Subtract(b, a, &delta);
    magnitude = VEC_Mag(&delta);
    magnitude *= magnitude;
    dot = VEC_DotProduct(&delta, direction);
    length = VEC_Mag(direction);
    length *= length;
    root = FX_Sqrt(dot - (length - radius * radius) * magnitude);
    first = FX_Div(root - dot, magnitude);
    second = FX_Div(-(dot + root), magnitude);
    if (first <= second) {
        second = first;
    }
    return second;
}

float ov96_022073F0(u8 *p, int index) {
    p += index * 20;
    return (float)p[0x1c];
}
