#include "field_transition_tasks_internal.h"

BOOL sub_020566F8(TaskManager *taskManager) {
    u8 *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    TransitionEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0: {
        void *object;
        int direction;
        FieldMap_FadeScreen(1);
        object = PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
        direction = PlayerAvatar_GetFacingDirection(*(void **)(fieldSystem + 0x40));
        if (direction == 2) {
            MapObject_SetHeldMovement(object, 10);
        } else if (direction == 3) {
            MapObject_SetHeldMovement(object, 11);
        } else {
            GF_AssertFail();
        }
        env->state++;
        break;
    }
    case 1: {
        void *object = PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
        if (MapObject_IsMovementPaused(object) == TRUE) {
            MapObject_ClearHeldMovementIfActive(object);
            if (FollowMon_IsActive(fieldSystem)) {
                ov01_02205790(fieldSystem, (u8)PlayerAvatar_GetFacingDirection(*(void **)(fieldSystem + 0x40)));
            }
            env->state++;
        }
        break;
    }
    case 2:
        if (IsPaletteFadeFinished()) {
            env->state++;
        }
        break;
    case 3:
        return TRUE;
    }
    return FALSE;
}

BOOL sub_020567B4(TaskManager *taskManager) {
    u8 *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    TransitionEnv *env = TaskManager_GetEnvironment(taskManager);
    PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
    switch (env->state) {
    case 0: {
        void *work;
        int x;
        env->work = ov01_021E90C0();
        work = env->work;
        x = PlayerAvatar_GetXCoord(*(void **)(fieldSystem + 0x40));
        ov01_021E90DC(x, PlayerAvatar_GetZCoord(*(void **)(fieldSystem + 0x40)), work);
        TaskManager_Call(taskManager, ov01_021E9C40, work);
        env->state++;
        break;
    }
    case 1:
        ov01_021E90D4(env->work);
        return TRUE;
    }
    return FALSE;
}

BOOL sub_0205681C(TaskManager *taskManager) {
    u8 *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    TransitionEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0:
        env->work = Heap_AllocAtEnd(11, 8);
        *(u32 *)env->work = 0;
        FieldMap_FadeScreen(1);
        env->state++;
        break;
    case 1: {
        void *object = PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
        int *counter = (int *)env->work;
        VecFx32 position;
        (*counter)++;
        MapObject_CopyPositionVector(object, &position);
        position.y += 2 << 12;
        MapObject_SetPositionVector(object, &position);
        if (*counter >= 16) {
            PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate(*(void **)(fieldSystem + 0x40), TRUE);
            env->state++;
        }
        break;
    }
    case 2:
        Field_PlayerAvatar_OrrTransitionFlags(*(void **)(fieldSystem + 0x40), 1);
        Field_PlayerAvatar_ApplyTransitionFlags(*(void **)(fieldSystem + 0x40));
        env->state++;
        break;
    case 3: {
        void *object = PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
        if (MapObject_AreBitsSetForMovementScriptInit(object)) {
            MapObject_SetHeldMovement(object, 12);
            env->state++;
        }
        break;
    }
    case 4:
        if (MapObject_AreBitsSetForMovementScriptInit(PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40))) && IsPaletteFadeFinished()) {
            if (FollowMon_IsActive(fieldSystem)) {
                ov01_02205790(fieldSystem, 0);
                sub_0205FC94(FollowMon_GetMapObject(fieldSystem), 0x30);
                sub_02069DC8(FollowMon_GetMapObject(fieldSystem), 1);
            }
            env->state++;
        }
        break;
    case 5:
        Heap_Free(env->work);
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02056938(TaskManager *taskManager) {
    u8 *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    TransitionEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0:
        env->work = Heap_AllocAtEnd(11, 8);
        *(u32 *)env->work = 0;
        FieldMap_FadeScreen(1);
        env->state++;
        break;
    case 1: {
        void *object = PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
        int *counter = (int *)env->work;
        VecFx32 position;
        (*counter)++;
        MapObject_CopyPositionVector(object, &position);
        position.y -= 2 << 12;
        MapObject_SetPositionVector(object, &position);
        if (*counter >= 16) {
            PlayerAvatar_ToggleAutomaticHeightUpdatingImmediate(*(void **)(fieldSystem + 0x40), TRUE);
            env->state++;
        }
        break;
    }
    case 2:
        Field_PlayerAvatar_OrrTransitionFlags(*(void **)(fieldSystem + 0x40), 1);
        Field_PlayerAvatar_ApplyTransitionFlags(*(void **)(fieldSystem + 0x40));
        env->state++;
        break;
    case 3: {
        void *object = PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40));
        if (MapObject_AreBitsSetForMovementScriptInit(object)) {
            MapObject_SetHeldMovement(object, 13);
            env->state++;
        }
        break;
    }
    case 4:
        if (MapObject_AreBitsSetForMovementScriptInit(PlayerAvatar_GetMapObject(*(void **)(fieldSystem + 0x40))) && IsPaletteFadeFinished()) {
            if (FollowMon_IsActive(fieldSystem)) {
                ov01_02205790(fieldSystem, 1);
                sub_0205FC94(FollowMon_GetMapObject(fieldSystem), 0x30);
                sub_02069DC8(FollowMon_GetMapObject(fieldSystem), 1);
            }
            env->state++;
        }
        break;
    case 5:
        Heap_Free(env->work);
        return TRUE;
    }
    return FALSE;
}
