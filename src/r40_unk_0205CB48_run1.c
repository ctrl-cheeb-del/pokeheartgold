#include "r40_unk_0205CB48_private.h"

void PlayerAvatar_MoveControl(PlayerAvatar *avatar, MapLoadManager *mapLoadManager, int direction, u16 keys, u16 heldKeys, int allowTurn) {
    register MapLoadManager *manager = mapLoadManager;
    if (direction == -1) {
        direction = sub_0205DDD4(avatar, keys, heldKeys);
    }
    if (sub_0205CBEC(avatar, direction)) {
        sub_0205CC4C(avatar, direction, keys, heldKeys);
        Field_PlayerAvatar_ApplyTransitionFlags(avatar);
        if (sub_0205D004(avatar, direction) == TRUE) {
            ov01_021F2F24(avatar);
            return;
        }
        if (PlayerAvatar_GetState(avatar) == 0) {
            if (sub_0205D40C(avatar, direction)) {
                ov01_021F2F24(avatar);
            } else if (allowTurn == TRUE) {
                ov01_021F2EDC(avatar);
            }
        }
        sub_0205D340(avatar, manager, direction, keys, heldKeys);
        sub_0205CC74(avatar);
        sub_0205CC94(avatar);
    }
}

int sub_0205CBE4(PlayerAvatar *avatar, int direction, int a2, int a3) {
    return sub_0205CBEC(avatar, direction);
}

int sub_0205CBEC(PlayerAvatar *avatar, int direction) {
    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(avatar);

    if (MapObject_AreBitsSetForMovementScriptInit(mapObject) == TRUE) {
        return TRUE;
    }
    if (direction == -1) {
        return FALSE;
    }
    if (sub_0205DE64(MapObject_GetMovementCommand(mapObject)) == TRUE) {
        int result = sub_0205DA34(avatar, mapObject, direction);
        if (result == 0) {
            return TRUE;
        }
        if (result == 0x20 && PlayerAvatar_GetState(avatar) == 2) {
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}
