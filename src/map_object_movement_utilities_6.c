#include "map_object_movement_utilities_internal.h"

void sub_02060AB8(LocalMapObject *object, int behavior, int a2, int a3) {
    if (sub_0205BA24(behavior) == 1) {
        MapObject_SetFlag28(object, 1);
    } else if (MapObject_CheckFlag28(object) == 1 && sub_0205BA30(behavior) == 0) {
        MapObject_SetFlag28(object, 0);
    }
}

void sub_02060AF0(LocalMapObject *object, int a1, int a2, int a3) {
}
