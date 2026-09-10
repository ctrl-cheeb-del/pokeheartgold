#include "player_avatar_movement_control_internal.h"

int sub_0205DD94(PlayerAvatar *avatar, int unused, int keys) {
    return sub_0205DDD4(avatar, unused, keys);
}

int sub_0205DD9C(int keys) {
    if (keys & 0x20) {
        return 2;
    }
    if (keys & 0x10) {
        return 3;
    }
    return -1;
}

int sub_0205DDB8(int keys) {
    if (keys & 0x40) {
        return 0;
    }
    if (keys & 0x80) {
        return 1;
    }
    return -1;
}
