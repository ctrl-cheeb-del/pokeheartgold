#include "player_avatar_movement_update_internal.h"

void sub_0205CC94(PlayerAvatar *avatar) {
    LocalMapObject *object;
    u8 behavior;
    u8 previous;
    int movement;

    if (PlayerAvatar_GetMoveState(avatar) != 1) {
        return;
    }
    object = PlayerAvatar_GetMapObject(avatar);
    behavior = sub_0205F504(object);
    movement = sub_02062390(MapObject_GetMovementCommand(object));
    if (movement == -1) {
        previous = behavior;
    } else {
        previous = sub_02060FA8(object, movement);
    }

    if (MetatileBehavior_IsPuddle(behavior) == TRUE) {
        PlaySE(SEQ_SE_DP_FOOT3_0);
    }
    if (MetatileBehavior_IsShallowWater(behavior) == TRUE) {
        PlaySE(SEQ_SE_DP_FOOT3_1);
    }
    MetatileBehavior_IsSand(behavior);
    if (MetatileBehavior_IsMud(behavior) == TRUE) {
        PlaySE(SEQ_SE_DP_MARSH_WALK);
    }

    movement = MapObject_GetMovementCommand(object);
    PlayerAvatar_GetState(avatar);
    if (sub_0205DE64(movement) == FALSE) {
        if (MetatileBehavior_IsVeryTallGrass(behavior) == TRUE || MetatileBehavior_IsVeryTallGrass(previous) == TRUE) {
            PlaySE(SEQ_SE_DP_KUSA);
        }
        if (MetatileBehavior_IsTallGrass(behavior) == TRUE || MetatileBehavior_IsTallGrass(previous) == TRUE) {
            PlaySE(SEQ_SE_GS_KUSA2);
        }
    }
    sub_0205CD70(object, avatar);
}

void sub_0205CD70(LocalMapObject *object, PlayerAvatar *avatar) {
    int movement = sub_02062390(MapObject_GetMovementCommand(object));
    u8 behavior = sub_0205F504(object);
    u8 soundBehavior = sub_0205F504(object);
    u16 sequence;
    int state;

    if (MetatileBehavior_IsVeryTallGrass(soundBehavior) != FALSE || MetatileBehavior_IsPuddle(soundBehavior) == TRUE || MetatileBehavior_IsShallowWater(soundBehavior) == TRUE || MetatileBehavior_IsTallGrass(soundBehavior) != FALSE) {
        return;
    }
    if (movement != -1) {
        behavior = sub_02060FE0(object, movement);
    }
    if (_020FCB98[behavior].sequence == SEQ_SE_GS_EDAPAKI) {
        PlayerAvatar_ResetUnkC(avatar);
    } else if (PlayerAvatar_GetPlayerMoveState(avatar) == 0) {
        PlayerAvatar_ResetUnkC(avatar);
    } else {
        PlayerAvatar_ToggleUnkC(avatar);
    }
    if (PlayerAvatar_GetUnkC(avatar) != 0) {
        return;
    }
    state = PlayerAvatar_GetState(avatar);
    switch (state) {
    case 1:
    case 2:
        return;
    }
    if (behavior < 16) {
        if (behavior == 0 && sub_0205DE98(avatar) == TRUE) {
            behavior = 1;
        }
        if (_020FCB98[behavior].special == 1) {
            sequence = _020FCB98[behavior].sequence;
            sub_02006088(sequence);
        } else {
            sequence = _020FCB98[behavior].sequence;
            PlaySE(sequence);
        }
        sub_02005BA8(sequence);
        return;
    }
    if (behavior >= 16) {
        GF_AssertFail();
    }
}

void PlayerAvatar_UpdateMovement(PlayerAvatar *avatar) {
    int moveState = PlayerAvatar_GetMoveState(avatar);
    int playerMoveState = PlayerAvatar_GetPlayerMoveState(avatar);
    LocalMapObject *object = PlayerAvatar_GetMapObject(avatar);

    PlayerAvatar_SetPlayerMoveState(avatar, 0);
    switch (sub_0205D01C(avatar, -1)) {
    case 0:
    case 2:
        break;
    default:
        PlayerAvatar_SetPlayerMoveState(avatar, 2);
        return;
    }

    if (!MapObject_AreBitsSetForMovementScriptInit(object)) {
        switch (moveState) {
        case 0:
            return;
        case 1:
            if (sub_0205DE64(MapObject_GetMovementCommand(object)) == TRUE) {
                return;
            }
            if (playerMoveState == 0 || playerMoveState == 3) {
                PlayerAvatar_SetPlayerMoveState(avatar, 1);
            } else {
                PlayerAvatar_SetPlayerMoveState(avatar, 2);
            }
            return;
        case 2:
            PlayerAvatar_SetPlayerMoveState(avatar, 2);
            return;
        default:
            return;
        }
    }

    if (MapObject_IsMovementPaused(object) != TRUE) {
        return;
    }
    switch (moveState) {
    case 0:
        return;
    case 1:
        if (playerMoveState == 0) {
            return;
        }
        if (playerMoveState == 3) {
            PlayerAvatar_SetPlayerMoveState(avatar, 0);
        } else {
            PlayerAvatar_SetPlayerMoveState(avatar, 3);
        }
        return;
    case 2:
        if (playerMoveState == 0) {
            return;
        }
        if (playerMoveState == 3) {
            PlayerAvatar_SetPlayerMoveState(avatar, 0);
        } else {
            PlayerAvatar_SetPlayerMoveState(avatar, 3);
        }
        return;
    }
}
