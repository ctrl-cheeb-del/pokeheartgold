#include "r40_unk_0205D0A8_private.h"

BOOL sub_0205D0A8(PlayerAvatar *avatar, int unused) {
    MapObject *mapObject = PlayerAvatar_GetMapObject(avatar);
    int direction = MapObject_GetNextFacingDirection(mapObject);
    int vertical = sub_0205D240(avatar, (void *)direction);
    u32 collision = sub_0205DA34(avatar, mapObject, direction);

    PlayerAvatar_SetForcedMovement(avatar, TRUE);
    if (collision != 0) {
        void *fieldSystem = MapObject_GetFieldSystem(mapObject);
        PlayerAvatar_SetFlag1(avatar, TRUE);
        PlayerAvatar_SetMoveState(avatar, 0);
        if (sub_0206D494(fieldSystem) == 0) {
            sub_0205D1FC(avatar);
            return FALSE;
        }
        return TRUE;
    }
    if (sub_0205D2A0(avatar, vertical) == FALSE) {
        sub_0205D1FC(avatar);
        direction = sub_020611F4(direction);
        if (sub_0205DA34(avatar, mapObject, direction) != 0) {
            return FALSE;
        }
        MapObject_SetFlagsBits(mapObject, 0x180);
        sub_0205DA1C(avatar, mapObject, sub_0206234C(direction, 8));
        PlayerAvatar_SetFlag1(avatar, TRUE);
        PlayerAvatar_SetForcedMovement(avatar, TRUE);
        PlayerAvatar_SetUnk28Unk2C(avatar, -1, -1);
    } else {
        MapObject_SetFlagsBits(mapObject, 0x180);
        sub_0205D2D0(avatar, direction);
    }
    PlayerAvatar_SetMoveState(avatar, 1);
    return TRUE;
}

BOOL sub_0205D190(PlayerAvatar *avatar) {
    MapObject *mapObject = PlayerAvatar_GetMapObject(avatar);
    if (sub_0205DA34(avatar, mapObject, 1) == 0) {
        sub_0205DA1C(avatar, mapObject, sub_0206234C(1, 0x14));
        PlayerAvatar_SetMoveState(avatar, 1);
        PlayerAvatar_SetUnk24(avatar, 3);
        return TRUE;
    }
    sub_0205DA1C(avatar, mapObject, sub_0206234C(1, 1));
    PlayerAvatar_ClearUnk24ClearFlag2(avatar);
    PlayerAvatar_SetMoveState(avatar, 0);
    PlayerAvatar_SetFlag2(avatar, FALSE);
    return TRUE;
}
