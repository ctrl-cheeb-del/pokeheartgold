#include "overlay96_course_entity_motion_r17_private.h"

void ov96_02218FD4(PokeathlonCourseEntityMotionR17 *p) {
    ov96_02218578(p, 12);
    p->unk5A = 10;
    p->unk50 = 0;
    p->vec20 = p->vec2C;
}

void ov96_02218FFC(PokeathlonCourseEntityMotionR17 *p) {
    s32 v = FX_Div(*(s32 *)((u8 *)p->unk04 + 8), *(s32 *)((u8 *)*(void **)((u8 *)p->unk04 + 4) + 8));
    v = (10 * (FX32_ONE - v)) - 3;
    if (v < 0) {
        v = 0;
    }
    p->unk58 = v >> FX32_SHIFT;
    ov96_02218578(p, 2);
}
