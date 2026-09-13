#ifndef SOL_R40_NIGHT_OVERLAY71_RESIDUAL17_PRIVATE_H
#define SOL_R40_NIGHT_OVERLAY71_RESIDUAL17_PRIVATE_H
#include "global.h"
void *Heap_Alloc(int, u32);
void Heap_Free(void *);
void *ov71_02247384(void *);
u32 MTRandom(void);
void *SysTask_CreateOnVWaitQueue(void (*)(void *, void *), void *, u32);
void ov71_02248B60(void *, void *);
void ov71_0224889C(void *);
void ov71_022489F8(void *);
void ov71_02248B24(void *);
void SysTask_Destroy(void *);
void ov71_02248E04(void *);
void SetMTRNGSeed(u32);
void *ov71_022482EC(void *);
void ov71_02248358(void *);
void PlaySE(int);
void ov71_022476EC(void *, void *);
void ov71_022476C4(void *, void *);
void ov71_022481EC(void *);
void ov71_0224820C(void *, void *);
#endif
