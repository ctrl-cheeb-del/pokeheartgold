#include "r40_unk_0205D01C_private.h"

int sub_0205D01C(PlayerAvatar *avatar, int value) {
    int i = 0;
    int behavior = sub_0205F504(PlayerAvatar_GetMapObject(avatar));
    if (sub_0205E078(avatar, behavior, value) == TRUE) {
        return 2;
    }
    if (PlayerAvatar_CheckFlag1(avatar) == TRUE) {
        return 0;
    }
    do {
        if (_020FCB88[i].predicate((u8)behavior) == TRUE) {
            return _020FCB88[i].result;
        }
        i++;
    } while (_020FCB88[i].predicate != NULL);
    return 0;
}
