#include "map_object_movement_commands_internal.h"

BOOL MapObjectMovementCmd102_Step0(LocalMapObject *object) {
    sub_0205F3C0(object, 4);
    sub_0205F328(object, 0);
    MapObject_IncrementMovementStep(object);
    return FALSE;
}

BOOL MapObjectMovementCmd104_Step0(LocalMapObject *object) {
    sub_0205F3C0(object, 4);
    sub_0205F328(object, 1);
    MapObject_IncrementMovementStep(object);
    return FALSE;
}
