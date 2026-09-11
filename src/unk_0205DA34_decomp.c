#include "unk_0205DA34_internal.h"

u32 sub_0205DA34(void *unused, LocalMapObject *object, int direction) {
    u32 result = 0;
    u32 collision = sub_0205DAA8(unused, object, direction);

    if (collision & 0xA) {
        result |= 1;
        if (sub_0205DBF4(unused, object, direction)) {
            result |= 8;
        }
    }
    if (collision & 4) {
        result |= 2;
    }
    if (sub_0205DB68(unused, object, direction)) {
        result |= 4;
    }
    if (sub_0205DCA0(unused, object, direction) == TRUE) {
        result |= 0x20;
    }
    if (sub_0205DCFC(unused, object, direction) == TRUE) {
        result |= 1;
    }
    return result;
}

u32 sub_0205DAA8(void *unused, LocalMapObject *object, int direction) {
    int x = MapObject_GetXCoord(object);
    int dx = GetDeltaXByFacingDirection(direction);
    int y = MapObject_GetYCoord(object);
    int z = MapObject_GetZCoord(object);
    int dz = GetDeltaYByFacingDirection(direction);
    VecFx32 position;
    s8 terrainFlag;
    u32 result;

    MapObject_CopyPositionVector(object, &position);
    result = 0;
    if (sub_02060D94(object, x + dx, y, z + dz) == TRUE) {
        result |= 1;
    }
    if (sub_020549F4(MapObject_GetFieldSystem(object), &position, x + dx, z + dz, &terrainFlag) == TRUE) {
        result |= 2;
        if (terrainFlag != 0) {
            result |= 8;
        }
    }
    if (sub_02060DEC(object, x + dx, z + dz, direction) == TRUE) {
        result |= 2;
    }
    if (sub_02060BFC(object, x + dx, y, z + dz) == TRUE) {
        result |= 4;
    }
    return result;
}

BOOL sub_0205DB68(void *unused, LocalMapObject *object, int direction) {
    FieldSystem *fieldSystem;
    int x;
    int z;
    u8 behavior;

    if (direction != -1) {
        fieldSystem = MapObject_GetFieldSystem(object);
        x = MapObject_GetXCoord(object) + GetDeltaXByFacingDirection(direction);
        z = MapObject_GetZCoord(object) + GetDeltaYByFacingDirection(direction);
        behavior = GetMetatileBehavior(fieldSystem, x, z);
        switch (direction) {
        case 0:
            if (MetatileBehavior_IsJumpNorth(behavior) == TRUE) {
                return TRUE;
            }
            break;
        case 1:
            if (MetatileBehavior_IsJumpSouth(behavior) == TRUE) {
                return TRUE;
            }
            break;
        case 2:
            if (MetatileBehavior_IsJumpWest(behavior) == TRUE) {
                return TRUE;
            }
            break;
        case 3:
            if (MetatileBehavior_IsJumpEast(behavior) == TRUE) {
                return TRUE;
            }
            break;
        }
    }
    return FALSE;
}

BOOL sub_0205DBF4(void *unused, LocalMapObject *object, int direction) {
    FieldSystem *fieldSystem;
    int x;
    int z;
    u8 behavior;

    if (direction != -1) {
        fieldSystem = MapObject_GetFieldSystem(object);
        x = MapObject_GetXCoord(object);
        z = MapObject_GetZCoord(object);
        behavior = GetMetatileBehavior(fieldSystem, x, z);
        switch (direction) {
        case 0:
            if (MetatileBehavior_IsWarpEntranceNorth(behavior) == TRUE) {
                return TRUE;
            }
        case 1:
            if (MetatileBehavior_IsWarpEntranceSouth(behavior) == TRUE) {
                return TRUE;
            }
        case 2:
            if (MetatileBehavior_IsWarpEntranceWest(behavior) == TRUE) {
                return TRUE;
            }
        case 3:
            if (MetatileBehavior_IsWarpEntranceEast(behavior) == TRUE) {
                return TRUE;
            }
        }
        x += GetDeltaXByFacingDirection(direction);
        z += GetDeltaYByFacingDirection(direction);
        if (MetatileBehavior_IsDoor(GetMetatileBehavior(fieldSystem, x, z)) == TRUE) {
            return TRUE;
        }
    }
    return FALSE;
}
