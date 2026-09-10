#include "map_object_movement_internal.h"

BOOL sub_02061720(LocalMapObject *object, u8 *state) {
    int direction = sub_02061F5C(object, 0x26, -1);
    if (direction == -1) {
        direction = MapObject_GetFacingDirection(object);
    }
    MapObject_ForceSetHeldMovement(object, sub_0206234C(direction, 0));
    state[2] = 1;
    return TRUE;
}

BOOL sub_02061754(LocalMapObject *object, u8 *state) {
    if (!sub_02062428(object)) {
        return FALSE;
    }
    *(u32 *)(state + 4) = 0;
    state[2] = 2;
    return TRUE;
}

BOOL sub_02061770(LocalMapObject *object, u8 *state) {
    if (*(u32 *)(state + 4) != 0 && sub_02061F5C(object, 0x26, -1) != -1) {
        state[2] = 0;
        return TRUE;
    }
    (*(int *)(state + 4))++;
    if (*(int *)(state + 4) < 24) {
        return FALSE;
    }
    state[2] = 3;
    return TRUE;
}
