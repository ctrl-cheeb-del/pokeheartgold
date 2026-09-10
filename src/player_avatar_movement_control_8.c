#include "player_avatar_movement_control_internal.h"

void sub_0205D610(PlayerAvatar *avatar, MapObject *mapObject, int direction) {
    sub_0205DA1C(avatar, mapObject, sub_0206234C(direction, 0x28));
    MapObject_SetNextFacingDirection(mapObject, direction);
    PlayerAvatar_ResetUnkC(avatar);
    PlayerAvatar_ToggleUnkC(avatar);
}
