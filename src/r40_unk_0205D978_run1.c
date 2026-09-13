#include "r40_unk_0205D978_private.h"

void sub_0205D978(PlayerAvatar *avatar, MapObject *mapObject) {
    int movement;
    BOOL canMove = sub_0205D6B4(avatar);
    int direction = PlayerAvatar_GetNextFacingDirection(avatar);
    u32 collision = sub_0205DA34(avatar, mapObject, direction);

    if (collision & 4) {
        movement = sub_0206234C(direction, 0x38);
    } else if (collision & 0x40) {
        movement = sub_0206234C(direction, 0);
        PlayerAvatar_ClearUnk24ClearFlag2(avatar);
    } else if (collision != 0) {
        canMove = FALSE;
        movement = sub_0206234C(direction, 0x1C);
        if (!(collision & 8)) {
            PlaySE(SEQ_SE_DP_WALL_HIT);
        }
        MapObject_SetNextFacingDirection(mapObject, direction);
        PlayerAvatar_ClearUnk24ClearFlag2(avatar);
    } else {
        movement = sub_0205D658(avatar, direction);
    }

    if (!canMove) {
        PlayerAvatar_SetFlag2(avatar, FALSE);
    }
    sub_0205DA1C(avatar, mapObject, movement);
}
