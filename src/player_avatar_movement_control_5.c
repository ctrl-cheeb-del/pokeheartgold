#include "player_avatar_movement_control_internal.h"

void sub_0205D1FC(PlayerAvatar *avatar) {
    if (PlayerAvatar_CheckForcedMovement(avatar) == TRUE) {
        MapObject_ClearFlagsBits(PlayerAvatar_GetMapObject(avatar), 0x180);
        if (!PlayerAvatar_CheckFlag7(avatar)) {
            PlayerAvatar_ClearUnk24ClearFlag2(avatar);
        }
        PlayerAvatar_SetForcedMovement(avatar, FALSE);
        PlayerAvatar_SetFlag7(avatar, FALSE);
        PlayerAvatar_SetFlag5(avatar, FALSE);
    }
}

int sub_0205D240(PlayerAvatar *avatar, void *arg) {
    MapObject *mapObject = PlayerAvatar_GetMapObject(avatar);
    void *fieldSystem = MapObject_GetFieldSystem(mapObject);
    VecFx32 original;
    VecFx32 position;
    MapObject_CopyPositionVector(mapObject, &original);
    position = original;
    sub_02061190(arg, &position, 1 << 14);
    if (!sub_0206121C(fieldSystem, &position) || original.y == position.y) {
        return 0;
    }
    if (original.y > position.y) {
        return 2;
    }
    return 1;
}

BOOL sub_0205D2A0(PlayerAvatar *avatar, int direction) {
    int value = PlayerAvatar_GetUnk24(avatar);
    if (direction == 1) {
        value--;
        if (value < 0) {
            return FALSE;
        }
    } else if (direction == 2) {
        value++;
        if (value > 3) {
            value = 3;
        }
    }
    PlayerAvatar_SetUnk24(avatar, value);
    return TRUE;
}

void sub_0205D2D0(PlayerAvatar *avatar, int direction) {
    MapObject *mapObject = PlayerAvatar_GetMapObject(avatar);
    int movement = 0x10;
    int command;
    void *fieldSystem;
    switch (PlayerAvatar_GetUnk24(avatar)) {
    case 1:
        movement = 0x50;
        break;
    case 2:
        movement = 0x14;
        break;
    case 3:
        movement = 0x14;
        break;
    }
    command = sub_0206234C(direction, movement);
    sub_0205DA1C(avatar, mapObject, command);
    fieldSystem = MapObject_GetFieldSystem(mapObject);
    if (FollowMon_IsActive(fieldSystem)) {
        int x = MapObject_GetPreviousXCoord(mapObject);
        int z = MapObject_GetPreviousZCoord(mapObject);
        ov01_02205990(command, x, z, (u8 *)fieldSystem + 0xE4);
    }
}
