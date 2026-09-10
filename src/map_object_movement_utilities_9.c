#include "map_object_movement_utilities_internal.h"

BOOL sub_02061108(LocalMapObject *object) {
    int previous = GetMetatileBehavior_None();
    int current = previous;
    if (!sub_0205F8D0(object)) {
        void *fieldSystem;
        int x;
        int z;
        x = MapObject_GetPreviousXCoord(object);
        z = MapObject_GetPreviousZCoord(object);
        fieldSystem = MapObject_GetFieldSystem(object);
        previous = GetMetatileBehavior(fieldSystem, x, z);
        x = MapObject_GetXCoord(object);
        z = MapObject_GetZCoord(object);
        current = GetMetatileBehavior(fieldSystem, x, z);
    }
    sub_0205F50C(object, previous);
    sub_0205F4FC(object, current);
    if (MetatileBehavior_IsNone(current) == 1) {
        MapObject_SetFlagsBits(object, 2 << 10);
        return 0;
    }
    MapObject_ClearFlagsBits(object, 2 << 10);
    return 1;
}

void sub_02061190(int direction, VecFx32 *position, int distance) {
    switch (direction) {
    case 0:
        position->z -= distance;
        break;
    case 1:
        position->z += distance;
        break;
    case 2:
        position->x -= distance;
        break;
    case 3:
        position->x += distance;
        break;
    }
}

void sub_020611C8(int x, int z, VecFx32 *position) {
    position->x = (x << 16) + 0x8000;
    position->z = (z << 16) + 0x8000;
}

void sub_020611DC(LocalMapObject *object) {
    u32 movement = MapObject_GetMovement(object) - 0x33;
    if (movement <= 3) {
        sub_0205F430(object);
    }
}

u32 sub_020611F4(u32 direction) {
    return _020FD4DC[direction];
}

int sub_02061200(int x, int z, int targetX, int targetZ) {
    if (x > targetX) {
        return 2;
    }
    if (x < targetX) {
        return 3;
    }
    if (z > targetZ) {
        return 0;
    }
    return 1;
}

BOOL sub_0206121C(void *fieldSystem, MapPosition *position) {
    u8 behavior;
    int y = sub_02054940(fieldSystem, position->y, position->x, position->z, &behavior);
    if (behavior == 0) {
        return 0;
    }
    position->y = y;
    return 1;
}

BOOL sub_02061248(void *fieldSystem, MapPosition *position, BOOL allowType2) {
    u8 behavior;
    int y = sub_02054940(fieldSystem, position->y, position->x, position->z, &behavior);
    if (behavior == 0) {
        return 0;
    }
    if (behavior == 2 && allowType2 == 0) {
        return 0;
    }
    position->y = y;
    return 1;
}
