#include "r40_unk_0205D450_private.h"

s32 sub_0205D450(PlayerAvatar *avatar, s32 direction) {
    s32 facingDirection;
    if (direction == -1) {
        PlayerAvatar_SetMoveState(avatar, 0);
        return 0;
    }
    facingDirection = PlayerAvatar_GetFacingDirection(avatar);
    if (facingDirection != direction) {
        if (PlayerAvatar_GetMoveState(avatar) != 1) {
            PlayerAvatar_SetMoveState(avatar, 2);
            return 2;
        }
    }
    PlayerAvatar_SetMoveState(avatar, 1);
    return 1;
}
