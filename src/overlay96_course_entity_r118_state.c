#include "overlay96_course_entity_r118_private.h"

BOOL ov96_02218688(Ov96CourseEntityR118 *object) {
    if (object->flags.bits.bit27) {
        return FALSE;
    }
    if (object->flags.bits.bit28) {
        return FALSE;
    }
    if (object->flags.bits.bit26) {
        return FALSE;
    }
    return object->state == 1;
}
