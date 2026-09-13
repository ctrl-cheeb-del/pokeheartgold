#ifndef OVERLAY_48_RESIDUAL_25_PRIVATE_H
#define OVERLAY_48_RESIDUAL_25_PRIVATE_H

#include "global.h"

#define U8AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define PTRAT(p, n) (*(void **)((u8 *)(p) + (n)))
#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))

typedef struct Ov48SmallState {
    u8 padding00[0x30];
    u16 unk30;
    u16 unk32;
    u8 active[4];
    u8 kind[4];
} Ov48SmallState;

void ov48_0225AA5C(void *p, u32 y, void *context);
void ov48_0225AAAC(void *p, void *managers, void *position, u32 heapId);
void ov48_0225AC34(void *p, void *managers);
void ov48_0225ACAC(void *p);
void ov48_0225ACD8(void *p, u32 index, u32 value, u32 other);

extern void StopSE(u32, u32);
extern void CopyToBgTilemapRect(void *, u8, u8, u8, u8, u8, const void *, u8, u8, u32, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u8);
extern void Sprite_Delete(void *);
extern void SpriteTransfer_DeleteCharTransferTask(void *);
extern void SpriteTransfer_DeletePlttTransferTask(void *);
extern void DestroySingle2DGfxResObj(void *, void *);
extern u8 ov48_0225B050(u32);
extern void ov48_0225AE3C(void *, void *);
extern void ov48_0225AE5C(void *, u16);
extern void ov48_0225AE58(void *, u16);
extern u8 ov48_0225B330[];

#endif
