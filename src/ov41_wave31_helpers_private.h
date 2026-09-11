#ifndef SOL40_R32_PRIVATE_H
#define SOL40_R32_PRIVATE_H
#include "global.h"
#include <string.h>
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
void GF_AssertFail(void); void ScheduleSetBgPosText(void *,u8,int,int); void ov41_02249C7C(void *,void *); void DestroySysTaskAndEnvironment(void *); void BG_LoadCharTilesData(void *,u8,void *,u32,u32); void SysTask_Destroy(void *); void Heap_Free(void *); void *Sprite_CreateAffine(void *); extern void ov41_0224A254(void);
void ov41_02249E40(void *,int); void ov41_02249F0C(void *,void *); void ov41_0224A094(void *,void *); void ov41_0224A0D0(void *,void *); void ov41_0224A118(void *,void *); void *sub_020135D8(void *); void ov41_0224A15C(void *,void *); void *GfGfxLoader_GetScrnData(void *,int,int,void *,u32); void ov41_02249F7C(void *,int,void *,int,int,int,int,int,int); void ov41_02249D60(void *);
void *Heap_Alloc(int, u32); void *GfGfxLoader_GetPlttData(int, int, void *, int); void *SysTask_CreateOnVWaitQueue(void (*)(void *, void *), void *, u32); void ov41_0224A04C(int, int, int, int, int, int);
#endif
