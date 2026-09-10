#include "field_transition_tasks_internal.h"

static const void *const sApplicationTemplate[] = {
    ov45_02229EE0,
    ov45_02229F70,
    ov45_02229F94,
    &SDK_OVERLAY_OVY_45_ID,
};

void sub_02056BC8(void *fieldSystem_) {
    u8 *fieldSystem = fieldSystem_;
    VecFx32 position;
    VecFx32 delta;
    VecFx32 *currentTarget = Camera_GetCurrentTarget(*(void **)(fieldSystem + 0x24));
    VecFx32 lookAt = Camera_GetLookAtCamTarget(*(void **)(fieldSystem + 0x24));
    void *object;
    VEC_Subtract(&lookAt, currentTarget, &delta);
    object = PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
    PlayerAvatar_CopyPositionVector(*(void **)(fieldSystem + 0x40), &position);
    PlayerAvatar_ToggleAutomaticHeightUpdating(*(void **)(fieldSystem + 0x40), FALSE);
    position.y -= 2 << 16;
    sub_0205C810(*(void **)(fieldSystem + 0x40), &position, 0);
    Camera_SetLookAtTargetAndRecalcPos(PlayerAvatar_GetPositionVector(*(void **)(fieldSystem + 0x40)), *(void **)(fieldSystem + 0x24));
    Camera_SetFixedTarget(PlayerAvatar_GetPositionVector(*(void **)(fieldSystem + 0x40)), *(void **)(fieldSystem + 0x24));
    Camera_OffsetLookAtPosAndTarget(&delta, *(void **)(fieldSystem + 0x24));
    MapObject_ClearHeldMovementIfActive(object);
    Field_PlayerAvatar_OrrTransitionFlags(*(void **)(fieldSystem + 0x40), 2 << 8);
    Field_PlayerAvatar_ApplyTransitionFlags(*(void **)(fieldSystem + 0x40));
    sub_0205F328(object, 0);
}

void sub_02056C64(void *fieldSystem_) {
    u8 *fieldSystem = fieldSystem_;
    VecFx32 position;
    VecFx32 delta;
    VecFx32 *currentTarget = Camera_GetCurrentTarget(*(void **)(fieldSystem + 0x24));
    VecFx32 lookAt = Camera_GetLookAtCamTarget(*(void **)(fieldSystem + 0x24));
    void *object;
    VEC_Subtract(&lookAt, currentTarget, &delta);
    object = PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
    PlayerAvatar_CopyPositionVector(*(void **)(fieldSystem + 0x40), &position);
    PlayerAvatar_ToggleAutomaticHeightUpdating(*(void **)(fieldSystem + 0x40), FALSE);
    position.y += 2 << 16;
    sub_0205C810(*(void **)(fieldSystem + 0x40), &position, 0);
    Camera_SetLookAtTargetAndRecalcPos(PlayerAvatar_GetPositionVector(*(void **)(fieldSystem + 0x40)), *(void **)(fieldSystem + 0x24));
    Camera_SetFixedTarget(PlayerAvatar_GetPositionVector(*(void **)(fieldSystem + 0x40)), *(void **)(fieldSystem + 0x24));
    Camera_OffsetLookAtPosAndTarget(&delta, *(void **)(fieldSystem + 0x24));
    MapObject_ClearHeldMovementIfActive(object);
    Field_PlayerAvatar_OrrTransitionFlags(*(void **)(fieldSystem + 0x40), 2 << 8);
    Field_PlayerAvatar_ApplyTransitionFlags(*(void **)(fieldSystem + 0x40));
    sub_0205F328(object, 0);
}

void sub_02056D00(TaskManager *taskManager, u16 parameter) {
    AppEnv *env = Heap_AllocAtEnd(11, sizeof(AppEnv));
    memset(env, 0, sizeof(AppEnv));
    env->parameter = parameter;
    TaskManager_Call(taskManager, sub_02056D30, env);
}

BOOL sub_02056D30(TaskManager *taskManager) {
    u8 *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    AppEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0:
        env->saveData = *(void **)(fieldSystem + 0xC);
        env->value = env->parameter;
        env->fieldArg = fieldSystem + 0xB4;
        CallApplicationAsTask(taskManager, sApplicationTemplate, &env->fieldArg);
        env->state++;
        break;
    case 1:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}
