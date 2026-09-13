#include "r40_unk_0205DDD4_private.h"

int sub_0205DDD4(PlayerAvatar *avatar, int unused, int keys) {
    int vertical = sub_0205DD9C(keys);
    int horizontal = sub_0205DDB8(keys);
    int facing;
    int previousVertical;
    int previousHorizontal;

    (void)unused;
    if (vertical == -1) {
        return horizontal;
    }
    if (horizontal == -1) {
        return vertical;
    }

    facing = PlayerAvatar_GetNextFacingDirection(avatar);
    previousVertical = PlayerAvatar_GetUnk28(avatar);
    previousHorizontal = PlayerAvatar_GetUnk2C(avatar);
    if (facing != -1) {
        if (vertical == previousVertical && horizontal == previousHorizontal) {
            return facing;
        }
        if (horizontal != previousHorizontal) {
            return horizontal;
        }
        return vertical;
    }
    return horizontal;
}
