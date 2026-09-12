#include "overlay96_course_entity_motion_r17_private.h"

void *ov96_0221935C(void *course, u32 a, u32 b) {
    u8 *p;
    u32 aa = a;
    u32 bb = b;

    p = PokeathlonCourse_GetHeapAllocPtr4(course);
    if (p == NULL) {
        GF_AssertFail();
    }
    if (aa >= 4) {
        GF_AssertFail();
    }
    if (bb >= 3) {
        GF_AssertFail();
    }
    p += 0x30;
    p += (aa * 3 + bb) * 0x1C;
    if (p == NULL) {
        GF_AssertFail();
    }
    return p;
}
