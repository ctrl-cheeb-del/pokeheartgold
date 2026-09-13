#include "global.h"

#include "r40_unk_02060AF4_private.h"

u32 sub_02060AF4(LocalMapObject *object, VecFx32 *position, int x, int y, int z, int direction) {
    u32 result = 0;
    s8 slope;

    if (sub_02060D94(object, x, y, z) == TRUE) {
        result |= 1;
    }
    if (sub_020549A8(MapObject_GetFieldSystem(object), position, x, z, &slope) == TRUE) {
        result |= 2;
        if (slope != 0) {
            result |= 8;
        }
    }
    if (sub_02060DEC(object, x, z, direction) == TRUE) {
        result |= 2;
    }
    if (sub_0203401C(sub_0203993C())) {
        if (sub_02060BFC(object, x, y, z) == TRUE) {
            result |= 4;
        }
    } else {
        if (sub_02060CA8(object, x, y, z) == TRUE) {
            result |= 4;
        }
    }
    return result;
}
