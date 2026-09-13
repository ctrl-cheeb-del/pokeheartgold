#include "ov96_r109_r3_private.h"

void ov96_02213D00(void *a, void *b, void *c, const Vec2s32 *in) {
    Vec2s32 converted;
    Vec2s32 out;
    converted.x = (in->x + (s32)((u32)(in->x >> 11) >> 20)) >> 12;
    converted.y = (in->y + (s32)((u32)(in->y >> 11) >> 20)) >> 12;
    sub_02020F4C(a, b, c, &converted, &out);
}
