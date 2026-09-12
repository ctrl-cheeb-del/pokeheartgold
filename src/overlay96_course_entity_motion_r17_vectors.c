#include "overlay96_course_entity_motion_r17_private.h"

void ov96_02218EB8(PokeathlonCourseEntityMotionR17 *p) {
    BOOL valid = TRUE;
    if (p->state != 7 && p->state != 6) {
        valid = FALSE;
    }
    if (!valid) {
        GF_AssertFail();
    }
    VecFx32 zero = { 0, 0, 0 };
    p->vec44 = zero;
    p->vec20 = p->vec2C;
    ov96_02218578(p, 1);
    if (ov96_02218934(p)) {
        ov96_02219030(p);
    }
}

void ov96_02218F18(PokeathlonCourseEntityMotionR17 *p) {
    VecFx32 out;
    VecFx32 zero = { 0, 0, 0 };
    VEC_MultAdd(0xB33, &p->vec38, &zero, &out);
    VEC_Add(&p->vec44, &out, &p->vec44);
    VEC_Add(&p->vec2C, &p->vec44, &p->vec2C);
}
