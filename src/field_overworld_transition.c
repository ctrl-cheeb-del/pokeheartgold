#include "field_overworld_transition_internal.h"

BOOL sub_02055244(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    if (!sub_0203DF7C(fieldSystem)) {
        return TRUE;
    }
    return FALSE;
}

void CallTask_LeaveOverworld(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    if (!sub_0203DF7C(fieldSystem)) {
        GF_AssertFail();
        return;
    }
    sub_0203DF34(fieldSystem);
    TaskManager_Call(taskManager, sub_02055244, NULL);
}

BOOL sub_0205528C(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    if (sub_020505C8(fieldSystem)) {
        return TRUE;
    }
    return FALSE;
}

void CallTask_RestoreOverworld(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    if (sub_0203DF7C(fieldSystem)) {
        GF_AssertFail();
        return;
    }
    FieldSystem_LoadFieldOverlay(fieldSystem);
    TaskManager_Call(taskManager, sub_0205528C, NULL);
}

BOOL sub_020552D4(void *taskManager) {
    if (IsPaletteFadeFinished()) {
        return TRUE;
    }
    return FALSE;
}

void PaletteFadeUntilFinished(void *taskManager) {
    if (!sub_0203DF7C(TaskManager_GetFieldSystem(taskManager))) {
        GF_AssertFail();
        return;
    }
    BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 4);
    TaskManager_Call(taskManager, sub_020552D4, NULL);
}

void CallTask_FadeFromBlack(void *taskManager) {
    if (!sub_0203DF7C(TaskManager_GetFieldSystem(taskManager))) {
        GF_AssertFail();
        return;
    }
    BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 4);
    TaskManager_Call(taskManager, sub_020552D4, NULL);
}

BOOL sub_02055370(void *taskManager) {
    u32 *state = TaskManager_GetStatePtr(taskManager);
    switch (*state) {
    case 0:
        PaletteFadeUntilFinished(taskManager);
        (*state)++;
        break;
    case 1:
        CallTask_LeaveOverworld(taskManager);
        (*state)++;
        break;
    case 2:
        return TRUE;
    }
    return FALSE;
}

void sub_020553B0(void *taskManager) {
    TaskManager_Call(taskManager, sub_02055370, NULL);
}

BOOL sub_020553C0(void *taskManager) {
    u32 *state = TaskManager_GetStatePtr(taskManager);
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    switch (*state) {
    case 0:
        CallTask_RestoreOverworld(taskManager);
        (*state)++;
        break;
    case 1:
        FieldSystem_DrawMapNameAnimation(fieldSystem);
        CallTask_FadeFromBlack(taskManager);
        (*state)++;
        break;
    case 2:
        return TRUE;
    }
    return FALSE;
}

void sub_02055408(void *taskManager) {
    TaskManager_Call(taskManager, sub_020553C0, NULL);
}
