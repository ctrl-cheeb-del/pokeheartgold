#include "map_object_movement_commands_internal.h"

BOOL MapObjectMovementCmd100_Step0(LocalMapObject *object) {
    sub_0205F3C0(object, 4);
    sub_0205F328(object, 9);
    MapObject_IncrementMovementStep(object);
    return FALSE;
}
