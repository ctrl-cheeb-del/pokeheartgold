#include "map_object_follow_internal.h"

void sub_02066054(LocalMapObject *object) {
    (void)object;
}

void sub_02066058(LocalMapObject *object) {
    ((FollowState *)sub_0205F394(object))->found = FALSE;
}

BOOL sub_02066064(LocalMapObject *object, FollowState *state) {
    MapObject_ClearSingleMovement(object);
    MapObject_ClearEndMovement(object);
    if (sub_020661F0(object, state) == TRUE && sub_0206623C(object, state) == TRUE) {
        MapObject_SetSingleMovement(object);
        state->state++;
        return TRUE;
    }
    return FALSE;
}

BOOL sub_020660A0(LocalMapObject *object, FollowState *state) {
    if (!sub_02062428(object)) {
        return FALSE;
    }
    MapObject_ClearSingleMovement(object);
    state->state = 0;
    return FALSE;
}
