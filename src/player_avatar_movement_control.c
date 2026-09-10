#include "player_avatar_movement_control_internal.h"

void sub_0205CC4C(PlayerAvatar *avatar, int unused1, int unused2, int keys) {
    int vertical = sub_0205DD9C(keys);
    int horizontal = sub_0205DDB8(keys);
    PlayerAvatar_SetUnk28Unk2C(avatar, vertical, horizontal);
    PlayerAvatar_ClearFlag6(avatar);
}

void sub_0205CC74(PlayerAvatar *avatar) {
    if (PlayerAvatar_CheckFlag6(avatar) == TRUE && PlayerAvatar_GetMoveState(avatar) == 1) {
        PlayerAvatar_SetFlag1(avatar, FALSE);
    }
}
