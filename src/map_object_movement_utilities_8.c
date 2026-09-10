#include "map_object_movement_utilities_internal.h"

BOOL sub_02060E54(LocalMapObject *object, int behavior) {
    if (sub_0205BA54((u8)behavior)) {
        if (!MapObject_CheckFlag28(object)) {
            return 1;
        }
    } else if (MetatileBehavior_IsSurfableWater((u8)behavior)) {
        return 1;
    } else if (sub_0205B78C((u8)behavior)) {
        u32 sprite = MapObject_GetSpriteID(object) - 0xB2;
        if (sprite <= 1) {
            return 1;
        }
    }
    return 0;
}

BOOL sub_02060EA4(LocalMapObject *object, int behavior) {
    if (MetatileBehavior_IsSand(behavior)) {
        return 1;
    }
    return 0;
}

BOOL sub_02060EBC(LocalMapObject *object, int behavior) {
    if (MetatileBehavior_IsSnow(behavior)) {
        return 1;
    }
    return 0;
}

BOOL sub_02060ED4(LocalMapObject *object, int behavior) {
    if (sub_0205B8C4(behavior)) {
        return 1;
    }
    return 0;
}

BOOL sub_02060EEC(LocalMapObject *object, int behavior) {
    if (MapObject_CheckFlag28(object) == 1 && sub_0205BA30((u8)behavior) == 1) {
        return 1;
    }
    return 0;
}

int GetDeltaXByFacingDirection(int direction) {
    return _020FD4AC[direction];
}

int GetDeltaYByFacingDirection(int direction) {
    return _020FD49C[direction];
}

void sub_02060F24(LocalMapObject *object, int direction) {
    MapObject_SetPreviousX(object, MapObject_GetXCoord(object));
    MapObject_SetPreviousY(object, MapObject_GetYCoord(object));
    MapObject_SetPreviousZ(object, MapObject_GetZCoord(object));
    MapObject_AddCurrentX(object, GetDeltaXByFacingDirection(direction));
    MapObject_AddCurrentY(object, 0);
    MapObject_AddCurrentZ(object, GetDeltaYByFacingDirection(direction));
}

void sub_02060F78(LocalMapObject *object) {
    MapObject_SetPreviousX(object, MapObject_GetXCoord(object));
    MapObject_SetPreviousY(object, MapObject_GetYCoord(object));
    MapObject_SetPreviousZ(object, MapObject_GetZCoord(object));
}

int sub_02060FA8(LocalMapObject *object, int direction) {
    int x = MapObject_GetXCoord(object) + GetDeltaXByFacingDirection(direction);
    int z = MapObject_GetZCoord(object) + GetDeltaYByFacingDirection(direction);
    return GetMetatileBehavior(MapObject_GetFieldSystem(object), x, z);
}

u8 sub_02060FE0(LocalMapObject *object, int direction) {
    int x = MapObject_GetXCoord(object) + GetDeltaXByFacingDirection(direction);
    int z = MapObject_GetZCoord(object) + GetDeltaYByFacingDirection(direction);
    return sub_020548EC(MapObject_GetFieldSystem(object), x, z);
}

void sub_0206101C(LocalMapObject *object, int direction, int distance) {
    VecFx32 position;
    MapObject_CopyPositionVector(object, &position);
    switch (direction) {
    case 0:
        position.z -= distance;
        break;
    case 1:
        position.z += distance;
        break;
    case 2:
        position.x -= distance;
        break;
    case 3:
        position.x += distance;
        break;
    }
    MapObject_SetPositionVector(object, &position);
}
