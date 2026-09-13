#include "r40_unk_0205D4B4_private.h"

void sub_0205D4B4(PlayerAvatar *avatar, MapObject *object, int direction, int unused, u16 keys) {
    int turn = 0;
    int movement;
    int collision = sub_0205DA34(avatar, object, direction);

    if (PlayerAvatar_GetState(avatar) != 2) {
        if (collision & 4) {
            movement = 0x38;
        } else if (collision != 0) {
            movement = 0x1C;
            if (!(collision & 8)) {
                void *fieldSystem = MapObject_GetFieldSystem(object);
                if (FieldSystem_IsSaveGymmickTypeEqualTo(fieldSystem, 7)) {
                    int x = MapObject_GetXCoord(object);
                    int dx = GetDeltaXByFacingDirection(direction);
                    int z = MapObject_GetZCoord(object);
                    int dz = GetDeltaYByFacingDirection(direction);
                    FuchsiaGymmick_CheckCollision(fieldSystem, x + dx, z + dz);
                } else {
                    PlaySE(0x600);
                }
            }
            MapObject_SetNextFacingDirection(object, direction);
            turn = 1;
        } else {
            int kind = 0xC;
            if (PlayerSaveData_CheckRunningShoes(PlayerAvatar_GetPlayerSaveData(avatar)) == TRUE && sub_0205DE88(avatar, keys) == TRUE) {
                kind = 0x58;
            }
            movement = sub_0205D44C(object, (u8)sub_0205F504(object), kind);
            sub_0205E048(avatar);
            PlayerAvatar_SetFlag6(avatar);
        }
    } else if (collision == 0 || collision == 0x20) {
        movement = sub_0205D44C(object, (u8)sub_0205F504(object), 0x10);
        sub_0205E048(avatar);
        PlayerAvatar_SetFlag6(avatar);
    } else {
        movement = 0x1C;
        if (!(collision & 8)) {
            PlaySE(0x600);
        }
        MapObject_SetNextFacingDirection(object, direction);
    }

    movement = sub_0206234C(direction, movement);
    sub_0205DA1C(avatar, object, movement);
    if (!turn) {
        void *fieldSystem = MapObject_GetFieldSystem(object);
        int x = MapObject_GetPreviousXCoord(object);
        int z = MapObject_GetPreviousZCoord(object);
        ov01_02205990(movement, x, z, (u8 *)fieldSystem + 0xE4);
    }
}
