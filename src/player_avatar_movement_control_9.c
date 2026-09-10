#include "player_avatar_movement_control_internal.h"

int sub_0205D658(PlayerAvatar *avatar, int value) {
    int movement = 0x4C;
    switch (PlayerAvatar_GetUnk24(avatar)) {
    case 1:
        movement = 0x10;
        break;
    case 2:
        movement = 0x50;
        break;
    case 3:
        movement = 0x14;
        break;
    }
    return sub_0206234C(value, movement);
}

BOOL sub_0205D684(PlayerAvatar *avatar) {
    int value = PlayerAvatar_Unk24AddWithCeiling(avatar, 1, 3);
    if (!PlayerAvatar_CheckFlag2(avatar) && value >= 2) {
        PlayerAvatar_SetFlag2(avatar, TRUE);
    }
    return value == 3;
}

BOOL sub_0205D6B4(PlayerAvatar *avatar) {
    int ret = TRUE;
    int value = PlayerAvatar_GetUnk24(avatar) - 1;
    if (value < 0) {
        value = 0;
        ret = FALSE;
    }
    PlayerAvatar_SetUnk24(avatar, value);
    if (PlayerAvatar_CheckFlag2(avatar) == TRUE && value == 0) {
        PlayerAvatar_SetFlag2(avatar, FALSE);
    }
    return ret;
}
