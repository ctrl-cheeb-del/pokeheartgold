#ifndef R22_H
#define R22_H
#include "global.h"
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
void GF_AssertFail(void); void ManagedSprite_GetPositionXY(void *,void *,void *); void Sprite_DeleteAndFreeResources(void *); void ManagedSprite_SetDrawFlag(void *,int); void ManagedSprite_SetAnimateFlag(void *,int); void Heap_Free(void *); BOOL ov96_0220B2D4(void *); void ov96_0220C578(void *,int);
void ov96_0220AE28(u8 *); void ov96_0220B148(void *,void *,void *); u8 ov96_0220B164(u8 *); void ov96_0220B1B8(u8 *); void ov96_0220B324(u8 *); void ov96_0220B354(u8 *); void ov96_0220B500(u8 *); void ov96_0220B6EC(u8 *); void ov96_0220B708(u8 *,int);
#endif
