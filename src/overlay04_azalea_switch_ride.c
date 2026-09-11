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

void FlipAzaleaGymSwitch(Ov04FieldSystem *fieldSystem, u8 switchNo) {
    Ov04AzaleaSave *save = Save_Gymmick_AssertMagic_GetData(Save_GetGymmickPtr(FieldSystem_GetSaveData(fieldSystem)), 5);
    void *object1;
    void *object2;
    u8 oldState;
    u8 newState;

    PlaySE(SEQ_SE_DP_KI_GASYAN);
    if (switchNo == 0) {
        oldState = save->switches & 1;
        save->switches ^= 1;
        object1 = Field3dObjectList_GetRenderObjectByID(*(void **)((u8 *)fieldSystem + 0xC0), 0x74);
        object2 = Field3dObjectList_GetRenderObjectByID(*(void **)((u8 *)fieldSystem + 0xC0), 0x75);
        MapPropAnimationManager_RemoveAnimationFromRenderObj(*(void **)((u8 *)fieldSystem + 0x54), object1, 0x74, oldState);
        MapPropAnimationManager_RemoveAnimationFromRenderObj(*(void **)((u8 *)fieldSystem + 0x54), object2, 0x75, oldState);
        newState = save->switches & 1;
        if (newState) {
            MapPropAnimationManager_AddAnimationToRenderObj(0x74, 1, TRUE, object1, *(void **)((u8 *)fieldSystem + 0x54));
            MapPropAnimationManager_AddAnimationToRenderObj(0x75, 1, TRUE, object2, *(void **)((u8 *)fieldSystem + 0x54));
        } else {
            MapPropAnimationManager_AddAnimationToRenderObj(0x74, 0, TRUE, object1, *(void **)((u8 *)fieldSystem + 0x54));
            MapPropAnimationManager_AddAnimationToRenderObj(0x75, 0, TRUE, object2, *(void **)((u8 *)fieldSystem + 0x54));
        }
    } else if (switchNo == 1) {
        oldState = (save->switches >> 1) & 1;
        save->switches ^= 2;
        object1 = Field3dObjectList_GetRenderObjectByID(*(void **)((u8 *)fieldSystem + 0xC0), 0x73);
        object2 = Field3dObjectList_GetRenderObjectByID(*(void **)((u8 *)fieldSystem + 0xC0), 0x7A);
        MapPropAnimationManager_RemoveAnimationFromRenderObj(*(void **)((u8 *)fieldSystem + 0x54), object1, 0x73, oldState);
        MapPropAnimationManager_RemoveAnimationFromRenderObj(*(void **)((u8 *)fieldSystem + 0x54), object2, 0x7A, oldState);
        newState = (save->switches >> 1) & 1;
        if (newState) {
            MapPropAnimationManager_AddAnimationToRenderObj(0x73, 1, TRUE, object1, *(void **)((u8 *)fieldSystem + 0x54));
            MapPropAnimationManager_AddAnimationToRenderObj(0x7A, 1, TRUE, object2, *(void **)((u8 *)fieldSystem + 0x54));
        } else {
            MapPropAnimationManager_AddAnimationToRenderObj(0x73, 0, TRUE, object1, *(void **)((u8 *)fieldSystem + 0x54));
            MapPropAnimationManager_AddAnimationToRenderObj(0x7A, 0, TRUE, object2, *(void **)((u8 *)fieldSystem + 0x54));
        }
    } else {
        GF_AssertFail();
    }
    TaskManager_Call(fieldSystem->taskManager, ov04_02254CA4, NULL);
}

void BeginAzaleaGymSpinarakRide(Ov04FieldSystem *fieldSystem, u8 spinarakNo) {
    Ov04AzaleaWork *work = fieldSystem->sub4->work;
    Ov04RideTaskEnv *env = Heap_AllocAtEnd(11, sizeof(Ov04RideTaskEnv));
    int i;
    Ov04AzaleaSave *save;
    const Ov04RidePath *paths;
    const Ov04Coord *coords;
    const Ov04Coord *coord;

    env->state = 0;
    env->fieldSystem = fieldSystem;
    work->spinarakNo = spinarakNo;
    work->unk30 = 0;
    work->initialized = 0;
    work->active = 1;
    work->unk1C = 0;

    save = Save_Gymmick_AssertMagic_GetData(Save_GetGymmickPtr(FieldSystem_GetSaveData(fieldSystem)), 5);
    work->pathState = save->switches;
    for (i = 0; i < 4; i++) {
        if (spinarakNo == save->pathOrder[i]) {
            work->selected = i;
            break;
        }
    }
    if (i == 4) {
        GF_AssertFail();
        return;
    }

    switch (spinarakNo) {
    case 3:
    case 4:
    case 5:
    case 9:
    case 10:
    case 11:
        work->useOffset = 1;
        work->coordIndex = ov04_022575A4[spinarakNo][work->pathState].count - 1;
        work->direction = 1;
        break;
    default:
        work->useOffset = 0;
        work->coordIndex = 0;
        work->direction = 0;
        break;
    }
    paths = ov04_022575A4[spinarakNo];
    coords = paths[work->pathState].coords;
    coord = &coords[work->coordIndex];
    work->x = coord->x << 16;
    work->z = coord->z << 16;
    TaskManager_Call(fieldSystem->taskManager, ov04_0225463C, env);
}

BOOL ov04_0225463C(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    Ov04RideEnv *env = TaskManager_GetEnvironment(taskManager);

    switch (env->state) {
    case 0:
        TaskManager_Call(*(void **)((u8 *)fieldSystem + 0x10), ov01_02205A60, NULL);
        env->state++;
        break;
    case 1:
        SysTask_CreateOnMainQueue(ov04_02254724, env, 0);
        env->state++;
        break;
    case 10:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

void ov04_02254698(Ov04Vec *result, const u16 *from, const u16 *to) {
    Ov04Vec vec;
    vec.x = (to[0] - from[0]) << 12;
    vec.z = (to[1] - from[1]) << 12;
    vec.y = 0;
    *result = vec;
}

void ov04_022546C8(const Ov04Vec *vec, Ov04Pair *result) {
    if (vec->x >= 0) {
        result->x = TRUE;
    } else {
        result->x = FALSE;
    }
    if (vec->z >= 0) {
        result->z = TRUE;
        return;
    }
    result->z = FALSE;
}

int ov04_022546E8(BOOL increasing, int current, int delta, u16 target) {
    s32 targetFx = target << 16;
    int result = 0;
    current += delta;
    if (targetFx == current) {
        result = 1;
    } else if (increasing) {
        if (current > targetFx) {
            result = 2;
        }
    } else {
        if (current < targetFx) {
            result = 2;
        }
    }
    return result;
}
