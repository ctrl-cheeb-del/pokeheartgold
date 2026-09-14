#include "to47_overlay02_escape_rope_r4_private.h"

FieldMoveTaskEnvironment *CreateFieldEscapeRopeTaskEnv(FieldSystem *fieldSystem, u32 heapId)
{
    FieldMoveTaskEnvironment *env = ov02_0224C660(heapId, 0x30);
    int state;

    env->kind = 0;
    env->fieldSystem = fieldSystem;
    env->playerObject = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    state = PlayerAvatar_GetState(fieldSystem->playerAvatar);
    if (state == 1 || state == 2) {
        env->hasFollower = FALSE;
    } else if (FollowMon_IsActive(fieldSystem)) {
        env->hasFollower = TRUE;
    } else {
        env->hasFollower = FALSE;
    }
    return env;
}

BOOL Task_FieldEscapeRope(TaskManager *taskManager)
{
    int result;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    FieldMoveTaskEnvironment *env = TaskManager_GetEnvironment(taskManager);

    do {
        result = ov02_02253700[env->state](taskManager, fieldSystem, env);
        if (result == 2) {
            Heap_Free(env);
        }
    } while (result == 1);
    return FALSE;
}

int ov02_0224C05C(TaskManager *unused, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env)
{
    void *effect = ov01_021FCD2C(fieldSystem, 4);

    env->effect = effect;
    ov01_021FCD8C(effect, 1, (s32)0xFFF6A000, 15);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, ov02_02253820);
    if (env->hasFollower != 0) {
        env->followerMovement = EventObjectMovementMan_Create(fieldSystem->followerMapObject, ov02_02253820);
    }
    env->state++;
    PlaySE(SEQ_SE_DP_KAIDAN2);
    return 0;
}

int ov02_0224C0B0(TaskManager *unused, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env)
{
    if (!EventObjectMovementMan_IsFinish(env->playerMovement)) {
        return 0;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    env->playerMovement = EventObjectMovementMan_Create(env->playerObject, ov02_02253794);
    if (env->hasFollower != 0) {
        EventObjectMovementMan_Delete(env->followerMovement);
        env->followerMovement = EventObjectMovementMan_Create(fieldSystem->followerMapObject, ov02_02253794);
    }
    env->counter++;
    if (env->counter < 8) {
        return 0;
    }
    if (env->kind == 2) {
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 4);
    } else {
        BeginNormalPaletteFade(0, 0, 0, 0x7FFF, 6, 1, 4);
    }
    env->state++;
    return 0;
}

int ov02_0224C14C(TaskManager *unused, FieldSystem *fieldSystem, FieldMoveTaskEnvironment *env)
{
    if (EventObjectMovementMan_IsFinish(env->playerMovement) == 1) {
        EventObjectMovementMan_Delete(env->playerMovement);
        env->playerMovement = EventObjectMovementMan_Create(env->playerObject, ov02_02253794);
        if (env->hasFollower != 0) {
            EventObjectMovementMan_Delete(env->followerMovement);
            env->followerMovement = EventObjectMovementMan_Create(fieldSystem->followerMapObject, ov02_02253794);
        }
    }
    if (!IsPaletteFadeFinished()) {
        return 0;
    }
    EventObjectMovementMan_Delete(env->playerMovement);
    if (env->hasFollower != 0) {
        EventObjectMovementMan_Delete(env->followerMovement);
    }
    ov01_021FCD78(env->effect);
    env->state++;
    return 1;
}
