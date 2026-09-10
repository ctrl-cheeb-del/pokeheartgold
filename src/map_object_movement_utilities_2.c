#include "map_object_movement_utilities_internal.h"

void sub_02060020(LocalMapObject *object) {
    sub_02061108(object);
    if (sub_0205F73C(object) == 1) {
        u8 previous = sub_0205F504(object);
        u8 current = sub_0205F514(object);
        int effect = ov01_021F9318(object);
        sub_02060AB8(object, previous, current, effect);
        sub_020603F8(object, previous, current, effect);
        sub_020607D8(object, previous, current, effect);
        sub_020603D0(object, previous, current, effect);
        sub_02060AF0(object, previous, current, effect);
    }
}
