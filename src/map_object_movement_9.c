#include "map_object_movement_internal.h"

void sub_020620F8(LocalMapObject *object, u8 *state) {
    if (state[2] == 0) {
        MapObject_ClearFlagsBits(object, (MapObjectFlagBits)0x80);
    }
}
