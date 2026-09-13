#include "overlay96_course_opponent_prefix_r111_private.h"

int ov96_02215058(void *objectRaw, void *sourceRaw, int state, int index) {
    Ov96R111CourseObject *object = objectRaw;
    Ov96R111Source *source = sourceRaw;
    volatile u16 point[2];

    switch (state) {
    case 6:
    case 11: {
        int offset = (index - 1) * 12;
        const u16 *points = (const u16 *)((const u8 *)ov96_0221D678 + offset);

        if (ov96_022156A8(object->position.x / FX32_ONE, object->position.y / FX32_ONE, (const u16(*)[2])points)) {
            return 0;
        }
        if ((s32)LCRandom() % 2 == 0) {
            point[0] = points[0];
            point[1] = points[1];
        } else if ((s32)LCRandom() % 2 == 0) {
            const u16 *other = (const u16 *)((const u8 *)ov96_0221D67C + offset);
            point[0] = other[0];
            point[1] = other[1];
        } else {
            const u16 *other = (const u16 *)((const u8 *)ov96_0221D680 + offset);
            point[0] = other[0];
            point[1] = other[1];
        }
        point[0] += 8 - (s32)LCRandom() % 17;
        point[1] += 8 - (s32)LCRandom() % 17;
        object->target.x = point[0] << 12;
        object->target.y = point[1] << 12;
        return 6;
    }
    case 7:
    case 12:
        object->target = source->position;
        if ((s32)LCRandom() % 100 < 80) {
            object->triggered = 1;
        }
        return 10;
    default:
        GF_AssertFail();
    case 5:
    case 8:
        return 0;
    }
}
