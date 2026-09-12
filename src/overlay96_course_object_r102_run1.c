#include "overlay96_course_object_r102_private.h"

u32 ov96_0220F3BC(const Ov96CourseObjectR102 *obj) {
    typedef struct {
        u32 low : 2;
        u32 type : 3;
        u32 rest : 27;
    } Flags;
    switch (((const Flags *)&obj->flags)->type) {
    case 3:
        return 1;
    case 4:
        return 2;
    case 5:
        return 3;
    case 6:
        return 5;
    default:
        GF_AssertFail();
        return 0;
    }
}
