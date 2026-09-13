#ifndef OVERLAY_45_THUMB_RESIDUAL_17_R40_PRIVATE_H
#define OVERLAY_45_THUMB_RESIDUAL_17_R40_PRIVATE_H
#include "global.h"
void *PlayerProfile_New(u32 heapId);
void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
void ov45_0222A844(void *work, void *profile, u32 heapId);
void ov45_0222BCC8(void **slot, u32 heapId);
void ov45_0222BCD8(void **slot);
void ov45_0222BCE4(void **slot, void *src, u32 heapId);
#endif
