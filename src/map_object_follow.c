#include "map_object_follow_internal.h"

void sub_020658D4(LocalMapObject *object) {
    FollowState *state = (FollowState *)sub_0205F370(object, 12);
    sub_02065CD0(object, state);
    sub_0205F328(object, 0);
    MapObject_ClearSingleMovement(object);
    MapObject_ClearFlag18(object, 0);
}
