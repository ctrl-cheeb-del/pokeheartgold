#ifndef OVERLAY_40_RESIDUAL_17_PRIVATE_H
#define OVERLAY_40_RESIDUAL_17_PRIVATE_H

#include "global.h"

#define PTRAT(p, n) (*(void **)((u8 *)(p) + (n)))
#define U32AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))

void ov40_0222FB40(void *p);
void ov40_0222FB74(void *task, void *data);
void *ov40_0222FB90(void *p, void *value);

extern void sub_0202FBF0(void *, u32, void *);
extern void sub_02030814(void *, void *, void *, u32, void *);
extern void ov40_0222BC44(void *);
extern void sub_0203A86C(void);
extern void SysTask_Destroy(void *);
extern void *SysTask_CreateOnVBlankQueue(void (*)(void *, void *), void *, u32);

#endif
