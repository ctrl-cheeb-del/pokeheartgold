#include "map_object_follow_internal.h"

BOOL sub_02065BE8(LocalMapObject *object, FollowState *state) {
    MapObject_ClearSingleMovement(object);
    MapObject_ClearEndMovement(object);
    if (sub_02065D24(object, state) == TRUE) {
        sub_02065D58(object, state);
        if (sub_02065FBC(object) == TRUE) {
            MapObject_SetSingleMovement(object);
            state->state++;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL sub_02065C2C(LocalMapObject *object, FollowState *state) {
    if (sub_02062428(object) == TRUE) {
        MapObject_ClearSingleMovement(object);
        state->state = 0;
    }
    return FALSE;
}

BOOL sub_02065C48(LocalMapObject *object, FollowState *state) {
    if (sub_02062428(object) == TRUE) {
        *((u8 *)state + 2) += 1;
        if (*((u8 *)state + 2) >= 2) {
            MapObject_ClearSingleMovement(object);
            state->state = 0;
            *((u8 *)state + 3) = 0;
            *(u16 *)((u8 *)state + 10) &= ~6;
            return FALSE;
        }
        MapObject_ForceSetHeldMovement(object, sub_02069ED4(object));
    }
    *((u8 *)state + 3) += 1;
    return FALSE;
}

BOOL sub_02065C90(LocalMapObject *object, FollowState *state) {
    PlayerAvatar *avatar = FieldSystem_GetPlayerAvatar(MapObject_GetFieldSystem(object));
    LocalMapObject *player = PlayerAvatar_GetMapObject(avatar);
    if (MapObject_TestFlagsBits(player, (MapObjectFlagBits)0x10) == TRUE && MapObject_TestFlagsBits(player, (MapObjectFlagBits)0x20) == TRUE) {
        state->state = 0;
    }
    if (PlayerAvatar_GetPlayerMoveState(avatar) == 3) {
        state->state = 0;
    }
    return FALSE;
}

int sub_02065CD0(LocalMapObject *object, FollowState *state) {
    if (MapObjectManager_GetFirstActiveObjectWithMovement1(MapObject_GetManager(object)) == NULL) {
        state->found = FALSE;
        return FALSE;
    }
    if (state->found == FALSE) {
        sub_02065CFC(object, state);
    }
    return TRUE;
}

void sub_02065CFC(LocalMapObject *object, FollowState *state) {
    PlayerAvatar *avatar = FieldSystem_GetPlayerAvatar(MapObject_GetFieldSystem(object));
    state->found = TRUE;
    state->z = PlayerAvatar_GetXCoord(avatar);
    state->unk6 = PlayerAvatar_GetZCoord(avatar);
    *((u16 *)state + 4) = 0xff;
}

BOOL sub_02065D24(LocalMapObject *object, FollowState *state) {
    PlayerAvatar *avatar = FieldSystem_GetPlayerAvatar(MapObject_GetFieldSystem(object));
    if (avatar != NULL) {
        int x = PlayerAvatar_GetXCoord(avatar);
        int z = PlayerAvatar_GetZCoord(avatar);
        if (x != state->z || z != (s16)state->unk6) {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_02065D58(LocalMapObject *object, FollowState *state) {
    PlayerAvatar *avatar = FieldSystem_GetPlayerAvatar(MapObject_GetFieldSystem(object));
    state->z = PlayerAvatar_GetXCoord(avatar);
    state->unk6 = PlayerAvatar_GetZCoord(avatar);
}

int sub_02065D78(LocalMapObject *object) {
    FieldSystem *fs = MapObject_GetFieldSystem(object);
    (void)FieldSystem_GetPlayerAvatar(fs);
    switch (*(int *)((u8 *)fs + 0xe8)) {
    case 0x58:
        return 0x10;
    case 0x59:
        return 0x11;
    case 0x5a:
        return 0x12;
    case 0x5b:
        return 0x13;
    default:
        return *(int *)((u8 *)fs + 0xe8);
    }
}

int sub_02065DB4(LocalMapObject *object) {
    int movement = MapObject_GetMovementCommand(PlayerAvatar_GetMapObject(FieldSystem_GetPlayerAvatar(MapObject_GetFieldSystem(object))));
    switch (movement) {
    case 0x58:
        return 0x10;
    case 0x59:
        return 0x11;
    case 0x5a:
        return 0x12;
    case 0x5b:
        return 0x13;
    default:
        return movement;
    }
}
