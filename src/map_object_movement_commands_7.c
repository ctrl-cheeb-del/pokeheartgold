#include "map_object_movement_commands_internal.h"

BOOL MapObjectMovementCmd069_Step0(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(0x200));
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd070_Step0(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(0x200));
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd071_Step0(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(0x80));
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd072_Step0(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(0x80));
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd073_Step0(LocalMapObject *object) {
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)(0x100));
    MapObject_IncrementMovementStep(object);
    return TRUE;
}

BOOL MapObjectMovementCmd074_Step0(LocalMapObject *object) {
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(0x100));
    MapObject_IncrementMovementStep(object);
    return TRUE;
}
