#ifndef SOL40_OV49_RES69_PRIVATE_H
#define SOL40_OV49_RES69_PRIVATE_H
#include "global.h"
typedef struct Ov49Actor { u8 type; u8 pad1[3]; void *sub; void *object; } Ov49Actor;
extern u32 ov49_02258DAC(); extern u32 ov49_02258F70(); extern void sub_0200606C(); extern void PlaySE();
extern void Heap_Free(); extern void ov49_02258830(); extern void sub_020180F8();
extern void *ov49_02258E60(); extern u32 ov49_02265958(); extern u32 ov49_02266AF0(); extern void GF_AssertFail();
extern u32 (*ov49_0226A5A4[])(void *, Ov49Actor *); extern const u32 ov49_0226A610[]; extern u32 (*ov49_0226A538[])(void *, Ov49Actor *);
extern void *memset();
void ov49_02265948(void *, Ov49Actor *);
#endif
