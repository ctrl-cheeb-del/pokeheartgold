#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

void ov01_021F1B38(PlayerAvatar *playerAvatar) {
    u32 unk34;
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(0, PlayerAvatar_GetGender(playerAvatar)));
    PlayerAvatar_SetState(playerAvatar, 0);
    PlayerAvatar_ClearUnk24ClearFlag2(playerAvatar);
    unk34 = PlayerAvatar_GetUnk34(playerAvatar);
    if (unk34 != 0) {
        ov01_021F1640(unk34);
    }
    PlayerAvatar_SetUnk34(playerAvatar, 0);
}

void ov01_021F1B78(PlayerAvatar *playerAvatar) {
    u32 unk34;
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(1, PlayerAvatar_GetGender(playerAvatar)));
    PlayerAvatar_SetState(playerAvatar, 1);
    PlayerAvatar_ClearUnk24ClearFlag2(playerAvatar);
    unk34 = PlayerAvatar_GetUnk34(playerAvatar);
    if (unk34 != 0) {
        ov01_021F1640(unk34);
    }
    PlayerAvatar_SetUnk34(playerAvatar, 0);
    PlaySE(SEQ_SE_DP_JITENSYA);
}

void ov01_021F1BC0(PlayerAvatar *playerAvatar) {
    u32 unk34;
    int direction;
    LocalMapObject *obj;
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(2, PlayerAvatar_GetGender(playerAvatar)));
    PlayerAvatar_SetState(playerAvatar, 2);
    PlayerAvatar_ClearUnk24ClearFlag2(playerAvatar);
    unk34 = PlayerAvatar_GetUnk34(playerAvatar);
    if (unk34 != 0) {
        ov01_021F1640(unk34);
    }
    PlayerAvatar_SetUnk34(playerAvatar, 0);
    direction = PlayerAvatar_GetFacingDirection(playerAvatar);
    obj = PlayerAvatar_GetMapObject(playerAvatar);
    MapObject_GetFieldSystem(obj);
    PlayerAvatar_SetUnk34(playerAvatar, ov01_021FE7DC(obj, 0, 0, direction, 1));
}

void ov01_021F1C30(PlayerAvatar *playerAvatar) {
    u32 unk34;
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(3, PlayerAvatar_GetGender(playerAvatar)));
    PlayerAvatar_SetState(playerAvatar, 3);
    PlayerAvatar_ClearUnk24ClearFlag2(playerAvatar);
    unk34 = PlayerAvatar_GetUnk34(playerAvatar);
    if (unk34 != 0) {
        ov01_021F1640(unk34);
    }
    PlayerAvatar_SetUnk34(playerAvatar, 0);
}

void ov01_021F1C70(PlayerAvatar *playerAvatar) {
    PlayerAvatar_SetFlag1(playerAvatar, TRUE);
}

void ov01_021F1C7C(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(5, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1C98(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(7, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1CB4(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(8, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1CD0(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(9, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1CEC(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(10, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1D08(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(11, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1D24(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(12, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1D40(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(6, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1D5C(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(13, PlayerAvatar_GetGender(playerAvatar)));
}

void ov01_021F1D78(PlayerAvatar *playerAvatar) {
    ov01_021F3084(playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(14, PlayerAvatar_GetGender(playerAvatar)));
}

BOOL ov01_021F1D94(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int direction, int playerEvents) {
    if (PlayerAvatar_CheckForcedMovement(playerAvatar) == TRUE) {
        if (ov01_021F2538(fieldSystem, playerAvatar, playerEvents) == TRUE) {
            return TRUE;
        }
        return FALSE;
    }
    if (!sub_0205CBE4(playerAvatar, direction)) {
        return FALSE;
    }
    if (direction == ~0) {
        return FALSE;
    }
    if (ov01_021F1DF4(fieldSystem, playerAvatar, direction, playerEvents) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov01_021F1DF4(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int a2, int a3) {
    int r = sub_0205DEC0(playerAvatar, a2);
    if (a3 & 1) {
        if (ov01_021F1E54(fieldSystem, playerAvatar, a2, r) == TRUE) {
            return TRUE;
        }
    }
    if (a3 & 2) {
        if (ov01_021F24F4(fieldSystem, playerAvatar, a2, r) == TRUE) {
            return TRUE;
        }
    }
    if (ov01_021F232C(fieldSystem, playerAvatar, a2, r) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov01_021F1E54(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int a2, int a3) {
    LocalMapObject *obj;
    if (a3 != 1) {
        return FALSE;
    }
    obj = ov01_021F3094(playerAvatar, a2);
    if (obj == NULL) {
        return FALSE;
    }
    if (MapObject_GetSpriteID(obj) != 0x54) {
        return FALSE;
    }
    if ((sub_02060BB8(obj, a2) & ~1) != 0) {
        return FALSE;
    }
    ov01_021F1EA4(a2, fieldSystem, playerAvatar, obj);
    return TRUE;
}

void ov01_021F1EA4(int a0, FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, LocalMapObject *obj) {
    int *env = ov01_021F30D0(0x14);
    env[1] = a0;
    env[2] = (int)fieldSystem;
    env[4] = (int)obj;
    env[3] = (int)playerAvatar;
    FieldSystem_CreateTask(fieldSystem, ov01_021F1ECC, env);
}
