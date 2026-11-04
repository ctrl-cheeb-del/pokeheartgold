#include "global.h"

#include "constants/scrcmd.h"

#include "field/field_follow_mon.h"

#include "field_system.h"
#include "field_terrain.h"
#include "map_object.h"
#include "map_object_movement_utilities_internal.h"
#include "metatile_behavior.h"
#include "overlay_01.h"

BOOL MapObject_IsTileOccupiedInLink(LocalMapObject *self, int x, int y, int z) {
    MapObjectManager *manager = MapObject_GetManager(self);
    LocalMapObject *object = MapObjectManager_GetObjects2(manager);
    u32 count = MapObjectManager_GetObjectCount(manager);

    do {
        if (object != self && MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_ACTIVE) != 0 && MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK18) == 0) {
            int objectX = MapObject_GetXCoord(object);
            int objectZ = MapObject_GetZCoord(object);
            if (objectX == x && objectZ == z) {
                int delta = MapObject_GetYCoord(object) - y;
                if (delta < 0) {
                    delta = -delta;
                }
                if (delta < 2) {
                    return TRUE;
                }
            }
            objectX = MapObject_GetPreviousXCoord(object);
            objectZ = MapObject_GetPreviousZCoord(object);
            if (objectX == x && objectZ == z) {
                int delta = MapObject_GetYCoord(object) - y;
                if (delta < 0) {
                    delta = -delta;
                }
                if (delta < 2) {
                    return TRUE;
                }
            }
        }
        MapObjectArray_NextObject(&object);
        count--;
    } while (count != 0);
    return FALSE;
}

BOOL MapObject_IsTileOccupied(LocalMapObject *self, int x, int y, int z) {
    int objectX;
    int objectZ;
    MapObjectManager *manager = MapObject_GetManager(self);
    LocalMapObject *object = MapObjectManager_GetObjects2(manager);
    u32 count = MapObjectManager_GetObjectCount(manager);

    do {
        if (object != self && MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_ACTIVE) != 0) {
            objectX = MapObject_GetXCoord(object);
            objectZ = MapObject_GetZCoord(object);
            if (objectX == x && objectZ == z) {
                int delta = MapObject_GetYCoord(object) - y;
                if (delta < 0) {
                    delta = -delta;
                }
                if (delta < 2) {
                    return TRUE;
                }
            }
            objectX = MapObject_GetPreviousXCoord(object);
            objectZ = MapObject_GetPreviousZCoord(object);
            if (objectX == x && objectZ == z) {
                int delta = MapObject_GetYCoord(object) - y;
                if (delta < 0) {
                    delta = -delta;
                }
                if (delta < 2) {
                    return TRUE;
                }
            }
            if (MapObject_GetID(object) == obj_partner_poke && FollowMonObject_IsLarge(object) != 0 && !MapObject_CheckInvisible(object)) {
                MapObject_GetPreviousCoordsBehind(object, &objectX, &objectZ);
                if (objectX == x && objectZ == z) {
                    int delta = MapObject_GetYCoord(object) - y;
                    if (delta < 0) {
                        delta = -delta;
                    }
                    if (delta < 2) {
                        return TRUE;
                    }
                }
            }
        }
        MapObjectArray_NextObject(&object);
        count--;
    } while (count != 0);
    return FALSE;
}

BOOL MapObject_IsOutsideMovementRange(LocalMapObject *object, int x, int y, int z) {
    int initialX = MapObject_GetInitialX(object);
    int rangeX = MapObject_GetXRange(object);
    if (rangeX != -1) {
        int maxX = initialX + rangeX;
        int minX = initialX - rangeX;
        if (minX > x || maxX < x) {
            return TRUE;
        }
    }
    {
        int initialZ = MapObject_GetInitialZ(object);
        int rangeZ = MapObject_GetYRange(object);
        if (rangeZ != -1) {
            int maxZ = initialZ + rangeZ;
            int minZ = initialZ - rangeZ;
            if (minZ > z || maxZ < z) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL MapObject_IsMoveBlockedByBehavior(LocalMapObject *object, int x, int z, int direction) {
    if (!MapObject_CheckIgnoreMetatileBehaviors(object)) {
        FieldSystem *fieldSystem = MapObject_GetFieldSystem(object);
        u8 objectBehavior = MapObject_GetCurrentMetatileBehavior(object);
        u8 behavior = GetMetatileBehavior(fieldSystem, x, z);
        if (behavior == GetMetatileBehavior_None()) {
            return TRUE;
        }
        if (gMetatileBlocksExitTests[direction](objectBehavior) == TRUE || gMetatileBlocksEntryTests[direction](behavior) == TRUE) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL MapObject_CheckWaterBehavior(LocalMapObject *object, int behavior) {
    if (MetatileBehavior_IsBridgeOverWater(behavior)) {
        if (!MapObject_CheckFlag28(object)) {
            return TRUE;
        }
    } else if (MetatileBehavior_IsSurfableWater(behavior)) {
        return TRUE;
    } else if (MetatileBehavior_Is34(behavior)) {
        u32 sprite = MapObject_GetSpriteID(object) - 0xB2;
        if (sprite <= 1) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL MapObject_CheckSandBehavior(LocalMapObject *object, int behavior) {
    if (MetatileBehavior_IsSand(behavior)) {
        return TRUE;
    }
    return FALSE;
}

BOOL MapObject_CheckSnowBehavior(LocalMapObject *object, int behavior) {
    if (MetatileBehavior_IsSnow(behavior)) {
        return TRUE;
    }
    return FALSE;
}

BOOL MapObject_CheckSnowFootprintBehavior(LocalMapObject *object, int behavior) {
    if (MetatileBehavior_IsSnowForFootprints(behavior)) {
        return TRUE;
    }
    return FALSE;
}

BOOL MapObject_IsOnBridge(LocalMapObject *object, int behavior) {
    if (MapObject_CheckFlag28(object) == TRUE && MetatileBehavior_IsBridge(behavior) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

int GetDeltaXByFacingDirection(u32 direction) {
    return gDirectionDeltaX[direction];
}

int GetDeltaYByFacingDirection(u32 direction) {
    return gDirectionDeltaY[direction];
}

void MapObject_MoveCoordsInDirection(LocalMapObject *object, u32 direction) {
    MapObject_SetPreviousX(object, MapObject_GetXCoord(object));
    MapObject_SetPreviousY(object, MapObject_GetYCoord(object));
    MapObject_SetPreviousZ(object, MapObject_GetZCoord(object));
    MapObject_AddCurrentX(object, GetDeltaXByFacingDirection(direction));
    MapObject_AddCurrentY(object, 0);
    MapObject_AddCurrentZ(object, GetDeltaYByFacingDirection(direction));
}

void MapObject_SetPreviousCoordsToCurrent(LocalMapObject *object) {
    MapObject_SetPreviousX(object, MapObject_GetXCoord(object));
    MapObject_SetPreviousY(object, MapObject_GetYCoord(object));
    MapObject_SetPreviousZ(object, MapObject_GetZCoord(object));
}

int MapObject_GetMetatileBehaviorInDirection(LocalMapObject *object, int direction) {
    int x = MapObject_GetXCoord(object) + GetDeltaXByFacingDirection(direction);
    int z = MapObject_GetZCoord(object) + GetDeltaYByFacingDirection(direction);
    return GetMetatileBehavior(MapObject_GetFieldSystem(object), x, z);
}

u8 MapObject_GetTileAttrBits8To14InDirection(LocalMapObject *object, int direction) {
    int x = MapObject_GetXCoord(object) + GetDeltaXByFacingDirection(direction);
    int z = MapObject_GetZCoord(object) + GetDeltaYByFacingDirection(direction);
    int attr = FieldSystem_GetTileAttrBits8To14(MapObject_GetFieldSystem(object), x, z);
    return attr;
}

void MapObject_OffsetPositionInDirection(LocalMapObject *object, u32 direction, int distance) {
    VecFx32 position;
    MapObject_CopyPositionVector(object, &position);
    switch (direction) {
    case DIR_NORTH:
        position.z -= distance;
        break;
    case DIR_SOUTH:
        position.z += distance;
        break;
    case DIR_WEST:
        position.x -= distance;
        break;
    case DIR_EAST:
        position.x += distance;
        break;
    }
    MapObject_SetPositionVector(object, &position);
}

BOOL MapObject_UpdateHeight(LocalMapObject *object) {
    VecFx32 position;
    VecFx32 adjusted;
    BOOL result;

    MapObject_CopyPositionVector(object, &position);
    adjusted = position;
    if (MapObject_CheckIgnoreHeights(object) == TRUE) {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK12);
        return FALSE;
    }
    result = MapObject_CheckFlag29(object);
    result = FieldSystem_SnapToTerrainHeightEx(MapObject_GetFieldSystem(object), &adjusted, result);
    if (result == TRUE) {
        position.y = adjusted.y;
        MapObject_SetPositionVector(object, &position);
        MapObject_SetPreviousY(object, MapObject_GetYCoord(object));
        MapObject_SetCurrentY(object, (position.y >> 3) / FX32_ONE);
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK12);
    } else {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK12);
    }
    return result;
}

BOOL MapObject_UpdateMetatileBehaviors(LocalMapObject *object) {
    u8 previous = GetMetatileBehavior_None();
    u8 current = previous;
    if (!MapObject_CheckIgnoreMetatileBehaviors(object)) {
        FieldSystem *fieldSystem;
        int x;
        int z;
        x = MapObject_GetPreviousXCoord(object);
        z = MapObject_GetPreviousZCoord(object);
        fieldSystem = MapObject_GetFieldSystem(object);
        previous = GetMetatileBehavior(fieldSystem, x, z);
        x = MapObject_GetXCoord(object);
        z = MapObject_GetZCoord(object);
        current = GetMetatileBehavior(fieldSystem, x, z);
    }
    MapObject_SetPreviousMetatileBehavior(object, previous);
    MapObject_SetCurrentMetatileBehavior(object, current);
    if (MetatileBehavior_IsNone(current) == TRUE) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK11);
        return FALSE;
    }
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK11);
    return TRUE;
}

void OffsetPositionInDirection(int direction, VecFx32 *position, int distance) {
    switch (direction) {
    case DIR_NORTH:
        position->z -= distance;
        break;
    case DIR_SOUTH:
        position->z += distance;
        break;
    case DIR_WEST:
        position->x -= distance;
        break;
    case DIR_EAST:
        position->x += distance;
        break;
    }
}

void SetPositionToTileCenter(int x, int z, VecFx32 *position) {
    position->x = (x << 16) + FX32_CONST(8);
    position->z = (z << 16) + FX32_CONST(8);
}

void MapObject_UpdateHiddenMovement(LocalMapObject *object) {
    u32 movement = MapObject_GetMovement(object) - 0x33;
    if (movement <= 3) {
        MapObject_CallMovementUpdate(object);
    }
}

u32 GetOppositeDirection(u32 direction) {
    return gOppositeDirections[direction];
}

int GetDirectionTowards(int x, int z, int targetX, int targetZ) {
    if (x > targetX) {
        return DIR_WEST;
    }
    if (x < targetX) {
        return DIR_EAST;
    }
    if (z > targetZ) {
        return DIR_NORTH;
    }
    return DIR_SOUTH;
}

BOOL FieldSystem_SnapToTerrainHeight(FieldSystem *fieldSystem, VecFx32 *position) {
    u8 heightSource;
    int y = FieldSystem_GetTerrainHeight(fieldSystem, position->y, position->x, position->z, &heightSource);
    if (heightSource == CALCULATED_HEIGHT_SOURCE_NONE) {
        return FALSE;
    }
    position->y = y;
    return TRUE;
}

BOOL FieldSystem_SnapToTerrainHeightEx(FieldSystem *fieldSystem, VecFx32 *position, BOOL allowDynamicHeight) {
    u8 heightSource;
    int y = FieldSystem_GetTerrainHeight(fieldSystem, position->y, position->x, position->z, &heightSource);
    if (heightSource == CALCULATED_HEIGHT_SOURCE_NONE) {
        return FALSE;
    }
    if (heightSource == CALCULATED_HEIGHT_SOURCE_DYNAMIC && !allowDynamicHeight) {
        return FALSE;
    }
    position->y = y;
    return TRUE;
}
