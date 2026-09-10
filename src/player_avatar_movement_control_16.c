#include "player_avatar_movement_control_internal.h"

BOOL sub_0205DE38(PlayerAvatar *avatar) {
    MapObject *mapObject = PlayerAvatar_GetMapObject(avatar);
    if (MapObject_AreBitsSetForMovementScriptInit(mapObject) == TRUE) {
        return TRUE;
    }
    if (sub_0205DE64(MapObject_GetMovementCommand(mapObject)) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_0205DE64(int value) {
    switch (value) {
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x1F:
        return TRUE;
    default:
        return FALSE;
    }
}

BOOL sub_0205DE88(int a0, int flags) {
    return (flags & 2) != 0;
}

BOOL sub_0205DE98(PlayerAvatar *avatar) {
    switch (PlayerAvatar_GetUnk8(avatar)) {
    case 0x58:
    case 0x59:
    case 0x5A:
    case 0x5B:
        return TRUE;
    default:
        return FALSE;
    }
}

int sub_0205DEC0(PlayerAvatar *avatar, int direction) {
    int result;
    switch (PlayerAvatar_GetState(avatar)) {
    case 0:
    case 2:
    case 3:
        result = sub_0205D428(sub_0205D450(avatar, direction));
        break;
    case 1:
        result = sub_0205D778(sub_0205D7AC(avatar, direction));
        break;
    default:
        result = 0;
        GF_AssertFail();
        break;
    }
    return result;
}
