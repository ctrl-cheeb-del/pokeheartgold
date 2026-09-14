#include "overlay96_course_entity_r118_private.h"

void GF_AssertFail(void);
int ov96_02217E08(Ov96CourseEntityR118 *);

int ov96_02217E08(Ov96CourseEntityR118 *object) {
    int state = object->state;
    int value = *(s32 *)((u8 *)object + 0x18);
    u32 enabled = object->flags.bits.bit27;
    int result = 0;

    if (enabled == 0) {
        return result;
    }

    switch (state) {
    case 11:
        result = 0;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 12:
        if (value == 11 || value == 6) {
            result = 3;
        } else if (state == 6) {
            result = 2;
        } else {
            result = 1;
        }
        break;
    case 1:
    case 2:
    case 9:
        if (value == 11 || value == 6) {
            result = 3;
        }
        break;
    case 0:
    case 3:
    case 4:
    case 10:
        GF_AssertFail();
        break;
    default:
        GF_AssertFail();
        break;
    }
    return result;
}
