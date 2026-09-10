#include "map_object_movement_commands_internal.h"

BOOL MapObject_AreBitsSetForMovementScriptInit(LocalMapObject *object) {
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_ACTIVE)) {
        return FALSE;
    }
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_SINGLE_MOVEMENT) == TRUE) {
        return FALSE;
    }
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK4) == TRUE
        && !MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK5)) {
        return FALSE;
    }
    return TRUE;
}

void MapObject_SetHeldMovement(LocalMapObject *object, u32 movement) {
    if ((int)movement >= 0x71) {
        GF_AssertFail();
    }
    MapObject_SetMovementCommand(object, movement);
    MapObject_SetMovementStep(object, 0);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK4);
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK5);
}

void MapObject_ForceSetHeldMovement(LocalMapObject *object, u32 movement) {
    MapObject_SetMovementCommand(object, movement);
    MapObject_SetMovementStep(object, 0);
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK5);
}

BOOL MapObject_IsMovementPaused(LocalMapObject *object) {
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK4)) {
        return TRUE;
    }
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK5)) {
        return TRUE;
    }
    return FALSE;
}

BOOL MapObject_ClearHeldMovementIfActive(LocalMapObject *object) {
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK4)) {
        return TRUE;
    }
    if (!MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK5)) {
        return FALSE;
    }
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK4 | MAPOBJECTFLAG_UNK5));
    return TRUE;
}

void MapObject_ClearHeldMovement(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK4);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK5);
    MapObject_SetMovementCommand(object, 0xFF);
    MapObject_SetMovementStep(object, 0);
}
