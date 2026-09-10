#include "player_avatar_movement_control_internal.h"

BOOL sub_0205DCA0(void *unused, MapObject *mapObject, int direction) {
    void *fieldSystem;
    int x;
    int dx;
    int z;
    int dz;
    u32 behavior;
    if (direction != -1) {
        fieldSystem = MapObject_GetFieldSystem(mapObject);
        x = MapObject_GetXCoord(mapObject);
        dx = GetDeltaXByFacingDirection(direction);
        z = MapObject_GetZCoord(mapObject);
        dz = GetDeltaYByFacingDirection(direction);
        behavior = GetMetatileBehavior(fieldSystem, x + dx, z + dz);
        if (sub_02060E54(mapObject, behavior) != FALSE) {
            return TRUE;
        }
    }
    return FALSE;
}
