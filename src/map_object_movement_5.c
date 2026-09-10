#include "map_object_movement_internal.h"

void sub_0206197C(LocalMapObject *object) {
    u8 *state = sub_0205F370(object, 8);
    if (sub_02062050(object) == TRUE) {
        sub_02062064(object, state + 4);
    }
}

void sub_0206199C(LocalMapObject *object) {
    u8 *state = sub_0205F394(object);
    while (_020FD548[*(s16 *)state](object, state) == TRUE) {}
}

void sub_020619C0(LocalMapObject *object, u8 *state) {
    u32 direction = MapObject_GetInitialFacingDirection(object);
    if (*(s16 *)(state + 2) == 1) {
        direction = sub_020611F4(direction);
    }
    MapObject_SetNextFacingDirection(object, direction);
    if (!sub_02062050(object)) {
        MapObject_SetFacingDirection(object, direction);
    }
    *(u16 *)state = 1;
}
