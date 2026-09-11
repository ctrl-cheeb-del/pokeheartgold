#ifndef PRIVATE_UNK_02062108_H
#define PRIVATE_UNK_02062108_H

#include "global.h"

#include "heap.h"
#include "map_object.h"
#include "sys_task_api.h"
#include "unk_02062108.h"

struct EventObjectMovementWork {
    u32 state;
    BOOL finished;
    s32 index;
    LocalMapObject *object;
    const MovementScriptCommand *command;
};

typedef BOOL (*MovementStateFunc)(struct EventObjectMovementWork *);
typedef BOOL (*MovementCommandFunc)(LocalMapObject *object);

extern const MovementStateFunc sMovementScriptMachineStateFuncs[];
extern const u32 _020FDA28[4];
extern const u32 *const _020FD198[];
extern const MovementCommandFunc *const gMovementCmdTable[];

void MovementScriptMachine(SysTask *, void *);
BOOL MovementScriptMachineSub_Init(struct EventObjectMovementWork *);
BOOL MovementScriptMachineSub_WaitReady(struct EventObjectMovementWork *);
BOOL MovementScriptMachineSub_SetMovementCommand(struct EventObjectMovementWork *);
BOOL MovementScriptMachineSub_WaitMovementCommand(struct EventObjectMovementWork *);
BOOL MovementScriptMachineSub_LoopCheck(struct EventObjectMovementWork *);
BOOL MovementScriptMachineSub_Done(struct EventObjectMovementWork *);
u32 sub_0206234C(s32, u32);
s32 sub_02062390(u32);
BOOL sub_020623C8(u32);
u32 sub_020623D8(s32);
void sub_02062400(LocalMapObject *);
BOOL sub_02062428(LocalMapObject *);
BOOL MapObject_RunMovementCommand(LocalMapObject *, u32, u32);
BOOL MapObjectMovementCmd098_Step2(LocalMapObject *);
void sub_0206247C(LocalMapObject *, u32);
void sub_02060F78(LocalMapObject *);

#endif
