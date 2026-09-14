#ifndef OV96_R43_R2_PRIVATE_H
#define OV96_R43_R2_PRIVATE_H

#include "global.h"

typedef int (*MATHQSortComparator)(const void *, const void *);

typedef struct Ov96RankEntry {
    u32 count : 16;
    u32 uses : 8;
    u32 filler : 4;
    u32 rank : 4;
} Ov96RankEntry;

typedef struct Ov96ResultA {
    u8 pad00[0x20];
    u8 participant;
    u8 flag : 1;
    u8 all : 1;
    u8 filler21 : 6;
} Ov96ResultA;

typedef struct Ov96ResultB {
    u8 pad00[8];
    u32 filler08 : 28;
    u32 flag : 1;
    u32 all : 1;
    u32 filler30 : 2;
    u8 participant;
} Ov96ResultB;

void MATH_QSort(void *, u32, u32, MATHQSortComparator, void *);
int ov96_021ECC58(const void *, const void *);
void *PokeathlonCourse_GetHeapAllocPtr4(void *);
u8 *PokeathlonCourse_GetDataCopyArea(void *);
u8 *ov96_021E8A20(void *);
u32 ov96_021E5F24(void *);
s32 PokeathlonCourse_GetParticipantCount(void *);
u8 ov96_021EEA80(void *);

void ov96_021EE290(Ov96RankEntry *);
BOOL ov96_021EE324(void *);
BOOL ov96_021EE440(void *);

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

#endif
