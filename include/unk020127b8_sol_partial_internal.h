#ifndef POKEHEARTGOLD_SCRATCH_UNK_020127B8_H
#define POKEHEARTGOLD_SCRATCH_UNK_020127B8_H

#include "global.h"

typedef struct AllocationList {
    void *allocation;
    int count;
} AllocationList;

typedef struct Interpolation {
    int value;
    int start;
    int delta;
} Interpolation;

typedef struct FadeTask {
    u8 unk00[4];
    s32 unk04;
    s32 unk08;
    u32 state;
    u32 unk10;
    u8 *allocation;
    u32 unk18;
    u32 unk1C;
    u32 heapId;
} FadeTask;

typedef struct FadeParam8 {
    const void *unk0;
    u16 unk4;
    u16 unk6;
} FadeParam8;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void GF_AssertFail(void);
void sub_02010F34(u32, u32, u32);
void sub_02011080(void *, u32, u32, u32);
void sub_020110DC(void *, u8 *, u32);
void sub_020110F4(void *, u8 *, u32);
void sub_02011068(void *, int, int, int);
void sub_02010F84(void *, int, int, int, u32, int, int, int, int, int);
void sub_02012A90(void *);
void *sub_02010EE0(AllocationList *, int);
int sub_020109D8(int, int);
void sub_02012A8C(void *);
void *sub_020110C4(void *);

void sub_020127B8(AllocationList *list);
void sub_02012884(Interpolation *interp, int numerator, int denominator);
void sub_0201289C(FadeTask *work, const void *param);
BOOL sub_020128E0(FadeTask *work);
void sub_02012940(u8 *dst, const FadeParam8 *param, int a2, int a3, u32 a4, u32 a5, u32 a6, u32 heapId);
BOOL sub_02012A2C(u8 *work);

#endif
