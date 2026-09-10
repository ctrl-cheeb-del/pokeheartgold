#include "player_avatar_movement_control_internal.h"

void sub_0205D818(PlayerAvatar *avatar, MapObject *mapObject) {
    int movement = sub_0206234C(MapObject_GetFacingDirection(mapObject), 0);
    sub_0205DA1C(avatar, mapObject, movement);
    PlayerAvatar_ClearUnk24ClearFlag2(avatar);
}
