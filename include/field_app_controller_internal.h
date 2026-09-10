#ifndef PRIVATE_UNK_02078834_H
#define PRIVATE_UNK_02078834_H
#include "global.h"

#include "filesystem.h"
typedef struct LocalTaskData {
    u8 *appArgs;
    u32 state;
    u16 *result;
    u8 percent;
    u8 mode;
    u8 pad0E[2];
    void *launchedArgs;
    u32 selection;
} LocalTaskData;
void *TaskManager_GetFieldSystem(void *);
void *TaskManager_GetEnvironment(void *);
void TaskManager_Call(void *, BOOL (*)(void *), void *);
void CallApplicationAsTask(void *, const void *, void *);
BOOL sub_0203A05C(void *);
void *Save_VarsFlags_Get(void *);
void SetFlag970(void *);
void CallTask_02050960(void *, u32, u8, u8);
void CallTask_WirelessTrade(void *);
void LoadOVY13(void);
void ov13_0221BA00(int);
void sub_020378E4(int);
void *sub_020968B0(void *, int);
void FieldSystem_LaunchApplication(void *, const void *, void *);
void HandleLoadOverlay(int, int);
void UnloadOverlayByID(int);
BOOL FieldSystem_ApplicationIsRunning(void *);
void *sub_020398C8(void);
void ov91_0225C540(void);
void ov91_0225C58C(void);
void ov91_0225C9EC(void);
void ov92_0225CAB4(void);
void ov92_0225CDF4(void);
void ov92_0225D36C(void);
void ov44_02232EA8(void);
void ov44_02232F64(void);
void ov44_022330A8(void);
void ov44_0222A4B4(void);
void ov44_0222A60C(void);
void ov44_0222A758(void);
void ov93_0225C540(void);
void ov93_0225C574(void);
void ov93_0225C6C0(void);
BOOL sub_02078834(void *);
LocalTaskData *sub_02078B2C(void);
void sub_02078B58(void *);
void sub_02078B78(void *, u16 *);
void sub_02078B9C(LocalTaskData *, void *, int, int);
u32 sub_02078BD8(LocalTaskData *);
void *sub_02078C18(void *, int, u32);
void sub_02078C60(void *);
void *sub_02078C74(void *, int, u32);
void sub_02078CB4(void *);
void *sub_02078CC8(void *, int, u32);
void sub_02078D10(void *);
BOOL sub_02078D24(int);
#endif
