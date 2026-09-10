#include "map_object_movement_utilities_internal.h"

void sub_02060698(LocalMapObject *object, u8 behavior) {
    int id = MapObject_GetID(object);
    if (MetatileBehavior_IsVeryTallGrass(behavior) == 1 && (id != 0xFD || MapObject_TestFlagsBits(object, 2 << 8) != 1)) {
        ov01_021FF8F0(object, 0);
    }
}

void sub_020606CC(LocalMapObject *object, u8 behavior) {
    int id = MapObject_GetID(object);
    if (MetatileBehavior_IsVeryTallGrass(behavior) == 1 && (id != 0xFD || MapObject_TestFlagsBits(object, 2 << 8) != 1)) {
        ov01_021FF8F0(object, 1);
    }
}

void sub_02060700(LocalMapObject *object) {
}

void sub_02060704(LocalMapObject *object) {
}

void sub_02060708(LocalMapObject *object, u8 unused, u8 behavior) {
    if (MetatileBehavior_IsPuddle(behavior) == 1) {
        int x = MapObject_GetPreviousXCoord(object);
        int y = MapObject_GetPreviousYCoord(object);
        int z = MapObject_GetPreviousZCoord(object);
        ov01_021FECA0(object, x, y, z);
    }
}

void sub_0206073C(LocalMapObject *object, u8 behavior) {
    if (MetatileBehavior_IsPuddle(behavior) == 1) {
        int x = MapObject_GetXCoord(object);
        int y = MapObject_GetYCoord(object);
        int z = MapObject_GetZCoord(object);
        ov01_021FECA0(object, x, y, z);
    }
}

void sub_02060770(LocalMapObject *object, u8 unused, u8 behavior) {
    if (MetatileBehavior_IsMud(behavior) == 1) {
        int x = MapObject_GetPreviousXCoord(object);
        int y = MapObject_GetPreviousYCoord(object);
        int z = MapObject_GetPreviousZCoord(object);
        ov01_021FEE04(object, x, y, z);
    }
}

void sub_020607A4(LocalMapObject *object, u8 behavior) {
    if (MetatileBehavior_IsMud(behavior) == 1) {
        int x = MapObject_GetXCoord(object);
        int y = MapObject_GetYCoord(object);
        int z = MapObject_GetZCoord(object);
        ov01_021FEE04(object, x, y, z);
    }
}
