#include "overlay96_course_opponent_prefix_r111_private.h"

int ov96_02214DBC(void *objectRaw, const void *sourceRaw, u8 state, u8 quadrant) {
    Ov96R111MovingObject *object = objectRaw;
    const Ov96R111Source *source = sourceRaw;
    u8 random = (s32)LCRandom() % 100;

    switch (state) {
    case 2:
        if (random < 60) {
            return 0;
        }
        if (random < 80) {
            object->position = source->position;
            return 10;
        }
        object->position = source->position;
        object->triggered = 1;
        return 10;
    case 3:
        if (random < 20) {
            return 0;
        }
        if (random < 90) {
            object->position = source->position;
            return 3;
        }
        object->position = source->position;
        object->triggered = 1;
        return 3;
    case 4:
    case 13:
        object->position = source->position;
        object->triggered = 1;
        break;
    case 1:
    case 9:
        if (quadrant != 4) {
            u8 index = 3 - quadrant;
            object->position.x = *(const u16 *)((const u8 *)ov96_0221D678 + index * 12) << 12;
            object->position.y = *(const u16 *)((const u8 *)ov96_0221D67A + index * 12) << 12;
        } else {
            GF_AssertFail();
        }
        break;
    case 0:
    case 8:
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}
