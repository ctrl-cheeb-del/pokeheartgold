#include "to46_map_object_followup_private.h"

BOOL sub_02065F44(LocalMapObject *object) {
    PlayerAvatar *avatar = FieldSystem_GetPlayerAvatar(MapObject_GetFieldSystem(object));
    int x = MapObject_GetXCoord(object);
    int z = MapObject_GetZCoord(object);
    int previousX = PlayerAvatar_GetPreviousXCoord(avatar);
    int previousZ = PlayerAvatar_GetPreviousZCoord(avatar);

    if (x != previousX || z != previousZ) {
        int movement = sub_02065DB4(object);
        int direction = sub_02061200(x, z, previousX, previousZ);
        if (movement == 0xff) {
            GF_AssertFail();
            return FALSE;
        }
        MapObject_ForceSetHeldMovement(object, sub_0206234C(direction, movement));
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02065FBC(LocalMapObject *object) {
    PlayerAvatar *avatar = FieldSystem_GetPlayerAvatar(MapObject_GetFieldSystem(object));
    MapObject_GetXCoord(object);
    MapObject_GetZCoord(object);
    PlayerAvatar_GetPreviousXCoord(avatar);
    PlayerAvatar_GetPreviousZCoord(avatar);
    {
        int movement = sub_02065DB4(object);
        if (movement == 0xff) {
            return FALSE;
        }
        MapObject_ForceSetHeldMovement(object, movement);
    }
    return TRUE;
}
