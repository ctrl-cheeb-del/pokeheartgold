#ifndef TO47_OVERLAY02_ESCAPE_ROPE_R4_PRIVATE_H
#define TO47_OVERLAY02_ESCAPE_ROPE_R4_PRIVATE_H

#include "global.h"

#include "constants/sndseq.h"

typedef struct TaskManager TaskManager;
typedef struct PlayerAvatar PlayerAvatar;
typedef struct LocalMapObject LocalMapObject;
typedef struct EventObjectMovementMan EventObjectMovementMan;

typedef struct FieldSystem {
    u8 pad00[0x40];
    PlayerAvatar *playerAvatar;
    u8 pad44[0xA0];
    LocalMapObject *followerMapObject;
} FieldSystem;

typedef struct FieldMoveTaskEnvironment {
    s32 state;
    s32 counter;
    BOOL hasFollower;
    u32 kind;
    EventObjectMovementMan *playerMovement;
    EventObjectMovementMan *followerMovement;
    u32 unk18;
    void *effect;
    LocalMapObject *playerObject;
    FieldSystem *fieldSystem;
    u32 unk28;
    void *unk2C;
} FieldMoveTaskEnvironment;

typedef int (*EscapeRopeStateFunc)(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);

extern const EscapeRopeStateFunc ov02_02253700[];
extern const u8 ov02_02253794[];
extern const u8 ov02_02253820[];

FieldMoveTaskEnvironment *ov02_0224C660(u32 heapId, u32 size);
LocalMapObject *PlayerAvatar_GetMapObject(PlayerAvatar *playerAvatar);
int PlayerAvatar_GetState(PlayerAvatar *playerAvatar);
BOOL FollowMon_IsActive(FieldSystem *fieldSystem);
FieldSystem *TaskManager_GetFieldSystem(TaskManager *taskManager);
FieldMoveTaskEnvironment *TaskManager_GetEnvironment(TaskManager *taskManager);
void Heap_Free(void *ptr);
void *ov01_021FCD2C(FieldSystem *fieldSystem, u32 value);
void ov01_021FCD8C(void *task, u32 mode, s32 amount, u32 duration);
void ov01_021FCD78(void *task);
EventObjectMovementMan *EventObjectMovementMan_Create(LocalMapObject *mapObject, const void *movement);
BOOL EventObjectMovementMan_IsFinish(EventObjectMovementMan *movement);
void EventObjectMovementMan_Delete(EventObjectMovementMan *movement);
BOOL IsPaletteFadeFinished(void);
void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
void PlaySE(u32 seqNo);

FieldMoveTaskEnvironment *CreateFieldEscapeRopeTaskEnv(FieldSystem *fieldSystem, u32 heapId);
BOOL Task_FieldEscapeRope(TaskManager *taskManager);
int ov02_0224C05C(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);
int ov02_0224C0B0(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);
int ov02_0224C14C(TaskManager *, FieldSystem *, FieldMoveTaskEnvironment *);

#endif
