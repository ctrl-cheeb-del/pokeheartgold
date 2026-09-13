#include "overlay96_course_entity_r118_private.h"

void GF_AssertFail(void);
void ov96_02218FFC(Ov96CourseEntityR118 *);
void ov96_02217DC8(Ov96CourseEntityR118 *, int);

void ov96_02217DC8(Ov96CourseEntityR118 *object, int kind) {
    switch (kind) {
    case 0:
        break;
    case 1:
        ov96_02218578(object, 1);
        break;
    case 2:
        ov96_02218578(object, 7);
        object->unk59 = 1;
        break;
    case 3:
        ov96_02218FFC(object);
        break;
    default:
        GF_AssertFail();
        break;
    }
}
