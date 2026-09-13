#ifndef OV96_R40_RESIDUAL110_PRIVATE_H
#define OV96_R40_RESIDUAL110_PRIVATE_H

#include "global.h"

#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef struct Ov96R110Group {
    u32 unk0;
    void *order0;
    u32 unk8;
    void *order1;
    u32 unk10;
    void *order2;
    void *entries[3];
} Ov96R110Group;

void Sprite_SetDrawFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void ov96_021EB52C(void *, int, int);
void ov96_02214854(void *);
void CopyRectToBgTilemapRect(void *, u32, u32, u32, u32, u32, void *, u32, u32, u32, u32);
void ScheduleBgTilemapBufferTransfer(void *, u32);
void *Heap_Alloc(u32, u32);
void MI_CpuFill8(void *, u8, u32);

void ov96_0221490C(void *, s32);
void ov96_0221497C(void *, s32);
void *ov96_02214A24(u32, u8);
void ov96_02214A6C(Ov96R110Group *, s32, void *);
void ov96_02214A9C(Ov96R110Group *);
void ov96_02214ABC(Ov96R110Group *);

#endif
