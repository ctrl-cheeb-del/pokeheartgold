#include "r40_unk_0205D83C_private.h"

void sub_0205D83C(PlayerAvatar *avatar, LocalMapObject *mapObject, int direction) {
    u32 result = sub_0205DA34(avatar, mapObject, direction);
    int movement;

    if (result & 4) {
        movement = sub_0206234C(direction, 0x38);
        sub_0205D684(avatar);
        sub_0205E048(avatar);
        PlayerAvatar_SetFlag6(avatar);
    } else if (result & 0x10) {
        if (PlayerAvatar_GetUnk24(avatar) >= 3) {
            movement = sub_0205D658(avatar, direction);
            PlayerAvatar_SetFlag6(avatar);
            PlayerAvatar_SetForcedMovement(avatar, TRUE);
        } else {
            movement = sub_0206234C(direction, 0x1C);
            if (!(result & 8)) {
                PlaySE(0x600);
            }
            MapObject_SetNextFacingDirection(mapObject, direction);
            PlayerAvatar_ClearUnk24ClearFlag2(avatar);
        }
    } else if (result & 0x40) {
        int facing = MapObject_GetNextFacingDirection(mapObject);
        movement = sub_0206234C(facing, 0);
        MapObject_SetNextFacingDirection(mapObject, facing);
        PlayerAvatar_ClearUnk24ClearFlag2(avatar);
        PlayerAvatar_SetUnk28Unk2C(avatar, -1, -1);
    } else if (result != 0) {
        movement = sub_0206234C(direction, 0x1C);
        if (!(result & 8)) {
            PlaySE(0x600);
        }
        MapObject_SetNextFacingDirection(mapObject, direction);
        PlayerAvatar_ClearUnk24ClearFlag2(avatar);
    } else {
        movement = sub_0205D658(avatar, direction);
        sub_0205D684(avatar);
        sub_0205E048(avatar);
        PlayerAvatar_SetFlag6(avatar);
    }
    sub_0205DA1C(avatar, mapObject, movement);
}
