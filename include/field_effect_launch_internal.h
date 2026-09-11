#ifndef TO40_UNK_020977CC_PRIVATE_H
#define TO40_UNK_020977CC_PRIVATE_H

#include "global.h"

#include "field_system.h"
#include "task.h"

typedef struct AreaLightTaskEnv {
    u8 state;
    u8 param1;
    u8 param2;
    u8 pad03;
    u32 mapId;
    u32 x;
    u32 y;
    ModelAttributes light;
} AreaLightTaskEnv;

typedef struct GenderTaskEnv {
    u8 param;
    u8 gender;
    u8 night;
    u8 pad03;
    void *destination;
} GenderTaskEnv;

void LoadAreaOrDungeonLightTxt(u32 archiveId, ModelAttributes *attributes);
void sub_020977CC(FieldSystem *fieldSystem, u8 param1, u8 param2, u32 mapId, u32 x, u32 y);
void sub_0203FC68(FieldSystem *fieldSystem, void *args);
void CallTask_LeaveOverworld(TaskManager *taskManager);
void sub_02055408(TaskManager *taskManager);
void sub_02097810(FieldSystem *fieldSystem, u8 param, void *destination);
BOOL sub_02097878(TaskManager *taskManager);
BOOL sub_020978D0(TaskManager *taskManager);

#endif
