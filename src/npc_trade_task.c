#include "npc_trade_task_private.h"

const OverlayManagerTemplate _020FE79C = {
    TradeSequence_Init,
    TradeSequence_Main,
    TradeSequence_Exit,
    FS_OVERLAY_ID(OVY_71),
};

void sub_0206793C(TaskManager *taskManager) {
    NPCTradeTaskEnv *env;
    TaskManager_GetFieldSystem(taskManager);
    env = TaskManager_GetEnvironment(taskManager);
    CallApplicationAsTask(taskManager, &_020FE79C, &env->animWork);
}

BOOL Task_NPCTrade(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    NPCTradeTaskEnv *env = TaskManager_GetEnvironment(taskManager);

    switch (env->state) {
    case 0:
        NPCTrade_CreateTradeAnim(fieldSystem, env->tradeWork, env->slot, &env->animWork, env->myMon, env->tradeMon);
        NPCTrade_ReceiveMonToSlot(fieldSystem, env->tradeWork, env->slot);
        env->state++;
        break;
    case 1:
        PaletteFadeUntilFinished(taskManager);
        env->state++;
        break;
    case 2:
        CallTask_LeaveOverworld(taskManager);
        env->state++;
        break;
    case 3:
        sub_0206793C(taskManager);
        env->state++;
        break;
    case 4:
        CallTask_RestoreOverworld(taskManager);
        env->state++;
        break;
    case 5:
        CallTask_FadeFromBlack(taskManager);
        env->state++;
        break;
    case 6:
        Heap_Free(env->myMon);
        Heap_Free(env->tradeMon);
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}

void CallTask_NPCTrade(TaskManager *taskManager, NPCTradeAppData *tradeWork, u16 slot, enum HeapID heapId) {
    NPCTradeTaskEnv *env = Heap_Alloc(heapId, sizeof(NPCTradeTaskEnv));
    memset(env, 0, sizeof(NPCTradeTaskEnv));
    env->state = 0;
    env->tradeWork = tradeWork;
    env->slot = slot;
    env->myMon = AllocMonZeroed(heapId);
    env->tradeMon = AllocMonZeroed(heapId);
    TaskManager_Call(taskManager, Task_NPCTrade, env);
}
