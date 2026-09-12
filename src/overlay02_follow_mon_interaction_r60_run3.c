#include "overlay02_follow_mon_interaction_r60_private.h"
int ov02_02250780(void *fieldSystem, int value) {
    void *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(PTR(fieldSystem, 0xc)));
    int a = GetMonData(mon, 0xb1, NULL);
    int b = GetMonData(mon, 0xb2, NULL);
    return a == value || b == value;
}

void ov02_022507B4(void *fieldSystem, u16 count) {
    if ((u32)(FollowMon_GetSpecies(PTR(fieldSystem, 0xe4)) - 0x32) > 1) {
        SmallMoveEnv *env = Heap_AllocAtEnd(0xb, sizeof(SmallMoveEnv));
        env->count = count;
        env->current = 0;
        TaskManager_Call(PTR(fieldSystem, 0x10), ov02_022507E8, env);
    }
}

int ov02_022507E8(void *taskManager) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    SmallMoveEnv *env = TaskManager_GetEnvironment(taskManager);
    int *state = TaskManager_GetStatePtr(taskManager);
    switch (*state) {
    case 0:
        MapObject_UnpauseMovement(PTR(fieldSystem, 0xe4));
        (*state)++;
    case 1:
        if (MapObject_AreBitsSetForMovementScriptInit(FollowMon_GetMapObject(fieldSystem))) {
            MapObject_PauseMovement(PTR(fieldSystem, 0xe4));
            (*state)++;
        }
        break;
    case 2: {
        u8 direction = MapObject_GetFacingDirection(PTR(fieldSystem, 0xe4));
        env->movement = EventObjectMovementMan_Create(PTR(fieldSystem, 0xe4), ov02_02253A70 + direction * 0x14);
        (*state)++;
        break;
    }
    case 3:
        if (EventObjectMovementMan_IsFinish(env->movement) == 1) {
            EventObjectMovementMan_Delete(env->movement);
            env->current++;
            if (env->current >= env->count) {
                (*state)++;
            } else {
                *state = 0;
            }
        }
        break;
    case 4:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}
