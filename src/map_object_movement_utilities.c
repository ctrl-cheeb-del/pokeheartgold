#include "map_object_movement_utilities_internal.h"

void sub_0205FD20(LocalMapObject *object) {
    sub_0205F41C(object);
    sub_02063A14(object);
}

void sub_0205FD30(LocalMapObject *object) {
    if (sub_0205F5E8(object, 2) == 0) {
        sub_0205FE0C(object);
        sub_0205FE24(object);
        sub_0205FE48(object);
        if (MapObject_GetFlagsBitsMask(object, 0x10)) {
            sub_02062400(object);
        } else if (!MapObject_CheckMovementPaused(object) && sub_0205FD98(object) == 1 && !sub_02063A1C(object)) {
            sub_0205F430(object);
        }
        sub_0205FE6C(object);
        sub_0205FEA4(object);
    }
}

BOOL sub_0205FD98(LocalMapObject *object) {
    u32 flags;
    if (MapObject_CheckSingleMovement(object) == 1) {
        return 1;
    }
    if (!MapObject_GetFlagsBitsMask(object, 6 << 10)) {
        return 1;
    }
    if (MapObject_GetMovement(object) == 0x32) {
        return 1;
    }
    if (MapObject_GetMovement(object) == 0x30) {
        return 1;
    }
    flags = MapObject_GetFlags(object);
    if ((flags & (1 << 12)) && !(flags & (1 << 23))) {
        return 0;
    }
    if ((flags & (2 << 10)) && !sub_0205F8D0(object)) {
        return 0;
    }
    return 1;
}

void sub_0205FE0C(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, 1 << 12)) {
        sub_02061070(object);
    }
}

void sub_0205FE24(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, 2 << 10) && sub_02061108(object) == 1) {
        MapObject_SetStartMovement(object);
    }
}

void sub_0205FE48(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, 4)) {
        sub_0205FEDC(object);
    }
    MapObject_ClearFlagsBits(object, 0x10004);
}

void sub_0205FE6C(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, 1 << 16)) {
        sub_02060020(object);
    } else if (MapObject_GetFlagsBitsMask(object, 4)) {
        sub_0205FF6C(object);
    }
    MapObject_ClearFlagsBits(object, 0x10004);
}

void sub_0205FEA4(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, 2 << 16)) {
        sub_02060114(object);
    } else if (MapObject_GetFlagsBitsMask(object, 8)) {
        sub_0206008C(object);
    }
    MapObject_ClearFlagsBits(object, 0x20008);
}
