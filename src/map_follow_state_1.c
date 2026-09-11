#include "map_follow_state_internal.h"

void sub_020659CC(LocalMapObject *object) {
    FieldSystem *fs = MapObject_GetFieldSystem(object);
    u8 *state = sub_0205F394(object);

    MapObject_ClearSingleMovement(object);
    MapObject_ClearEndMovement(object);
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)0x20);
    MapObject_SetMovementCommand(object, 0xff);
    MapObject_SetMovementStep(object, 0);
    *state = 0;
    fs->followMon.unk4 = 0;
    fs->followMon.unk1C = 0;
    fs->followMon.unk8 = 0;
    fs->followMon.unkC = 0;
    MapObject_SetPositionFromXYZAndDirection(object,
        MapObject_GetXCoord(object),
        MapObject_GetYCoord(object),
        MapObject_GetZCoord(object),
        MapObject_GetFacingDirection(object));
}

BOOL sub_02065A4C(LocalMapObject *object, FollowStateSol *state) {
    FieldSystem *fs = MapObject_GetFieldSystem(object);
    MapObject_ClearSingleMovement(object);
    MapObject_ClearEndMovement(object);

    if (fs->followMon.unk1C == 1) {
        fs->followMon.unk1C = 2;
        return FALSE;
    }
    if (fs->followMon.unk1C == 2) {
        sub_02065D58(object, state);
        if (fs->followMon.unk8 == MapObject_GetXCoord(object) && fs->followMon.unkC == MapObject_GetZCoord(object)) {
            fs->followMon.unk1C = 0;
            state->state = 3;
            if (sub_02069E14(object) && !state->flag0) {
                if (sub_02069EAC(object)) {
                    ov01_0220329C(object, 0);
                    sub_02069E84(object, 0);
                } else {
                    sub_02069DC8(object, 0);
                }
                sub_020664D8(object);
            }
            sub_02065D78(object);
            if (sub_020623C8()) {
                sub_02069E28(object, (u8)PlayerAvatar_GetFacingDirection(FieldSystem_GetPlayerAvatar(fs)));
            }
            return TRUE;
        }
        if (sub_02065DF4(object, state) == TRUE) {
            if (sub_02069E14(object)) {
                if (sub_02069EAC(object)) {
                    ov01_0220329C(object, 0);
                    sub_02069E84(object, 0);
                } else {
                    sub_02069DC8(object, 0);
                }
                sub_020664D8(object);
            }
            MapObject_SetSingleMovement(object);
            fs->followMon.unk1C = 3;
            return TRUE;
        }
    } else if (fs->followMon.unk1C == 3) {
        fs->followMon.unk1C = 0;
    }
    return FALSE;
}

BOOL sub_02065B70(LocalMapObject *object, FollowStateSol *state) {
    MapObject_ClearSingleMovement(object);
    MapObject_ClearEndMovement(object);
    if (sub_02065D24(object, state) == TRUE) {
        sub_02065D58(object, state);
        if (sub_02069E14(object)) {
            if (sub_02069EAC(object)) {
                ov01_0220329C(object, 0);
                sub_02069E84(object, 0);
            } else {
                sub_02069DC8(object, 0);
            }
            sub_020664D8(object);
        }
        if (sub_02065F44(object) == TRUE) {
            MapObject_SetSingleMovement(object);
            state->state++;
            return TRUE;
        }
    }
    return FALSE;
}
