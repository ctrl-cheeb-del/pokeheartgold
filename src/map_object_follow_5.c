#include "map_object_follow_internal.h"

void sub_02065FFC(LocalMapObject *object) {
    FollowState *state = (FollowState *)sub_0205F370(object, 12);
    sub_02066150(object, state);
    sub_0205F328(object, 0);
    MapObject_ClearSingleMovement(object);
    state->found = FALSE;
}
