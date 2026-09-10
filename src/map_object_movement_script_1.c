#include "map_object_movement_script_internal.h"

void sub_020613F8(LocalMapObject *object) {
    LocalMovementState *state = (LocalMovementState *)sub_0205F394(object);
    int direction;
    switch (state->state) {
    case 0:
        MapObject_ClearSingleMovement(object);
        MapObject_ClearEndMovement(object);
        direction = sub_0206234C(MapObject_GetFacingDirection(object), 0);
        MapObject_ForceSetHeldMovement(object, direction);
        state->state++;
        break;
    case 1:
        if (!sub_02062428(object)) {
            break;
        }
        state->delay = sub_02061E20(_020FD7B8, -1);
        state->state++;
    case 2:
        state->delay--;
        if (state->delay != 0) {
            break;
        }
        state->state++;
    case 3:
        direction = sub_02061E44(state->directionTable, -1);
        MapObject_SetOrQueueFacing(object, direction);
        if (state->restrictToRange == 1 && !sub_020615F0(object, direction)) {
            state->state = 0;
            break;
        }
        if (sub_02060BB8(object, direction)) {
            state->state = 0;
            break;
        }
        MapObject_ForceSetHeldMovement(object, sub_0206234C(direction, state->heldMovement));
        MapObject_SetSingleMovement(object);
        state->state++;
    case 4:
        if (sub_02062428(object)) {
            MapObject_ClearSingleMovement(object);
            state->state = 0;
        }
        break;
    }
}

void sub_020614F4(LocalMapObject *object, LocalMovementBounds *bounds) {
    s32 x = MapObject_GetInitialX(object);
    s32 z = MapObject_GetInitialZ(object);
    s32 xRange = MapObject_GetXRange(object);
    s32 zRange = MapObject_GetYRange(object);
    switch (MapObject_GetMovement(object)) {
    case 6:
        bounds->minX = x - xRange;
        bounds->maxX = x;
        bounds->minZ = z - zRange;
        bounds->maxZ = z;
        break;
    case 7:
        bounds->minX = x;
        bounds->maxX = x + xRange;
        bounds->minZ = z - zRange;
        bounds->maxZ = z;
        break;
    case 8:
        bounds->minX = x - xRange;
        bounds->maxX = x;
        bounds->minZ = z;
        bounds->maxZ = z + zRange;
        break;
    case 9:
        bounds->minX = x;
        bounds->maxX = x + xRange;
        bounds->minZ = z;
        bounds->maxZ = z + zRange;
        break;
    case 10:
        bounds->minX = x - xRange;
        bounds->maxX = x;
        bounds->minZ = z - zRange;
        bounds->maxZ = z + zRange;
        break;
    case 11:
        bounds->minX = x;
        bounds->maxX = x + xRange;
        bounds->minZ = z - zRange;
        bounds->maxZ = z + zRange;
        break;
    case 12:
        bounds->minX = x - xRange;
        bounds->maxX = x + xRange;
        bounds->minZ = z - zRange;
        bounds->maxZ = z;
        break;
    case 13:
        bounds->minX = x - xRange;
        bounds->maxX = x + xRange;
        bounds->minZ = z;
        bounds->maxZ = z + zRange;
        break;
    default:
        GF_AssertFail();
        break;
    }
}

BOOL sub_020615F0(LocalMapObject *object, int direction) {
    LocalMovementBounds bounds;
    s32 x;
    s32 z;
    sub_020614F4(object, &bounds);
    x = MapObject_GetXCoord(object) + GetDeltaXByFacingDirection(direction);
    z = MapObject_GetZCoord(object) + GetDeltaYByFacingDirection(direction);
    if (bounds.minX > x || bounds.maxX < x) {
        return FALSE;
    }
    if (bounds.minZ > z || bounds.maxZ < z) {
        return FALSE;
    }
    return TRUE;
}
