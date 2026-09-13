#include "r40_unk_02064824_private.h"

BOOL sub_02064824(TrainerApproachWork *work) {
    LocalMapObject *obj = PlayerAvatar_GetMapObject(work->player);
    int x = MapObject_GetXCoord(obj);
    int z = MapObject_GetZCoord(obj);
    int tx = MapObject_GetXCoord(work->trainer);
    int tz = MapObject_GetZCoord(work->trainer);
    int direction = sub_02061200(x, z, tx, tz);
    if (direction != PlayerAvatar_GetFacingDirection(work->player) && (work->unk18 == 0 || work->unk14 == 2)) {
        if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
            MapObject_ClearFlagsBits(obj, (MapObjectFlagBits)0x80);
            MapObject_SetHeldMovement(obj, sub_0206234C(direction, 0));
            work->state = 15;
        }
    } else {
        work->state = 16;
    }
    return FALSE;
}
