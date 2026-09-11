#include "bag_view_tasks_1_private.h"

BOOL sub_02092B04(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    MartReturnEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 24:
        env->state = sub_02092B40(fieldSystem, env);
        break;
    case 25:
        sub_02092B7C(taskManager);
        break;
    }
    return FALSE;
}

BOOL sub_02092B40(FieldSystem *fieldSystem, MartReturnEnv *env) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return 24;
    }
    if (env->result != NULL) {
        env->result[1] = sub_0207791C(env->bagView);
    }
    Heap_Free(env->bagView);
    FieldSystem_LoadFieldOverlay(fieldSystem);
    return 25;
}

void sub_02092B7C(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    MartReturnEnv *env = TaskManager_GetEnvironment(taskManager);
    if (sub_020505C8(fieldSystem)) {
        FieldMap_FadeScreen(1);
        TaskManager_Jump(taskManager, Task_Mart, env);
        env->state = 26;
    }
}
