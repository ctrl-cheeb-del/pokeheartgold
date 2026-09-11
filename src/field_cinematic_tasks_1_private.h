#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct TaskManager TaskManager;
extern void *Heap_AllocAtEnd(int,int); extern void Heap_Free(void *); extern int Field_GetTimeOfDay(void *); extern void GF_AssertFail(void);
extern void TaskManager_Call(TaskManager *, BOOL (*)(TaskManager *), void *); extern void *TaskManager_GetFieldSystem(TaskManager *); extern void *TaskManager_GetEnvironment(TaskManager *);
extern void CallTask_LeaveOverworld(TaskManager *); extern void CallTask_RestoreOverworld(TaskManager *);
extern void *LegendaryCinematic_LaunchApp(void *,void *,int,int,int); extern BOOL FieldSystem_ApplicationIsRunning(void *);
void sub_02097BE0(void *,u16); BOOL sub_02097C50(TaskManager *); void sub_02097CB4(void *,void *); BOOL sub_02097CD8(TaskManager *);
#endif
