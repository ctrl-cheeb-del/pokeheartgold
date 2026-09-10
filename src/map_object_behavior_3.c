#include "map_object_behavior_internal.h"

int sub_020643B8(LocalMapObject *o, int range, int targetX, int targetZ, int unusedX, int unusedZ) {
    int z, x = MapObject_GetXCoord(o);
    if (x == targetX) {
        z = MapObject_GetZCoord(o);
        if (targetZ < z && targetZ >= z - range) {
            return z - targetZ;
        }
    }
    return -1;
}

int sub_020643E4(LocalMapObject *o, int range, int targetX, int targetZ, int unusedX, int unusedZ) {
    int z, x = MapObject_GetXCoord(o);
    if (x == targetX) {
        z = MapObject_GetZCoord(o);
        if (targetZ > z && targetZ <= z + range) {
            return targetZ - z;
        }
    }
    return -1;
}

int sub_02064410(LocalMapObject *o, int range, int targetX, int targetZ, int unusedX, int unusedZ) {
    int x, z = MapObject_GetZCoord(o);
    if (z == targetZ) {
        x = MapObject_GetXCoord(o);
        if (targetX < x && targetX >= x - range) {
            return x - targetX;
        }
    }
    return -1;
}

int sub_0206443C(LocalMapObject *o, int range, int targetX, int targetZ, int unusedX, int unusedZ) {
    int x, z = MapObject_GetZCoord(o);
    if (z == targetZ) {
        x = MapObject_GetXCoord(o);
        if (targetX > x && targetX <= x + range) {
            return targetX - x;
        }
    }
    return -1;
}
