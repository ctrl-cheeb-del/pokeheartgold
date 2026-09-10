#include "player_avatar_movement_control_internal.h"

void sub_0205CFBC(PlayerAvatar *avatar, int direction) {
    MapObject *mapObject;
    PlayerAvatar_SetMoveState(avatar, 0);
    PlayerAvatar_SetPlayerMoveState(avatar, 0);
    mapObject = PlayerAvatar_GetMapObject(avatar);
    MapObject_SetFacingDirection(mapObject, direction);
    sub_0205F328(mapObject, 0);
    sub_02060F78(mapObject);
    MapObject_ClearHeldMovement(mapObject);
    MapObject_SetHeldMovement(mapObject, sub_0206234C(direction, 0));
}

BOOL sub_0205D004(PlayerAvatar *avatar, int value) {
    int index = sub_0205D01C(avatar, value);
    return sub_0205D07C(avatar, index, value);
}
