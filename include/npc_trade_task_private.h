#ifndef POKEHEARTGOLD_UNK_0206793C_PRIVATE_H
#define POKEHEARTGOLD_UNK_0206793C_PRIVATE_H
#include <nitro/fs/overlay.h>

#include "global.h"

#include "heap.h"
#include "npc_trade.h"
#include "overlay_71.h"
#include "task.h"
#include "unk_02055244.h"
extern u8 SDK_OVERLAY_OVY_71_ID;
typedef struct NPCTradeTaskEnv {
    NPCTradeAppData *tradeWork;
    int state;
    int slot;
    TRADE_ANIM_WORK animWork;
    Pokemon *myMon;
    Pokemon *tradeMon;
} NPCTradeTaskEnv;
void CallTask_RestoreOverworld(TaskManager *);
BOOL Task_NPCTrade(TaskManager *);
void sub_0206793C(TaskManager *);
void CallTask_NPCTrade(TaskManager *, NPCTradeAppData *, u16, enum HeapID);
#endif
