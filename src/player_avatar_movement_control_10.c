#include "player_avatar_movement_control_internal.h"

int sub_0205D75C(PlayerAvatar *avatar, int direction) {
    int result = sub_0205D7AC(avatar, direction);
    PlayerAvatar_SetMoveState(avatar, sub_0205D778(result));
    return result;
}

int sub_0205D778(int value) {
    switch (value) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 1;
    default:
        GF_AssertFail();
        return 0;
    }
}
