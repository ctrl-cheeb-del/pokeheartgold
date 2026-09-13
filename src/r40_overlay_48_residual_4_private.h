#ifndef OVERLAY_48_RESIDUAL_4_PRIVATE_H
#define OVERLAY_48_RESIDUAL_4_PRIVATE_H

#include "global.h"

#include "system.h"

#define PTRAT(p, n) (*(void **)((u8 *)(p) + (n)))
#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))

void ov48_02259650(void *p);
void ov48_02259688(void *p, u32 heapId);

extern u32 ov48_0225B1B0[5];
extern u8 ov48_0225B1A0[];
extern void FreeBgTilemapBuffer(void *, u8);
extern void Heap_Free(void *);
extern void GfGfx_SwapDisplay(void);
extern void NNS_G2dInitOamManagerModule(void);
extern void OamManager_Create(u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void ObjCharTransfer_InitEx(void *, u32, u32);
extern void ObjPlttTransfer_Init(u32, u32);
extern void ObjCharTransfer_ClearBuffers(void);
extern void ObjPlttTransfer_Reset(void);
extern void G2dRenderer_SetObjCharTransferReservedRegion(u32, u32);
extern void G2dRenderer_SetPlttTransferReservedRegion(u32);
extern void *G2dRenderer_Init(u32, void *, u32);
extern void G2dRenderer_SetSubSurfaceCoords(void *, u32, u32);
extern void *Create2DGfxResObjMan(u32, u32, u32);
extern void sub_0203A880(void);
extern void GfGfx_EngineATogglePlanes(u32, u32);
extern void GfGfx_EngineBTogglePlanes(u32, u32);

#endif
