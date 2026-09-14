#include "global.h"

typedef struct TaskManager TaskManager;
typedef struct PlayerAvatar PlayerAvatar;
typedef struct Pokemon Pokemon;
typedef struct LocalMapObject LocalMapObject;
typedef struct EventObjectMovementMan EventObjectMovementMan;

typedef struct FieldSystem {
    u8 pad00[0x40];
    PlayerAvatar *playerAvatar;
    u8 pad44[0x108 - 0x44];
    void *unk108;
} FieldSystem;

typedef struct FieldMoveTaskEnvironment {
    u32 state;
    s32 count;
    BOOL useMon;
    u32 kind;
    EventObjectMovementMan *movement;
    u8 pad14[4];
    void *effect;
    void *task;
    LocalMapObject *mapObject;
    FieldSystem *fieldSystem;
    Pokemon *mon;
} FieldMoveTaskEnvironment;

typedef int (*Ov02FieldTaskFunc)(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);

extern FieldSystem *TaskManager_GetFieldSystem(TaskManager *taskManager);
extern FieldMoveTaskEnvironment *TaskManager_GetEnvironment(TaskManager *taskManager);
extern u32 *TaskManager_GetStatePtr(TaskManager *taskManager);
extern void TaskManager_Call(TaskManager *taskManager, void *task, void *env);
extern void Heap_Free(void *ptr);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern void *ov01_021FCD2C(FieldSystem *fieldSystem, u32 value);
extern void ov01_021FCD8C(void *task, u32, s32, u32);
extern BOOL ov01_021FCD6C(void *task);
extern void ov01_021FCD78(void *task);
extern EventObjectMovementMan *EventObjectMovementMan_Create(LocalMapObject *mapObject, const void *movement);
extern BOOL EventObjectMovementMan_IsFinish(EventObjectMovementMan *movement);
extern void EventObjectMovementMan_Delete(EventObjectMovementMan *movement);
extern BOOL IsPaletteFadeFinished(void);
extern FieldMoveTaskEnvironment *ov02_0224C660(u32 heapId, u32 size);
extern LocalMapObject *PlayerAvatar_GetMapObject(PlayerAvatar *avatar);
extern BOOL ov01_02206268(FieldSystem *fieldSystem);
extern u32 ov01_022062CC(FieldSystem *fieldSystem);
extern u32 PlayerAvatar_GetGender(PlayerAvatar *avatar);
extern void *ov02_02249458(FieldSystem *, u32, Pokemon *, u32);
extern BOOL ov02_02250780(FieldSystem *, u32);
extern void ov02_022507B4(FieldSystem *, u32);
extern void FieldSystem_UnkSub108_AddMonMood(void *, u32);
extern u32 GetMonData(Pokemon *, u32, void *);
extern void PlayCry(u16 species, u8 form);
extern BOOL IsCryFinished(void);
extern void ov01_02205A60(void);
extern const Ov02FieldTaskFunc ov02_022536F0[];
extern const Ov02FieldTaskFunc ov02_02253710[];
extern const Ov02FieldTaskFunc ov02_02253754[];
extern const void *ov02_02253794;
extern const void *ov02_02253884;

BOOL ov02_0224C1F8(TaskManager *taskManager);
int ov02_0224C234(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);
int ov02_0224C2A8(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);
int ov02_0224C2EC(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);
int ov02_0224C338(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);
FieldMoveTaskEnvironment *FieldMoveTask_CreateDigEnvironment(FieldSystem *, Pokemon *, u8, u32);
BOOL Task_FieldDig(TaskManager *taskManager);
int ov02_0224C4B4(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);

BOOL ov02_0224C1F8(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveTaskEnvironment *env = TaskManager_GetEnvironment(taskManager);
    int result;
    do {
        result = ov02_022536F0[env->state](taskManager, fieldSystem, env);
        if (result == 2) {
            Heap_Free(env);
            return TRUE;
        }
    } while (result == 1);
    return FALSE;
}

int ov02_0224C234(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    void *task;
    if (env->kind == 2) {
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 4);
    } else {
        BeginNormalPaletteFade(0, 1, 1, 0x7FFF, 6, 1, 4);
    }
    task = ov01_021FCD2C(fieldSystem, 4);
    env->task = task;
    ov01_021FCD8C(task, 1, (s32)0xFFF6A000, 1);
    env->movement = EventObjectMovementMan_Create(env->mapObject, &ov02_02253794);
    env->state++;
    return 0;
}

int ov02_0224C2A8(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (EventObjectMovementMan_IsFinish(env->movement) == 1) {
        EventObjectMovementMan_Delete(env->movement);
        env->movement = EventObjectMovementMan_Create(env->mapObject, &ov02_02253794);
    }
    if (!IsPaletteFadeFinished()) {
        return 0;
    }
    ov01_021FCD8C(env->task, 2, 0, 0x3C);
    env->state++;
    return 1;
}

int ov02_0224C2EC(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->movement)) {
        return 0;
    }
    EventObjectMovementMan_Delete(env->movement);
    if (++env->count < 4) {
        env->movement = EventObjectMovementMan_Create(env->mapObject, &ov02_02253794);
        return 0;
    }
    env->movement = EventObjectMovementMan_Create(env->mapObject, &ov02_02253884);
    env->state++;
    return 0;
}

int ov02_0224C338(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    if (!EventObjectMovementMan_IsFinish(env->movement)) {
        return 0;
    }
    if (!ov01_021FCD6C(env->task)) {
        return 0;
    }
    ov01_021FCD78(env->task);
    EventObjectMovementMan_Delete(env->movement);
    return 2;
}

FieldMoveTaskEnvironment *FieldMoveTask_CreateDigEnvironment(FieldSystem *fieldSystem, Pokemon *mon, u8 slot, u32 heapId) {
    FieldMoveTaskEnvironment *env = ov02_0224C660(heapId, 0x30);
    env->kind = 1;
    env->fieldSystem = fieldSystem;
    env->mapObject = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    env->mon = mon;
    if (ov01_02206268(fieldSystem) && slot == ov01_022062CC(fieldSystem)) {
        env->useMon = TRUE;
    } else {
        env->useMon = FALSE;
    }
    return env;
}

BOOL Task_FieldDig(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveTaskEnvironment *env = TaskManager_GetEnvironment(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);
    int result;

    switch (*state) {
    case 0:
        if (env->useMon) {
            TaskManager_Call(taskManager, ov01_02205A60, NULL);
        }
        (*state)++;
        break;
    case 1:
        (*state)++;
        if (env->useMon) {
            if (ov02_02250780(fieldSystem, 4)) {
                result = 2;
                FieldSystem_UnkSub108_AddMonMood(fieldSystem->unk108, 1);
            } else {
                result = 1;
            }
            ov02_022507B4(fieldSystem, result);
            break;
        }
    case 2:
        if (env->useMon) {
            u32 species = GetMonData(env->mon, 5, NULL);
            u32 form = GetMonData(env->mon, 0x70, NULL);
            PlayCry((u16)species, (u8)form);
        }
        (*state)++;
    case 3:
        do {
            if (env->useMon) {
                if (IsCryFinished()) {
                    result = 0;
                } else {
                    result = ov02_02253710[env->state](taskManager, fieldSystem, env);
                }
            } else {
                result = ov02_02253754[env->state](taskManager, fieldSystem, env);
            }
            if (result == 2) {
                Heap_Free(env);
            }
        } while (result == 1);
        break;
    }
    return FALSE;
}

int ov02_0224C4B4(TaskManager *taskManager, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env) {
    u32 gender = PlayerAvatar_GetGender(fieldSystem->playerAvatar);
    env->effect = ov02_02249458(fieldSystem, 0, env->mon, gender);
    env->state++;
    return 0;
}
