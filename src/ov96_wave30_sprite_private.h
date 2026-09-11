#ifndef R23_H
#define R23_H
#include "global.h"
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
void GF_AssertFail(void);void ManagedSprite_SetAnim(void *,int);void ManagedSprite_SetPositionXY(void *,s16,s16);void ManagedSprite_SetDrawFlag(void *,int);void Sprite_DeleteAndFreeResources(void *);void Heap_Free(void *);void ManagedSprite_GetPositionXY(void *,s16 *,s16 *);void ov96_0220AFF8(void *);void ov96_0220B068(u8 *);void ov96_0220B148(void *,s16 *,s16 *);
void ov96_0220AED4(u8 *);void ov96_0220AF30(u8 *);void ov96_0220B068(u8 *);
void *Heap_Alloc(u32,u32);void MI_CpuFill8(void *,u8,u32);void *ov96_0220D13C(void *,void *,s32,s32,s32,u16);void ManagedSprite_SetAnimateFlag(void *,int);void *ov96_0220AE40(u32,void *,void *,u32);
#endif
