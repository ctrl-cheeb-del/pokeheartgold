#include "map_object_movement_internal.h"

void sub_02061844(LocalMapObject *object) {
    sub_020616C0(object, 3);
}

void sub_02061850(LocalMapObject *object) {
    u8 *state = sub_0205F394(object);
    while (_020FD5A0[(s8)state[2]](object, state) == TRUE) {}
}

void sub_02061874(LocalMapObject *object, u8 *state) {
    u32 facing = MapObject_GetFacingDirection(object);
    MapObject_ForceSetHeldMovement(object, sub_0206234C(facing, 0));
    state[2] = 1;
}

BOOL sub_02061894(LocalMapObject *object, u8 *state) {
    if (!sub_02062428(object)) {
        return FALSE;
    }
    *(u32 *)(state + 4) = 0;
    state[2] = 2;
    return TRUE;
}

BOOL sub_020618B0(LocalMapObject *object, u8 *state) {
    (void)object;
    (*(int *)(state + 4))++;
    if (*(int *)(state + 4) < 24) {
        return FALSE;
    }
    state[2] = 3;
    return TRUE;
}
