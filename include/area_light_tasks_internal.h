#ifndef TO40_UNK_020979A8_PRIVATE_H
#define TO40_UNK_020979A8_PRIVATE_H
#include "global.h"

#include "field_system.h"
#include "task.h"
typedef struct AreaLightTaskEnv {
    u8 state, param1, param2, pad03;
    u32 mapId, x, y;
    ModelAttributes light;
} AreaLightTaskEnv;
typedef struct NightTaskEnv {
    u8 param, night;
    u8 pad02[2];
    void *destination;
} NightTaskEnv;
void LoadAreaOrDungeonLightTxt(u32 archiveId, ModelAttributes *attributes);
void sub_020979A8(FieldSystem *, u8, u8, u32, u32, u32);
void sub_0203FC90(FieldSystem *, void *);
void CallTask_LeaveOverworld(TaskManager *);
void sub_02055408(TaskManager *);
void sub_020979EC(FieldSystem *, u8, void *);
BOOL sub_02097A48(TaskManager *);
BOOL sub_02097AA0(TaskManager *);
#endif
