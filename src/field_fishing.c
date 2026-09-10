#include "field_fishing_internal.h"

FishingRodTaskEnv *CreateFishingRodTaskEnv(FieldSystem *fieldSystem, u32 heapId, u32 rodType);
BOOL Task_OverworldFish(TaskManager *taskMan);
SysTask *ov01_021FC748(FieldSystem *fieldSystem, u32 rodType, BOOL hooked);
BOOL ov01_021FC76C(SysTask *task);
BOOL ov01_021FC778(SysTask *task);
void ov01_021FC784(SysTask *task);
void ov01_021FC798(SysTask *task, void *data);
int ov01_021FC7C4(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC7DC(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC814(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC84C(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC88C(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC8E8(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC914(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC934(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC968(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC980(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC98C(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC9AC(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC9DC(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FC9E8(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FCA2C(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FCA58(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FCA94(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
int ov01_021FCAA8(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj);
void *ov01_021FCAC4(u32 size);
BOOL ov01_021FCAE8(void);
BOOL ov01_021FCAFC(void);
void ov01_021FCB14(FishingRodEnv *env);
void ov01_021FCB4C(FishingRodEnv *env);
void ov01_021FCB6C(FishingRodEnv *env);
void ov01_021FCB90(FishingRodEnv *env, u32 msgId);
BOOL ov01_021FCBCC(FishingRodEnv *env);
u32 ov01_021FCC00(u32 rodType);
BOOL ov01_021FCC2C(FishingRodEnv *env);
BOOL ov01_021FCC74(u8 friendship);
u8 ov01_021FCCB0(FishingRodEnv *env);

static const u32 sRodBiteDelay[3] = { 45, 30, 15 };

static const u32 sMoodBonus[5][3] = {
    { 0,  0,  0  },
    { 9,  6,  3  },
    { 15, 12, 6  },
    { 21, 18, 9  },
    { 30, 24, 12 },
};

static int (*const sFishStateFuncs[])(FishingRodEnv *, PlayerAvatar *, LocalMapObject *) = {
    ov01_021FC7C4,
    ov01_021FC7DC,
    ov01_021FC814,
    ov01_021FC84C,
    ov01_021FC88C,
    ov01_021FC8E8,
    ov01_021FC914,
    ov01_021FC934,
    ov01_021FC968,
    ov01_021FC980,
    ov01_021FC98C,
    ov01_021FC9AC,
    ov01_021FC9DC,
    ov01_021FC9E8,
    ov01_021FCA2C,
    ov01_021FCA58,
    ov01_021FCA94,
    ov01_021FCAA8,
};

FishingRodTaskEnv *CreateFishingRodTaskEnv(FieldSystem *fieldSystem, u32 heapId, u32 rodType) {
    FishingRodTaskEnv *env;
    u32 n;
    u8 *p;

    env = Heap_AllocAtEnd(heapId, sizeof(FishingRodTaskEnv));
    p = (u8 *)env;
    n = sizeof(FishingRodTaskEnv);
    do {
        *p = 0;
        p++;
        n--;
    } while (n != 0);
    env->rodType = rodType;
    env->msgId = ov01_021FCC00(rodType);
    return env;
}

BOOL Task_OverworldFish(TaskManager *taskMan) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskMan);
    FishingRodTaskEnv *env = TaskManager_GetEnvironment(taskMan);

    switch (env->state) {
    case 0:
        MapObjectManager_PauseAllMovement(fieldSystem->mapObjectManager);
        env->battleSetup = NULL;
        env->hooked = FieldSystem_PerformFishEncounterCheck(fieldSystem, env->rodType, &env->battleSetup);
        env->task = ov01_021FC748(fieldSystem, env->rodType, env->hooked);
        env->state++;
        break;
    case 1:
        if (ov01_021FC76C(env->task) == TRUE) {
            BOOL result = ov01_021FC778(env->task);
            ov01_021FC784(env->task);
            if (result == TRUE) {
                GearPhoneRingManager_ResetIfActive(FieldSystem_GetGearPhoneRingManager(fieldSystem));
                GameStats_Inc(Save_GameStats_Get(fieldSystem->saveData), GAME_STAT_FISH_LANDED);
                FieldSystem_StartForcedWildBattle(fieldSystem, taskMan, env->battleSetup);
                Heap_Free(env);
                return FALSE;
            }
            if (env->battleSetup != NULL) {
                BattleSetup_Delete(env->battleSetup);
            }
            MapObjectManager_UnpauseAllMovement(fieldSystem->mapObjectManager);
            Heap_Free(env);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

SysTask *ov01_021FC748(FieldSystem *fieldSystem, u32 rodType, BOOL hooked) {
    FishingRodEnv *env = ov01_021FCAC4(sizeof(FishingRodEnv));
    env->fieldSystem = fieldSystem;
    env->rodType = rodType;
    env->hooked = hooked;
    return SysTask_CreateOnMainQueue(ov01_021FC798, env, 0x80);
}

BOOL ov01_021FC76C(SysTask *task) {
    FishingRodEnv *env = SysTask_GetData(task);
    return env->finished;
}

BOOL ov01_021FC778(SysTask *task) {
    FishingRodEnv *env = SysTask_GetData(task);
    return env->result;
}

void ov01_021FC784(SysTask *task) {
    Heap_Free(SysTask_GetData(task));
    SysTask_Destroy(task);
}

void ov01_021FC798(SysTask *task, void *data) {
    FishingRodEnv *env = data;
    PlayerAvatar *avatar = env->fieldSystem->playerAvatar;
    LocalMapObject *obj = PlayerAvatar_GetMapObject(avatar);

    while (sFishStateFuncs[env->state](env, avatar, obj) != 0) {
        ;
    }
}

int ov01_021FC7C4(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    ov01_021FCB14(env);
    MapObject_UnpauseMovement(obj);
    env->state = 1;
    return 1;
}

int ov01_021FC7DC(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    if (MapObject_AreBitsSetForMovementScriptInit(obj) == TRUE) {
        MapObject_ClearHeldMovementIfActive(obj);
        Field_PlayerAvatar_OrrTransitionFlags(avatar, 0x20);
        Field_PlayerAvatar_ApplyTransitionFlags(avatar);
        sub_0205F328(obj, 1);
        env->state = 2;
    }
    return 0;
}

int ov01_021FC814(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->timer++;
    if (env->timer == 10) {
        PlaySE(SEQ_SE_DP_FW104);
    }
    if (env->timer < 0x22) {
        return 0;
    }
    if (env->hooked == 1) {
        env->state = 3;
    } else {
        env->state = 12;
    }
    env->timer = 0;
    return 1;
}

int ov01_021FC84C(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->counter1 = (LCRandom() % 4 + 1) * 30;
    env->counter2 = sRodBiteDelay[env->rodType];
    env->counter2 += ov01_021FCCB0(env);
    env->state = 4;
    return 1;
}

int ov01_021FC88C(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->counter1--;
    if (ov01_021FCAE8() == TRUE) {
        env->state = 10;
        return 1;
    }
    if (env->counter1 > 0) {
        return 0;
    }
    sub_0205F328(obj, 2);
    if (ov01_021FCC2C(env)) {
        env->effect = ov01_02200540(FollowMon_GetMapObject(env->fieldSystem), 0, 1);
    } else {
        env->effect = ov01_02200540(obj, 0, 1);
    }
    env->state = 5;
    return 1;
}

int ov01_021FC8E8(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->counter2--;
    if (ov01_021FCAE8() == TRUE) {
        env->state = 6;
        return 1;
    }
    if (env->counter2 > 0) {
        return 0;
    }
    env->state = 11;
    return 0;
}

int ov01_021FC914(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    ov01_02200400(env->effect);
    sub_0205F328(obj, 3);
    env->timer = 0;
    env->state = 7;
    return 0;
}

int ov01_021FC934(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->timer++;
    if (env->effect != 0) {
        sub_02068B48(env->effect);
        env->effect = 0;
    }
    if (env->timer > 15) {
        env->timer = 0;
        env->state = 8;
        ov01_021FCB90(env, 0x34);
    }
    return 0;
}

int ov01_021FC968(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    if (ov01_021FCBCC(env) == 0) {
        return 0;
    }
    env->state = 9;
    return 1;
}

int ov01_021FC980(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->result = TRUE;
    env->state = 15;
    return 1;
}

int ov01_021FC98C(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    sub_0205F328(obj, 0);
    ov01_021FCB90(env, 0x33);
    env->timer = 0x10;
    env->state = 14;
    return 1;
}

int ov01_021FC9AC(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    sub_0205F328(obj, 0);
    ov01_021FCB90(env, 0x32);
    env->timer = 0x10;
    env->state = 14;
    GameStats_Inc(Save_GameStats_Get(env->fieldSystem->saveData), GAME_STAT_UNK101);
    return 1;
}

int ov01_021FC9DC(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->timer = 0x78;
    env->state = 13;
    return 1;
}

int ov01_021FC9E8(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->timer--;
    if (ov01_021FCAE8() == TRUE) {
        env->state = 10;
        return 1;
    }
    if (env->timer != 0) {
        return 0;
    }
    sub_0205F328(obj, 0);
    ov01_021FCB90(env, 0x31);
    env->timer = 0x10;
    env->state = 14;
    return 0;
}

int ov01_021FCA2C(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->timer++;
    if (env->timer < 0x10) {
        return 0;
    }
    env->timer = 0x10;
    if (ov01_021FCBCC(env) == 0) {
        return 0;
    }
    env->state = 15;
    return 1;
}

int ov01_021FCA58(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    if (env->effect != 0) {
        ov01_02200400(env->effect);
    }
    ov01_021FCB4C(env);
    Field_PlayerAvatar_OrrTransitionFlags(avatar, PlayerAvatar_GetTransitionBits(PlayerAvatar_GetState(avatar)));
    Field_PlayerAvatar_ApplyTransitionFlags(avatar);
    env->timer = 0;
    env->state = 16;
    return 1;
}

int ov01_021FCA94(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    env->timer++;
    if (env->timer > 2) {
        env->state = 17;
    }
    return 0;
}

int ov01_021FCAA8(FishingRodEnv *env, PlayerAvatar *avatar, LocalMapObject *obj) {
    if (env->effect != 0) {
        sub_02068B48(env->effect);
        env->effect = 0;
    }
    env->finished = TRUE;
    return 0;
}

void *ov01_021FCAC4(u32 size) {
    void *ptr = Heap_AllocAtEnd(HEAP_ID_FIELD1, size);
    if (ptr == NULL) {
        GF_AssertFail();
    }
    memset(ptr, 0, size);
    return ptr;
}

BOOL ov01_021FCAE8(void) {
    return (gSystem.heldKeys & 1) != 0;
}

BOOL ov01_021FCAFC(void) {
    if (gSystem.heldKeys & 3) {
        return TRUE;
    }
    return FALSE;
}

void ov01_021FCB14(FishingRodEnv *env) {
    env->msgData = NewMsgDataFromNarc(1, 0x1B, 0x28, 4);
    env->strExpanded = String_New(1024, 4);
    env->strRaw = String_New(1024, 4);
    env->msgFmt = MessageFormat_New_Custom(8, 0x40, 4);
}

void ov01_021FCB4C(FishingRodEnv *env) {
    MessageFormat_Delete(env->msgFmt);
    String_Delete(env->strExpanded);
    String_Delete(env->strRaw);
    DestroyMsgData(env->msgData);
}

void ov01_021FCB6C(FishingRodEnv *env) {
    FieldSystem *fieldSystem = env->fieldSystem;
    DialogBox_AddWindowToLayer3(fieldSystem->bgConfig, &env->window, 3);
    DialogBox_LoadFrame(&env->window, Save_PlayerData_GetOptionsAddr(fieldSystem->saveData));
}

void ov01_021FCB90(FishingRodEnv *env, u32 msgId) {
    FieldSystem *fieldSystem;
    ov01_021FCB6C(env);
    fieldSystem = env->fieldSystem;
    ReadMsgDataIntoString(env->msgData, msgId, env->strRaw);
    StringExpandPlaceholders(env->msgFmt, env->strExpanded, env->strRaw);
    env->printHandle = DialogBox_PrintMessage(&env->window, env->strExpanded, Save_PlayerData_GetOptionsAddr(fieldSystem->saveData), 1);
}

BOOL ov01_021FCBCC(FishingRodEnv *env) {
    if (DialogBox_IsPrintFinished(env->printHandle) == TRUE) {
        if (ov01_021FCAFC() == TRUE) {
            ClearFrameAndWindow2(&env->window, 0);
            RemoveWindow(&env->window);
            return TRUE;
        }
    }
    return FALSE;
}

u32 ov01_021FCC00(u32 rodType) {
    switch (rodType) {
    default:
        GF_AssertFail();
    case 0:
        return 0x1BD;
    case 1:
        return 0x1BE;
    case 2:
        return 0x1BF;
    }
}

BOOL ov01_021FCC2C(FishingRodEnv *env) {
    if (PlayerAvatar_GetState(env->fieldSystem->playerAvatar) == 2) {
        return FALSE;
    }
    if (FollowMon_IsActive(env->fieldSystem)) {
        u32 friendship = GetMonData(GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(env->fieldSystem->saveData)), 9, NULL);
        if (ov01_021FCC74((u8)friendship)) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov01_021FCC74(u8 friendship) {
    s32 threshold;
    if (friendship <= 99) {
        return FALSE;
    }
    if (friendship <= 149) {
        threshold = 20;
    } else if (friendship <= 199) {
        threshold = 30;
    } else if (friendship <= 249) {
        threshold = 40;
    } else {
        threshold = 50;
    }
    if (LCRandom() % 100 < threshold) {
        return TRUE;
    }
    return FALSE;
}

u8 ov01_021FCCB0(FishingRodEnv *env) {
    s32 mood;
    u32 bucket;
    u8 rodType;

    if (FollowMon_IsActive(env->fieldSystem)) {
        mood = FieldSystem_UnkSub108_GetMonMood(env->fieldSystem->unk108);
        if (mood <= -10) {
            bucket = 0;
        } else if (mood >= -9 && mood <= 9) {
            bucket = 1;
        } else if (mood >= 10 && mood < 50) {
            bucket = 2;
        } else if (mood >= 50 && mood < 100) {
            bucket = 3;
        } else {
            bucket = 4;
        }
        rodType = (u8)env->rodType;
        if (rodType > 2) {
            GF_AssertFail();
            return 0;
        }
        return (u8)sMoodBonus[bucket][rodType];
    }
    return 0;
}
