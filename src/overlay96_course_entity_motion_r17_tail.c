#include "overlay96_course_entity_motion_r17_private.h"

void ov96_02219398(PokeathlonCourseEntityMotionR17 *p) {
    u32 rem = ((((*(volatile u32 *)&p->flags << 8) >> 30) + 1) % 3);
    p->flags = (p->flags & 0xFF3FFFFF) | ((rem << 30) >> 8);
    p->unk04 = (u8 *)p->unk08 + 0x74 + (((p->flags << 8) >> 30) << 4);
}

BOOL ov96_022193CC(u32 id, BOOL flag) {
    return sub_0200606C((u16)id, flag ? 3 : 4);
}
