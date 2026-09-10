#ifndef POKEHEARTGOLD_FIELD_OVERWORLD_TRANSITION_INTERNAL_H
#define POKEHEARTGOLD_FIELD_OVERWORLD_TRANSITION_INTERNAL_H
#include "global.h"

typedef BOOL (*FieldTaskFunc)(void *);

extern void *TaskManager_GetFieldSystem(void *taskManager);
extern u32 *TaskManager_GetStatePtr(void *taskManager);
extern void TaskManager_Call(void *taskManager, FieldTaskFunc function, void *environment);
extern BOOL sub_0203DF7C(void *fieldSystem);
extern void sub_0203DF34(void *fieldSystem);
extern BOOL sub_020505C8(void *fieldSystem);
extern void FieldSystem_LoadFieldOverlay(void *fieldSystem);
extern void FieldSystem_DrawMapNameAnimation(void *fieldSystem);
extern BOOL IsPaletteFadeFinished(void);
extern void BeginNormalPaletteFade(u32 mask, u32 delay, u32 start, u32 end, u32 color, u32 speed, u32 frames);
extern void GF_AssertFail(void);

BOOL sub_02055244(void *taskManager);
void CallTask_LeaveOverworld(void *taskManager);
BOOL sub_0205528C(void *taskManager);
void CallTask_RestoreOverworld(void *taskManager);
BOOL sub_020552D4(void *taskManager);
void PaletteFadeUntilFinished(void *taskManager);
void CallTask_FadeFromBlack(void *taskManager);
BOOL sub_02055370(void *taskManager);
void sub_020553B0(void *taskManager);
BOOL sub_020553C0(void *taskManager);
void sub_02055408(void *taskManager);

BOOL sub_02055244(void *taskManager);
void CallTask_LeaveOverworld(void *taskManager);
BOOL sub_0205528C(void *taskManager);
void CallTask_RestoreOverworld(void *taskManager);
BOOL sub_020552D4(void *taskManager);
void PaletteFadeUntilFinished(void *taskManager);
void CallTask_FadeFromBlack(void *taskManager);
BOOL sub_02055370(void *taskManager);
void sub_020553B0(void *taskManager);
BOOL sub_020553C0(void *taskManager);
void sub_02055408(void *taskManager);

#endif
