#include "field_cinematic_tasks_1_private.h"
#include <string.h>
typedef struct Block { u32 x[18]; } Block;
typedef struct EnvA { Block copy; u32 scene; u32 tod; u32 state; } EnvA;
typedef struct EnvB { EnvA *a; void *app; u32 state; } EnvB;

void sub_02097BE0(void *field,u16 scene) {
 u8 *f=field; EnvA *e=Heap_AllocAtEnd(11,sizeof(EnvA)); e->copy=**(Block **)(f+0x48); e->scene=scene; e->state=0;
 switch(Field_GetTimeOfDay(field)) { case 0: case 1:e->tod=0;break; case 2:e->tod=1;break; case 3:case 4:e->tod=2;break; default:GF_AssertFail();e->tod=1;break; }
 TaskManager_Call(*(TaskManager **)(f+0x10),sub_02097C50,e);
}

BOOL sub_02097C50(TaskManager *task) {
 void *field=TaskManager_GetFieldSystem(task); EnvA *e=TaskManager_GetEnvironment(task);
 switch(e->state) { case 0:CallTask_LeaveOverworld(task);e->state++;break; case 1:sub_02097CB4(field,e);e->state++;break; case 2:CallTask_RestoreOverworld(task);e->state++;break; case 3:Heap_Free(e);return TRUE; }
 return FALSE;
}

void sub_02097CB4(void *field,void *arg) { u8 *f=field; EnvB *e=Heap_AllocAtEnd(11,sizeof(EnvB));e->a=arg;e->state=0;TaskManager_Call(*(TaskManager **)(f+0x10),sub_02097CD8,e); }

BOOL sub_02097CD8(TaskManager *task) {
 u8 *field=TaskManager_GetFieldSystem(task); EnvB *e=TaskManager_GetEnvironment(task); EnvA *a=e->a;
 switch(e->state) { case 0:e->app=LegendaryCinematic_LaunchApp(field,&a->copy,a->scene,a->tod,11);e->state++;break; case 1:if(!FieldSystem_ApplicationIsRunning(field))e->state++;break; case 2:Heap_Free(e->app);Heap_Free(e);return TRUE; }
 return FALSE;
}
