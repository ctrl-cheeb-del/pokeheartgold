#include "global.h"

#include "constants/sndseq.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov04Vec;

typedef struct {
    s32 x;
    s32 z;
} Ov04Pair;

typedef struct {
    u32 state;
} Ov04RideEnv;

typedef struct {
    u32 a, b, c;
} Ov04MapPropTemplate;

typedef struct {
    u16 x;
    u16 z;
} Ov04Coord;

typedef struct {
    u16 count;
    u16 pad2;
    const Ov04Coord *coords;
} Ov04RidePath;

typedef struct {
    u8 pad0[0x14];
    u8 initialized;
    u8 pathState;
    u8 active;
    u8 selected;
    u8 spinarakNo;
    u8 useOffset;
    u8 coordIndex;
    u8 direction;
    u32 unk1C;
    u8 pad20[0xC];
    s32 x;
    u32 unk30;
    s32 z;
} Ov04AzaleaWork;

typedef struct {
    u8 pad0[0x24];
    Ov04AzaleaWork *work;
} Ov04FieldSub4;

typedef struct {
    u8 pad0[4];
    Ov04FieldSub4 *sub4;
    u8 pad8[8];
    void *taskManager;
} Ov04FieldSystem;

typedef struct {
    u32 state;
    Ov04FieldSystem *fieldSystem;
} Ov04RideTaskEnv;

typedef struct {
    u8 pathOrder[4];
    s32 switches;
} Ov04AzaleaSave;

extern void *Heap_AllocAtEnd(u32 heapID, u32 size);
extern void *FieldSystem_GetSaveData(void *fieldSystem);
extern void *Save_GetGymmickPtr(void *saveData);
extern void *Save_Gymmick_AssertMagic_GetData(void *gymmick, u32 magic);
extern void GF_AssertFail(void);
extern const Ov04RidePath *const ov04_022575A4[12];
extern void PlaySE(u32 seqNo);
extern void *Field3dObjectList_GetRenderObjectByID(void *list, u32 id);
extern void MapPropAnimationManager_RemoveAnimationFromRenderObj(void *manager, void *object, u32 id, u32 animation);
extern void MapPropAnimationManager_AddAnimationToRenderObj(u32 id, u32 animation, BOOL loop, void *object, void *manager);
extern BOOL ov04_02254CA4(void *taskManager);
extern void PlayerAvatar_CopyPositionVector(void *avatar, Ov04Vec *position);
extern void PlayerAvatar_ToggleAutomaticHeightUpdating(void *avatar, BOOL enable);
extern void PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate(void *avatar, BOOL enable);
extern void PlayerAvatar_SetMapObjectYPosition(void *avatar, s32 y);
extern void StopSE(u32 seqNo, u32 fade);
extern void ov01_02205A34(Ov04FieldSystem *fieldSystem, s32 y);
extern void SysTask_Destroy(void *task);
extern void MapPropManager_LoadOne(void *manager, u32 id, const void *template, u32 arg3, void *animationManager);
extern void ov01_021FB3E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, s32 a5, void *a6);
extern void *MapPropManager_FindMapPropByBuildModel(void *manager, u32 id);
extern void MapProp_GetTranslation(Ov04Vec *translation, void *object);
extern void MapProp_SetTranslation(void *object, const Ov04Vec *translation);
extern void ov01_021FB4A0(u32 a0, s32 a1, void *manager);
extern const Ov04MapPropTemplate _02257328;
extern const u16 ov04_02257334[];

extern void *TaskManager_GetFieldSystem(void *taskManager);
extern void *TaskManager_GetEnvironment(void *taskManager);
extern void *SysTask_CreateOnMainQueue(void (*func)(void *, void *), void *arg, u32 priority);
extern void TaskManager_Call(void *taskManager, BOOL (*func)(void *), void *env);
extern void Heap_Free(void *ptr);
extern BOOL ov01_02205A60(void *taskManager);
extern void ov04_02254724(void *task, void *arg);

void ov04_02253E20(Ov04FieldSystem *fieldSystem);
void ov04_02253ED4(Ov04FieldSystem *fieldSystem);
BOOL ov04_02253F38(void *taskManager);
BOOL ov04_02253F94(void *taskManager);
void ov04_02253FF0(void *task, Ov04RideTaskEnv *env);
void ov04_022540C0(void *task, Ov04RideTaskEnv *env);
void FlipAzaleaGymSwitch(Ov04FieldSystem *fieldSystem, u8 switchNo);
void BeginAzaleaGymSpinarakRide(Ov04FieldSystem *fieldSystem, u8 spinarakNo);
BOOL ov04_0225463C(void *taskManager);
void ov04_02254698(Ov04Vec *result, const u16 *from, const u16 *to);
void ov04_022546C8(const Ov04Vec *vec, Ov04Pair *result);
int ov04_022546E8(BOOL increasing, int current, int delta, u16 target);

void ov04_02253E20(Ov04FieldSystem *fieldSystem) {
    u32 *saveState = Save_Gymmick_AssertMagic_GetData(Save_GetGymmickPtr(FieldSystem_GetSaveData(fieldSystem)), 4);
    Ov04MapPropTemplate template = _02257328;
    void *object;
    Ov04Vec translation;
    s32 y;

    MapPropManager_LoadOne(*(void **)((u8 *)fieldSystem + 0x9C), 0x6F, &template, 0, *(void **)((u8 *)fieldSystem + 0x54));
    ov01_021FB3E4(0, 0xE, 0x13, 3, 3, 2 << 16, *(void **)((u8 *)fieldSystem + 0x98));
    switch ((u8)*saveState) {
    case 0:
        y = 2 << 16;
        break;
    case 1:
        y = 0x1F << 16;
        break;
    default:
        GF_AssertFail();
        y = 2 << 16;
        break;
    }
    object = MapPropManager_FindMapPropByBuildModel(*(void **)((u8 *)fieldSystem + 0x9C), 0x6F);
    MapProp_GetTranslation(&translation, object);
    translation.y = y;
    MapProp_SetTranslation(object, &translation);
    ov01_021FB4A0(0, y, *(void **)((u8 *)fieldSystem + 0x98));
    G3X_SetEdgeColorTable(ov04_02257334);
}

void ov04_02253ED4(Ov04FieldSystem *fieldSystem) {
    Ov04RideTaskEnv *env = Heap_AllocAtEnd(11, sizeof(Ov04RideTaskEnv));
    u32 *saveState;
    Ov04Vec position;

    env->state = 0;
    env->fieldSystem = fieldSystem;
    saveState = Save_Gymmick_AssertMagic_GetData(Save_GetGymmickPtr(FieldSystem_GetSaveData(fieldSystem)), 4);
    PlayerAvatar_CopyPositionVector(*(void **)((u8 *)fieldSystem + 0x40), &position);
    if (position.y == (2 << 16)) {
        TaskManager_Call(fieldSystem->taskManager, ov04_02253F38, env);
        *saveState = 1;
    } else {
        TaskManager_Call(fieldSystem->taskManager, ov04_02253F94, env);
        *saveState = 0;
    }
}

BOOL ov04_02253F38(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    Ov04RideEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0:
        TaskManager_Call(*(void **)((u8 *)fieldSystem + 0x10), ov01_02205A60, NULL);
        env->state++;
        break;
    case 1:
        SysTask_CreateOnMainQueue((void (*)(void *, void *))ov04_02253FF0, env, 0);
        env->state++;
        break;
    case 5:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

BOOL ov04_02253F94(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    Ov04RideEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0:
        TaskManager_Call(*(void **)((u8 *)fieldSystem + 0x10), ov01_02205A60, NULL);
        env->state++;
        break;
    case 1:
        SysTask_CreateOnMainQueue((void (*)(void *, void *))ov04_022540C0, env, 0);
        env->state++;
        break;
    case 5:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

void ov04_02253FF0(void *task, Ov04RideTaskEnv *env) {
    Ov04FieldSystem *fieldSystem = env->fieldSystem;
    Ov04Vec propPosition;
    Ov04Vec playerPosition;
    void *object;

    switch (env->state) {
    case 2:
        PlayerAvatar_ToggleAutomaticHeightUpdating(*(void **)((u8 *)fieldSystem + 0x40), FALSE);
        PlaySE(SEQ_SE_DP_ELEBETA);
        env->state++;
        return;
    case 3:
        object = MapPropManager_FindMapPropByBuildModel(*(void **)((u8 *)fieldSystem + 0x9C), 0x6F);
        MapProp_GetTranslation(&propPosition, object);
        propPosition.y += 1 << 16;
        if (propPosition.y >= (0x1F << 16)) {
            propPosition.y = 0x1F << 16;
            StopSE(SEQ_SE_DP_ELEBETA, 0);
            env->state++;
        }
        PlayerAvatar_CopyPositionVector(*(void **)((u8 *)fieldSystem + 0x40), &playerPosition);
        playerPosition.y += 1 << 16;
        PlayerAvatar_SetMapObjectYPosition(*(void **)((u8 *)fieldSystem + 0x40), playerPosition.y);
        ov01_02205A34(fieldSystem, playerPosition.y);
        MapProp_SetTranslation(object, &propPosition);
        return;
    case 4:
        ov01_021FB4A0(0, 0x1F << 16, *(void **)((u8 *)fieldSystem + 0x98));
        PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate(*(void **)((u8 *)fieldSystem + 0x40), TRUE);
        PlaySE(SEQ_SE_DP_KI_GASYAN);
        SysTask_Destroy(task);
        env->state++;
        return;
    }
}

void ov04_022540C0(void *task, Ov04RideTaskEnv *env) {
    Ov04FieldSystem *fieldSystem = env->fieldSystem;
    Ov04Vec propPosition;
    Ov04Vec playerPosition;
    void *object;

    switch (env->state) {
    case 2:
        PlayerAvatar_ToggleAutomaticHeightUpdating(*(void **)((u8 *)fieldSystem + 0x40), FALSE);
        PlaySE(SEQ_SE_DP_ELEBETA);
        env->state++;
        return;
    case 3:
        object = MapPropManager_FindMapPropByBuildModel(*(void **)((u8 *)fieldSystem + 0x9C), 0x6F);
        MapProp_GetTranslation(&propPosition, object);
        propPosition.y -= 1 << 16;
        if (propPosition.y <= (2 << 16)) {
            propPosition.y = 2 << 16;
            StopSE(SEQ_SE_DP_ELEBETA, 0);
            env->state++;
        }
        PlayerAvatar_CopyPositionVector(*(void **)((u8 *)fieldSystem + 0x40), &playerPosition);
        playerPosition.y -= 1 << 16;
        PlayerAvatar_SetMapObjectYPosition(*(void **)((u8 *)fieldSystem + 0x40), playerPosition.y);
        ov01_02205A34(fieldSystem, playerPosition.y);
        MapProp_SetTranslation(object, &propPosition);
        return;
    case 4:
        ov01_021FB4A0(0, 2 << 16, *(void **)((u8 *)fieldSystem + 0x98));
        PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate(*(void **)((u8 *)fieldSystem + 0x40), TRUE);
        PlaySE(SEQ_SE_DP_KI_GASYAN);
        SysTask_Destroy(task);
        env->state++;
        return;
    }
}
