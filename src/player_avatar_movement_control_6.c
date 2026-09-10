#include "player_avatar_movement_control_internal.h"

int sub_0205D40C(PlayerAvatar *avatar, int direction) {
    int value = sub_0205D450(avatar, direction);
    PlayerAvatar_SetMoveState(avatar, sub_0205D428(value));
    return value;
}

int sub_0205D428(int value) {
    switch (value) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        GF_AssertFail();
        return 0;
    }
}

int sub_0205D44C(int a0, int a1, int a2) {
    return a2;
}
