#include "overlay02_follow_mon_interaction_r60_private.h"

void FollowMon_ExpandInteractionMessage(void *fieldSystem, void *dest, int heapId, int msgNo) {
    void *msgData = NewMsgDataFromNarc(0, 0x1b, 0x109, heapId);
    void *fmt = MessageFormat_New(heapId);
    void *str;
    FollowMon_PlaceholdersSet(fieldSystem, fmt);
    str = NewString_ReadMsgData(msgData, msgNo);
    StringExpandPlaceholders(fmt, dest, str);
    String_Delete(str);
    MessageFormat_Delete(fmt);
    DestroyMsgData(msgData);
}

void ov02_0224FCE0(void *fieldSystem, void *dest, int heapId, int flags, u8 fashion) {
    void *msgData = NewMsgDataFromNarc(0, 0x1b, 0x28, heapId);
    void *fmt = MessageFormat_New(heapId);
    void *str;
    int msgNo;
    if (flags & 2) {
        BufferPlayersName(fmt, 0, Save_PlayerData_GetProfile(PTR(fieldSystem, 0xc)));
        if (flags & 1) {
            BufferFashionName(fmt, 1, fashion - 1);
            msgNo = 0x20;
        } else {
            BufferFashionNameWithArticle(fmt, 1, fashion - 1);
            msgNo = 0x5f;
        }
    } else {
        void *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(PTR(fieldSystem, 0xc)));
        void *boxMon = Mon_GetBoxMon(mon);
        BufferPlayersName(fmt, 0, Save_PlayerData_GetProfile(PTR(fieldSystem, 0xc)));
        BufferBoxMonNickname(fmt, 1, boxMon);
        msgNo = (flags & 1) ? 0x61 : 0x62;
    }
    str = NewString_ReadMsgData(msgData, msgNo);
    StringExpandPlaceholders(fmt, dest, str);
    String_Delete(str);
    MessageFormat_Delete(fmt);
    DestroyMsgData(msgData);
}

void ov02_0224FD9C(const InteractionMove *move, void *object) {
    VecFx32 pos;
    int species;
    MapObject_CopyPositionVector(object, &pos);
    if (move->dx != 0) {
        pos.x += move->dx << 12;
    }
    if (move->facing != 0) {
        species = FollowMon_GetSpecies(object);
        if (species != 0x32 && species != 0x33) {
            ov01_021F8F74(object, move->facing);
        }
    }
    if (move->dz != 0) {
        pos.z += move->dz << 12;
    }
    MapObject_SetPositionVector(object, &pos);
}

void ov02_0224FDF8(const InteractionMove *move, u32 sound, int pan, int volume) {
    if (move->enabled == 0 || sound == 0) {
        return;
    }
    if (sound > SEQ_SE_END) {
        PlayCryEx(sound == SEQ_SE_END + 1 ? 0 : 0xb, pan, 0x1ff, 0x1ff, 0x1ff, volume);
    } else {
        PlaySE(sound);
    }
}

void ov02_0224FE40(void *env, const InteractionMove *move, void *object) {
    if (move->unk0 != 0) {
        u8 direction = MapObject_GetFacingDirection(object);
        MapObject_SetFacingDirectionDirect(object, move->unk0 - 1);
        ov02_0224FE70(env, object, direction);
    }
}

void ov02_0224FE70(void *env, void *object, u8 oldDirection) {
    int x;
    int z;
    int behavior;
    void *fieldSystem;
    if (!ov01_022055DC(object) || oldDirection == (u8)MapObject_GetFacingDirection(object)) {
        return;
    }
    if (U8(env, 0x87c) != 2 && U8(env, 0x87c) != 3) {
        return;
    }
    fieldSystem = MapObject_GetFieldSystem(object);
    ov02_0224FF04(object, U8(env, 0x87c), &x, &z);
    behavior = GetMetatileBehavior(fieldSystem, x, z);
    if (MetatileBehavior_IsTallGrass((u8)behavior) == 1) {
        ov01_021FF0E4(object, 0, x, z, 1);
    } else if (MetatileBehavior_IsVeryTallGrass((u8)behavior) == 1) {
        ov01_021FF964(object, 0, x, z, 1);
    }
}

void ov02_0224FF04(void *object, int direction, int *x, int *z) {
    *x = MapObject_GetXCoord(object);
    *z = MapObject_GetZCoord(object);
    switch (direction) {
    case 0:
        (*z)++;
        break;
    case 1:
        (*z)--;
        break;
    case 2:
        (*x)++;
        break;
    case 3:
        (*x)--;
        break;
    default:
        GF_AssertFail();
        break;
    }
}

int ov02_0224FF5C(void *env, void *object) {
    InteractionMove *move = (InteractionMove *)((u8 *)env + 0x818 + U8(env, 0x86b) * 8);
    if (U8(env, 0x86a) == 0) {
        ov02_0224FD9C(move, object);
        u32 offset = (U8(env, 0x86c) & 0xf) << 3;
        u8 *soundData = (u8 *)env + offset;
        ov02_0224FDF8(move, U16(soundData, 0x7e8), U16(env, 0x87e), U8(env, 0x87d));
        ov02_0224FE40(env, move, object);
    }
    U8(env, 0x86a)
    ++;
    if (U8(env, 0x86a) >= move->duration) {
        U8(env, 0x86b)
        ++;
        return TRUE;
    }
    return FALSE;
}

int ov02_0224FFD8(void *env) {
    FollowInteractionEnv *work = env;
    if (work->moveIndex >= 10) {
        return FALSE;
    }
    if (work->moves[work->moveIndex].unk0 == 0xff) {
        return FALSE;
    }
    work->frame = 0;
    return TRUE;
}

int ov02_02250004(void *fieldSystem, void *env, int member) {
    u8 direction;
    if (member == 0) {
        GF_AssertFail();
        return TRUE;
    }
    switch (U8(env, 0x868)) {
    case 0:
        ReadWholeNarcMemberByIdPair((u8 *)env + 0x818, 0xe0, member - 1);
    case 1:
        MapObject_CopyPositionVector(PTR(fieldSystem, 0xe4), (VecFx32 *)((u8 *)env + 0x870));
        U8(env, 0x87c) = MapObject_GetFacingDirection(PTR(fieldSystem, 0xe4));
        ov01_021F8F68(PTR(fieldSystem, 0xe4), 0);
        ov01_021F8F08(PTR(fieldSystem, 0xe4), 1);
        U8(env, 0x868) = 2;
        U8(env, 0x86b) = 0;
        break;
    case 2:
        if (!ov02_0224FFD8(env)) {
            U8(env, 0x868) = 4;
            break;
        }
        U8(env, 0x868) = 3;
    case 3:
        if (ov02_0224FF5C(env, PTR(fieldSystem, 0xe4))) {
            U8(env, 0x868) = 2;
        }
        break;
    case 4:
        direction = MapObject_GetFacingDirection(PTR(fieldSystem, 0xe4));
        ov01_021F8F68(PTR(fieldSystem, 0xe4), 0);
        ov01_021F8F08(PTR(fieldSystem, 0xe4), 0);
        MapObject_SetPositionVector(PTR(fieldSystem, 0xe4), (VecFx32 *)((u8 *)env + 0x870));
        MapObject_SetFacingDirectionDirect(PTR(fieldSystem, 0xe4), U8(env, 0x87c));
        ov02_0224FE70(env, PTR(fieldSystem, 0xe4), direction);
        return TRUE;
    }
    return FALSE;
}
