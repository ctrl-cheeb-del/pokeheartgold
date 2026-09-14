#ifndef OV80_FD08_PARTY_BUILD_INTERNAL_H
#define OV80_FD08_PARTY_BUILD_INTERNAL_H

#include "global.h"

typedef struct Ov80PartyRecord {
    u32 raw[14];
} Ov80PartyRecord;

typedef struct Ov80PartyBuildWork {
    u8 pad_000[0x3D2];
    u16 secondIds[6];
    u8 pad_3DE[0x10A];
    u16 firstIds[6];
} Ov80PartyBuildWork;

void ov80_02236DD4(u8);
u32 sub_02030A24(void *, int, u8, int);
void ov80_0222A52C(Ov80PartyRecord *, u16 *, u8 *, u32 *, int, int, int, int);
void *AllocMonZeroed(int);
void Heap_Free(void *);
int ov80_02237120(void *);
void ov80_0222A140(Ov80PartyRecord *, void *, int);
void ov80_0222A3BC(void *, void *, void *);
void ov80_02230270(void *);

#endif
