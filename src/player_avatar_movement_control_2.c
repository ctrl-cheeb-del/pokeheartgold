#include "player_avatar_movement_control_internal.h"

void sub_0205CF44(PlayerAvatar *avatar) {
    PlayerAvatar_SetMoveState(avatar, 0);
    PlayerAvatar_SetPlayerMoveState(avatar, 0);
    PlayerAvatar_ClearUnk24ClearFlag2(avatar);
}
