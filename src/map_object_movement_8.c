#include "map_object_movement_internal.h"

BOOL sub_02062050(LocalMapObject *object) {
    u32 type = MapObject_GetType(object) - 7;
    if (type <= 1) {
        return TRUE;
    }
    return FALSE;
}

void sub_02062064(LocalMapObject *object, u8 *state) {
    if (MapObject_GetType(object) == 7) {
        state[1] = 0;
    } else {
        state[1] = 1;
    }
}
