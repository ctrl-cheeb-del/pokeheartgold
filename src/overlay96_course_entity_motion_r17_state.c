#include "overlay96_course_entity_motion_r17_private.h"

void ov96_02218AF0(PokeathlonCourseEntityMotionR17 *p) {
    if ((u32)(p->state - 9) <= 2) {
        return;
    }
    if (p->unk50 <= 0) {
        p->unk54 = 0;
        return;
    }
    p->unk50 -= p->unk54;
    if (p->unk50 < 0) {
        p->unk50 = 0;
    }
    p->unk54 += 2 << 12;
}
