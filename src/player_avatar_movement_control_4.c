#include "player_avatar_movement_control_internal.h"

BOOL sub_0205D07C(PlayerAvatar *avatar, int index, int value) {
    if (_020FCB7C[index](avatar, value) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

int sub_0205D09C(PlayerAvatar *avatar) {
    sub_0205D1FC(avatar);
    return 0;
}
