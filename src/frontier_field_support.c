#include "frontier_field_support_internal.h"

u32 sub_02067088(SummaryWaitEnv *env, FieldSystem *fieldSystem) {
    u8 *args;
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return 3;
    }
    args = *env->app;
    env->selected = args[0x14];
    Heap_Free(args);
    *env->app = NULL;
    return 0;
}

BOOL sub_020670B0(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    SummaryWaitEnv *env = TaskManager_GetEnvironment(taskManager);
    u32 *state = (u32 *)((u8 *)env + 4);
    switch (*state) {
    case 0:
        *state = sub_02066EDC(env, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 1:
        *state = sub_02066F90(env, fieldSystem);
        break;
    case 2:
        *state = sub_02066FEC(env, fieldSystem, HEAP_ID_FIELD2);
        break;
    case 3:
        *state = sub_02067088(env, fieldSystem);
        break;
    case 4:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

void sub_02067118(TaskManager *taskManager, void **app, u8 a0, u8 a1, u8 a2, u8 a3, u8 a4, u8 a5) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    SummaryWaitEnv *env = Heap_Alloc(HEAP_ID_FIELD2, 0x18);
    MI_CpuClear8(env, 0x18);
    ((u8 *)env)[8] = a0;
    ((u8 *)env)[9] = a1;
    ((u8 *)env)[10] = a2;
    ((u8 *)env)[11] = a3;
    ((u8 *)env)[12] = a4;
    ((u8 *)env)[13] = a5;
    env->app = app;
    TaskManager_Call(fieldSystem->taskman, sub_020670B0, env);
}

u32 sub_02067164(AppWaitEnv *env, FieldSystem *fieldSystem) {
    if (sub_0203A05C(fieldSystem->saveData)) {
        env->app = NintendoWifiConnection_LaunchApp(fieldSystem, env->arg1, env->arg2);
        return 1;
    }
    env->result = 1;
    return 2;
}

u32 sub_0206718C(AppWaitEnv *env, FieldSystem *fieldSystem) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return 1;
    }
    env->result = ((u32 *)env->app)[8];
    Heap_Free(env->app);
    return 2;
}

BOOL sub_020671B0(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    AppWaitEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0:
        env->state = sub_02067164(env, fieldSystem);
        break;
    case 1:
        env->state = sub_0206718C(env, fieldSystem);
        break;
    case 2:
        *GetVarPointer(fieldSystem, env->outputVar) = env->result;
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

void sub_02067200(TaskManager *taskManager, u16 arg1, u16 outputVar, u16 arg2) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    AppWaitEnv *env = Heap_Alloc(HEAP_ID_FIELD2, sizeof(AppWaitEnv));
    MI_CpuClear8(env, sizeof(AppWaitEnv));
    env->arg1 = arg1;
    env->arg2 = arg2;
    env->outputVar = outputVar;
    TaskManager_Call(fieldSystem->taskman, sub_020671B0, env);
}

BOOL sub_02067238(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    SmallTaskEnv *env = TaskManager_GetEnvironment(taskManager);
    u16 *linkData = sub_02037C44(1 - sub_0203769C());
    u16 *output;
    if (linkData == NULL) {
        return FALSE;
    }
    output = GetVarPointer(fieldSystem, env->outputVar);
    switch (env->kind) {
    case 0:
        *output = sub_0204B610(fieldSystem, linkData);
        break;
    case 1:
        *output = sub_0204B66C(fieldSystem, linkData);
        break;
    case 2:
        *output = sub_0204B690(fieldSystem, linkData);
        break;
    }
    Heap_Free(env);
    return TRUE;
}

void sub_020672A4(TaskManager *taskManager, u16 kind, u16 outputVar) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    SmallTaskEnv *env = Heap_Alloc(HEAP_ID_FIELD2, sizeof(SmallTaskEnv));
    MI_CpuClear8(env, sizeof(SmallTaskEnv));
    env->kind = kind;
    env->outputVar = outputVar;
    TaskManager_Call(fieldSystem->taskman, sub_02067238, env);
}

u32 sub_020672D8(SaveData *saveData) {
    FrontierData *frontierData;
    u32 stat;
    u8 flag13;
    u8 flag0;
    u8 flag1;

    stat = FrontierSave_GetStat(Save_Frontier_GetStatic(saveData), 0, 0xFF);
    if (stat < 20) {
        return 0;
    }
    frontierData = Save_FrontierData_Get(saveData);
    flag13 = sub_0202D5DC(frontierData, 13, 0);
    flag0 = sub_0202D5DC(frontierData, 0, 0);
    flag1 = sub_0202D5DC(frontierData, 1, 0);
    sub_0202D5DC(frontierData, 14, 0);
    sub_0202D5DC(frontierData, 2, 0);
    sub_0202D5DC(frontierData, 3, 0);
    if (flag13 != 0 && flag0 != 0 && flag1 != 0) {
        return 0;
    }
    if (flag13 == 0) {
        sub_0202D5DC(frontierData, 13, 1);
        return 1;
    }
    if (stat < 50) {
        return 0;
    }
    if (flag0 == 0) {
        sub_0202D5DC(frontierData, 0, 1);
        return 2;
    }
    if (stat < 100 || flag1 != 0) {
        return 0;
    }
    sub_0202D5DC(frontierData, 1, 1);
    return 3;
}

u32 sub_02067398(SaveData *saveData) {
    FrontierData *frontierData;
    u32 stat;
    u8 flag13;
    u8 flag0;
    u8 flag1;
    u8 flag14;
    u8 flag2;
    u8 flag3;

    stat = FrontierSave_GetStat(Save_Frontier_GetStatic(saveData), 0, 0xFF);
    if (stat < 20) {
        return 0;
    }
    frontierData = Save_FrontierData_Get(saveData);
    flag13 = sub_0202D5DC(frontierData, 13, 0);
    flag0 = sub_0202D5DC(frontierData, 0, 0);
    flag1 = sub_0202D5DC(frontierData, 1, 0);
    flag14 = sub_0202D5DC(frontierData, 14, 0);
    flag2 = sub_0202D5DC(frontierData, 2, 0);
    flag3 = sub_0202D5DC(frontierData, 3, 0);
    if (flag13 != 0 && flag0 != 0 && flag1 != 0) {
        return 0;
    }
    if (flag13 == 0) {
        if (flag14 != 0) {
            return 4;
        }
        return 1;
    }
    if (stat < 50) {
        return 0;
    }
    if (flag0 == 0) {
        if (flag2 != 0) {
            return 5;
        }
        return 2;
    }
    if (stat < 100) {
        return 0;
    }
    if (flag1 != 0) {
        return 0;
    }
    if (flag3 != 0) {
        return 6;
    }
    return 3;
}

void sub_02067484(Unk67484Outer *outer, const int *delta) {
    Unk67484Inner *inner = outer->inner;
    inner->x += delta[0];
    inner->y += delta[1];
    inner->z += delta[2];
}

u32 sub_020674A4(u32 value) {
    return value * 0x02E90EDD + 1;
}

u32 sub_020674B0(u32 value) {
    return value * 0x5D588B65 + 1;
}

u32 sub_020674BC(SaveData *saveData) {
    u32 value = sub_020674B0(sub_0202C7DC(Save_FriendGroup_Get(saveData)));
    sub_0202D638(Save_FrontierData_Get(saveData), value);
    return value;
}

u32 sub_020674E0(SaveData *saveData) {
    FrontierData *frontierData = Save_FrontierData_Get(saveData);
    u32 value = sub_020674B0(sub_0202D63C(frontierData));
    u32 next;
    sub_0202D638(frontierData, value);
    next = sub_020674A4(value);
    sub_0202D308(sub_0202D908(saveData), 10, &next);
    return next;
}

u32 sub_0206751C(SaveData *saveData) {
    FrontierData *frontierData = Save_FrontierData_Get(saveData);
    u32 unk = sub_0202D908(saveData);
    u32 value = sub_020674A4(sub_0202D63C(frontierData));
    s32 i;
    s32 count;
    count = sub_0202D57C(frontierData, (u16)sub_0202D284(unk, 0, 0), 0) * 24;
    i = 0;
    for (i = 0; i < count; i++) {
        value = sub_020674A4(value);
    }
    sub_0202D308(sub_0202D908(saveData), 10, &value);
    return value;
}

BOOL FieldSystem_MapIsBattleTowerMultiPartnerSelectRoom(FieldSystem *fieldSystem) {
    return fieldSystem->location->mapId == MAP_BATTLE_TOWER_PARTNER_ROOM;
}
