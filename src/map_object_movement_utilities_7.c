#include "map_object_movement_utilities_internal.h"

void sub_02060B90(LocalMapObject *object, int a1, int a2, int a3, int a4) {
    VecFx32 position;
    MapObject_CopyPositionVector(object, &position);
    sub_02060AF4(object, &position, a1, a2, a3, a4);
}

void sub_02060BB8(LocalMapObject *object, int direction) {
    int x = MapObject_GetXCoord(object) + GetDeltaXByFacingDirection(direction);
    int y = MapObject_GetYCoord(object);
    int z = MapObject_GetZCoord(object) + GetDeltaYByFacingDirection(direction);
    sub_02060B90(object, x, y, z, direction);
}
