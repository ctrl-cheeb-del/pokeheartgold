#ifndef OVERLAY96_SPRITE_RESOURCE_LOAD_R14_PRIVATE_H
#define OVERLAY96_SPRITE_RESOURCE_LOAD_R14_PRIVATE_H

#include "global.h"

#include "sprite.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void MI_CpuCopy8(const void *src, void *dst, u32 size);
void Heap_Free(void *ptr);
int ov96_021E91B8(u16 a, u16 b, u8 c);
void *SpriteTransfer_GetCharProxy(void *resource);
void *SpriteTransfer_GetPaletteProxy(void *resource, void *charProxy);
void DC_FlushRange(const void *src, u32 size);
void GX_LoadOBJPltt(const void *src, u32 dst, u32 size);
void GXS_LoadOBJPltt(const void *src, u32 dst, u32 size);
void SysTask_Destroy(void *task);
BOOL ov96_021E8FE0(void *work);
void GF_AssertFail(void);

void ov96_021E8BB4(u8 *desc, int heapId, void *dst);
void ov96_021E8BF4(u8 *gfx, int index, int screen, void *palette);
void ov96_021E8EE4(u8 *gfx, int priority, int transfer, NNS_G2D_VRAM_TYPE whichScreen, u8 resourceId, u8 index);
void ov96_021E8FB4(void *task, u8 *work);

#endif
