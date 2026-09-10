#include "map_object_behavior_internal.h"

BOOL sub_02063A94(LocalMapObject *object) {
    int x = MapObject_GetXCoord(object);
    if (x != MapObject_GetPreviousXCoord(object)) {
        return TRUE;
    }
    x = MapObject_GetZCoord(object);
    if (x != MapObject_GetPreviousZCoord(object)) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02063AC8(LocalMapObject *object) {
    int x = MapObject_GetXCoord(object);
    if (x != MapObject_GetPreviousXCoord(object)) {
        return FALSE;
    }
    x = MapObject_GetZCoord(object);
    if (x == MapObject_GetPreviousZCoord(object)) {
        return TRUE;
    }
    return FALSE;
}
