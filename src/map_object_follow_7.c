#include "map_object_follow_internal.h"

void sub_020661CC(LocalMapObject *unused, FollowState *state, LocalMapObject *other) {
    state->found = TRUE;
    state->x = MapObject_GetXCoord(other);
    state->z = MapObject_GetZCoord(other);
    state->unk6 = 0xff;
    state->other = other;
}

BOOL sub_020661F0(LocalMapObject *object, FollowState *state) {
    LocalMapObject *other = state->other;
    int x = MapObject_GetXCoord(object);
    int z = MapObject_GetZCoord(object);
    int ox = MapObject_GetPreviousXCoord(other);
    int oz = MapObject_GetPreviousZCoord(other);
    if ((x != ox || z != oz) && (MapObject_CheckSingleMovement(other) == TRUE || MapObject_GetFlagsBitsMask(other, (MapObjectFlagBits)0x1840) == 0)) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_0206623C(LocalMapObject *object, FollowState *state) {
    int x = MapObject_GetXCoord(object);
    int z = MapObject_GetZCoord(object);
    int ox = MapObject_GetXCoord(state->other);
    int oz = MapObject_GetZCoord(state->other);
    int opx = MapObject_GetPreviousXCoord(state->other);
    int opz = MapObject_GetPreviousZCoord(state->other);
    int direction;
    if (x == ox && z == oz) {
        return FALSE;
    }
    direction = sub_02061200(x, z, opx, opz);
    x += GetDeltaXByFacingDirection(direction);
    z += GetDeltaYByFacingDirection(direction);
    if (x != ox || z != oz) {
        MapObject_ForceSetHeldMovement(object, sub_0206234C(direction, 12));
        return TRUE;
    }
    return FALSE;
}
