#include "r40_unk_0205CF60_private.h"

BOOL sub_0205CF60(PlayerAvatar *avatar) {
    int moveState = PlayerAvatar_GetMoveState(avatar);
    int playerMoveState = PlayerAvatar_GetPlayerMoveState(avatar);
    MapObject *mapObject;

    if (moveState == 0) {
        return TRUE;
    }
    if (moveState == 2) {
        return TRUE;
    }
    if (moveState == 1) {
        if (playerMoveState == 0 || playerMoveState == 3) {
            return TRUE;
        }
        mapObject = PlayerAvatar_GetMapObject(avatar);
        if (MapObject_AreBitsSetForMovementScriptInit(mapObject) == TRUE) {
            return TRUE;
        }
        if (sub_0205DE64(MapObject_GetMovementCommand(mapObject)) == TRUE) {
            return TRUE;
        }
    }
    return FALSE;
}
