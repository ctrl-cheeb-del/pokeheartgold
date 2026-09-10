#include "map_object_follow_internal.h"

BOOL sub_020663B4(LocalMapObject *object, FollowState *state) {
    if (*((u8 *)state + 2) == 0) {
        sub_02066420(object, ov01_021FFF5C(object, *((u8 *)state + 1)));
    }
    MapObject_ClearSingleMovement(object);
    MapObject_ClearEndMovement(object);
    state->state++;
    return FALSE;
}

BOOL sub_020663E4(LocalMapObject *object, FollowState *state) {
    if (*((u8 *)state + 2) == 0) {
        if (sub_0206642C(object) == 0 && sub_0205F73C(object) == TRUE) {
            sub_02066420(object, ov01_021FFF5C(object, *((u8 *)state + 1)));
        }
        MapObject_SetFlagsBits(object, (MapObjectFlagBits)(1 << 20));
    }
    return FALSE;
}

int sub_02066420(LocalMapObject *object, int value) {
    void *state = sub_0205F394(object);
    *(int *)((u8 *)state + 4) = value;
    return (int)state;
}

int sub_0206642C(LocalMapObject *object) {
    return *(int *)((u8 *)sub_0205F394(object) + 4);
}

void sub_02066438(LocalMapObject *object) {
    *((u8 *)sub_0205F394(object) + 2) = 1;
}
