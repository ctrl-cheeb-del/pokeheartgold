#include "player_avatar_movement_control_internal.h"

BOOL sub_0205DFC8(PlayerAvatar *avatar) {
    return MapObject_AreBitsSetForMovementScriptInit(PlayerAvatar_GetMapObject(avatar));
}

void sub_0205DFD4(PlayerAvatar *avatar, int movement) {
    MapObject *mapObject = PlayerAvatar_GetMapObject(avatar);
    sub_0205DA1C(avatar, mapObject, movement);
}

void sub_0205DFEC(PlayerAvatar *avatar, int value) {
    sub_02060FA8(PlayerAvatar_GetMapObject(avatar), value);
}

void sub_0205DFFC(PlayerAvatar *avatar, int direction, int *x, int *z) {
    *x = PlayerAvatar_GetXCoord(avatar) + GetDeltaXByFacingDirection(direction);
    *z = PlayerAvatar_GetZCoord(avatar) + GetDeltaYByFacingDirection(direction);
}

void PlayerAvatar_GetCoordsInFront(PlayerAvatar *avatar, int *x, int *z) {
    int direction = PlayerAvatar_GetFacingDirection(avatar);
    sub_0205DFFC(avatar, direction, x, z);
}

void sub_0205E048(PlayerAvatar *avatar) {
    void *fieldSystem = MapObject_GetFieldSystem(PlayerAvatar_GetMapObject(avatar));
    void *stats = Save_GameStats_Get(*(void **)((u8 *)fieldSystem + 0xC));
    GameStats_Inc(stats, 0);
    if (PlayerAvatar_GetState(*(PlayerAvatar **)((u8 *)fieldSystem + 0x40)) == 1) {
        GameStats_Inc(stats, 1);
    }
}

BOOL sub_0205E078(PlayerAvatar *avatar, int direction, int value) {
    if (value != -1) {
        return FALSE;
    }
    if (PlayerAvatar_GetState(avatar) != 1) {
        return FALSE;
    }
    if (!PlayerAvatar_CheckBikeStateLocked(avatar)) {
        return FALSE;
    }
    if (sub_02060EEC(PlayerAvatar_GetMapObject(avatar), direction) == TRUE) {
        return TRUE;
    }
    return FALSE;
}
