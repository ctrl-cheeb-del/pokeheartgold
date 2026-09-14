#ifndef POKEHEARTGOLD_TO47_OVERLAY14_BOX_SCAN_VIEW_PRIVATE_H
#define POKEHEARTGOLD_TO47_OVERLAY14_BOX_SCAN_VIEW_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov14BoxView {
    void *boxMon;
    u16 species;
    u16 field6;
    u32 field8;
    u8 fieldC;
    u8 fieldD;
    u8 fieldE;
    u8 nature;
    u16 field10;
    u8 field12 : 7;
    u8 field12Bit : 1;
    u8 gender : 7;
    u8 showGender : 1;
    u16 moves[4];
} Ov14BoxView;

void *Heap_Alloc(u32, u32);
u32 GetBoxMonData(void *, u32, void *);
u32 GetBoxMonNature(void *);
u8 GetBoxMonGender(void *);

void *ov14_021E60C0(void *p, u32 boxId, u32 idx);
s32 ov14_021E71C8(u16 v);

u32 ov14_021E7278(void *);
Ov14BoxView *ov14_021E7358(void *);

#endif
