#include "overlay96_course_object_r102_private.h"

void ov96_0220FB98(Ov96CourseObjectR102 *obj, u8 valueA, u8 value8) {
    obj->flags |= 0x20;
    obj->x = 0x80;
    obj->y = 0;
    obj->x = 0;
    obj->flags = (obj->flags & ~0x1C) | 4;
    obj->field8 = value8;
    obj->field9 = MTRandom() % 15;
    obj->flags &= 0xFFFFC03F;
    obj->fieldA = valueA;
}

void ov96_0220FBDC(Ov96CourseObjectR102 *obj) {
    obj->flags &= ~0x20;
    obj->flags &= ~0x1C;
}
