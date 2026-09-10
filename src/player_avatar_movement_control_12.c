#include "player_avatar_movement_control_internal.h"

void sub_0205D948(PlayerAvatar *avatar, MapObject *mapObject, int direction) {
    PlayerAvatar_ClearUnk24ClearFlag2(avatar);
    sub_0205DA1C(avatar, mapObject, sub_0206234C(direction, 0x28));
    MapObject_SetNextFacingDirection(mapObject, direction);
    PlayerAvatar_ClearUnk24ClearFlag2(avatar);
}
