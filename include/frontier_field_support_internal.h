#ifndef POKEHEARTGOLD_FRONTIER_FIELD_SUPPORT_INTERNAL_H
#define POKEHEARTGOLD_FRONTIER_FIELD_SUPPORT_INTERNAL_H
#include "global.h"

#include "constants/maps.h"

#include "field_system.h"
#include "friend_group.h"
#include "heap.h"
#include "launch_application.h"
#include "save_trainer_card.h"
#include "task.h"
#include "unk_0202C730.h"
#include "unk_0202D230.h"
#include "unk_02030A98.h"
#include "unk_02035900.h"
#include "unk_020379A0.h"
#include "unk_0204B538.h"

extern FrontierData *Save_FrontierData_Get(SaveData *saveData);
extern void sub_0202D638(FrontierData *frontierData, u32 value);
extern u32 sub_0202D63C(FrontierData *frontierData);
extern BOOL sub_0203A05C(SaveData *saveData);
typedef struct SummaryWaitEnv SummaryWaitEnv;
extern u32 sub_02066EDC(SummaryWaitEnv *env, FieldSystem *fieldSystem, enum HeapID heapId);
extern u32 sub_02066F90(SummaryWaitEnv *env, FieldSystem *fieldSystem);
extern u32 sub_02066FEC(SummaryWaitEnv *env, FieldSystem *fieldSystem, enum HeapID heapId);

typedef struct AppWaitEnv {
    u32 result;
    u32 state;
    void *app;
    u8 filler_C[4];
    u16 outputVar;
    u16 arg1;
    u16 arg2;
} AppWaitEnv;

struct SummaryWaitEnv {
    u8 filler[0xD];
    u8 selected;
    u8 filler_E[6];
    void **app;
};

typedef struct SmallTaskEnv {
    u16 kind;
    u16 outputVar;
} SmallTaskEnv;

typedef struct Unk67484Inner {
    u8 filler[0x24];
    u16 x;
    u16 z;
    u16 y;
} Unk67484Inner;

typedef struct Unk67484Outer {
    u8 filler[0xA0];
    Unk67484Inner *inner;
} Unk67484Outer;

u32 sub_02067088(SummaryWaitEnv *env, FieldSystem *fieldSystem);
BOOL sub_020670B0(TaskManager *taskManager);
void sub_02067118(TaskManager *taskManager, void **app, u8 a0, u8 a1, u8 a2, u8 a3, u8 a4, u8 a5);
u32 sub_02067164(AppWaitEnv *env, FieldSystem *fieldSystem);
u32 sub_0206718C(AppWaitEnv *env, FieldSystem *fieldSystem);
BOOL sub_020671B0(TaskManager *taskManager);
void sub_02067200(TaskManager *taskManager, u16 arg1, u16 outputVar, u16 arg2);
BOOL sub_02067238(TaskManager *taskManager);
void sub_020672A4(TaskManager *taskManager, u16 kind, u16 outputVar);

u32 sub_020672D8(SaveData *saveData);
u32 sub_02067398(SaveData *saveData);
void sub_02067484(Unk67484Outer *outer, const int *delta);
u32 sub_020674A4(u32 value);
u32 sub_020674B0(u32 value);
u32 sub_020674BC(SaveData *saveData);
u32 sub_020674E0(SaveData *saveData);
u32 sub_0206751C(SaveData *saveData);
BOOL FieldSystem_MapIsBattleTowerMultiPartnerSelectRoom(FieldSystem *fieldSystem);
void sub_0206759C(SaveData *saveData, int days);

#endif
