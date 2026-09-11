#include "unk_02060BFC_internal.h"

BOOL sub_02060BFC(LocalMapObject *self, int x, int y, int z) {
    MapObjectManager *manager = MapObject_GetManager(self);
    LocalMapObject *object = MapObjectManager_GetObjects2(manager);
    int count = MapObjectManager_GetObjectCount(manager);

    do {
        if (object != self && MapObject_GetFlagsBitsMask(object, 1) != 0 && MapObject_GetFlagsBitsMask(object, 1 << 18) == 0) {
            int objectX = MapObject_GetXCoord(object);
            int objectZ = MapObject_GetZCoord(object);
            if (objectX == x && objectZ == z) {
                int delta = MapObject_GetYCoord(object) - y;
                if (delta < 0) {
                    delta = -delta;
                }
                if (delta < 2) {
                    return TRUE;
                }
            }
            objectX = MapObject_GetPreviousXCoord(object);
            objectZ = MapObject_GetPreviousZCoord(object);
            if (objectX == x && objectZ == z) {
                int delta = MapObject_GetYCoord(object) - y;
                if (delta < 0) {
                    delta = -delta;
                }
                if (delta < 2) {
                    return TRUE;
                }
            }
        }
        MapObjectArray_NextObject(&object);
        count--;
    } while (count != 0);
    return FALSE;
}

BOOL sub_02060CA8(LocalMapObject *self, int x, int y, int z) {
    int objectX;
    int objectZ;
    MapObjectManager *manager = MapObject_GetManager(self);
    LocalMapObject *object = MapObjectManager_GetObjects2(manager);
    int count = MapObjectManager_GetObjectCount(manager);

    do {
        if (object != self && MapObject_GetFlagsBitsMask(object, 1) != 0) {
            objectX = MapObject_GetXCoord(object);
            objectZ = MapObject_GetZCoord(object);
            if (objectX == x && objectZ == z) {
                int delta = MapObject_GetYCoord(object) - y;
                if (delta < 0) {
                    delta = -delta;
                }
                if (delta < 2) {
                    return TRUE;
                }
            }
            objectX = MapObject_GetPreviousXCoord(object);
            objectZ = MapObject_GetPreviousZCoord(object);
            if (objectX == x && objectZ == z) {
                int delta = MapObject_GetYCoord(object) - y;
                if (delta < 0) {
                    delta = -delta;
                }
                if (delta < 2) {
                    return TRUE;
                }
            }
            if (MapObject_GetID(object) == 0xFD && ov01_022055DC(object) != 0 && MapObject_CheckVisible(object) == FALSE) {
                ov01_02205664(object, &objectX, &objectZ);
                if (objectX == x && objectZ == z) {
                    int delta = MapObject_GetYCoord(object) - y;
                    if (delta < 0) {
                        delta = -delta;
                    }
                    if (delta < 2) {
                        return TRUE;
                    }
                }
            }
        }
        MapObjectArray_NextObject(&object);
        count--;
    } while (count != 0);
    return FALSE;
}

BOOL sub_02060D94(LocalMapObject *object, int x, int unused, int z) {
    int initialX = MapObject_GetInitialX(object);
    int rangeX = MapObject_GetXRange(object);
    if (rangeX != -1) {
        int maxX = initialX + rangeX;
        int minX = initialX - rangeX;
        if (minX > x || maxX < x) {
            return TRUE;
        }
    }
    {
        int initialZ = MapObject_GetInitialZ(object);
        int rangeZ = MapObject_GetYRange(object);
        if (rangeZ != -1) {
            int maxZ = initialZ + rangeZ;
            int minZ = initialZ - rangeZ;
            if (minZ > z || maxZ < z) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL sub_02060DEC(LocalMapObject *object, int x, int z, int direction) {
    if (sub_0205F8D0(object) == FALSE) {
        void *fieldSystem = MapObject_GetFieldSystem(object);
        u8 objectBehavior = sub_0205F504(object);
        int behavior = GetMetatileBehavior(fieldSystem, x, z);
        if (behavior == GetMetatileBehavior_None()) {
            return TRUE;
        }
        if (_020FD4CC[direction](objectBehavior) == TRUE || _020FD4BC[direction](behavior) == TRUE) {
            return TRUE;
        }
    }
    return FALSE;
}
