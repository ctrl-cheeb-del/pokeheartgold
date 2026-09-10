#include "map_object_movement_utilities_internal.h"

void sub_0206039C(LocalMapObject *object, u8 behavior) {
    if (MetatileBehavior_IsShallowWater(behavior) == 1) {
        if (MapObject_CheckFlag26(object) == 0) {
            ov01_021FF4FC(object, 1);
            MapObject_SetFlag26(object, 1);
        }
    } else {
        MapObject_SetFlag26(object, 0);
    }
}

void sub_020603D0(LocalMapObject *object, int a1, int a2, int a3) {
    MapObject_SetFlag26(object, 0);
}

void sub_020603DC(LocalMapObject *object, int a1, int unused, int a3) {
    u8 value = sub_0205F524(object);
    sub_020603F8(object, a1, value, a3);
}
