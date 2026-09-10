#include "player_avatar_movement_control_internal.h"

void sub_0205DA1C(PlayerAvatar *avatar, MapObject *mapObject, int movement) {
    PlayerAvatar_SetUnk8(avatar, movement);
    MapObject_SetHeldMovement(mapObject, movement);
}
