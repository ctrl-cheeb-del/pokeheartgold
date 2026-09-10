#ifndef UNK_02087FD4_PRIVATE_H
#define UNK_02087FD4_PRIVATE_H

#include "global.h"

typedef struct SummaryTableEntry {
    void *value;
    u8 rest[0x20];
} SummaryTableEntry;

typedef struct SummaryTableWork {
    u8 pad000[0x6E0];
    s32 activeCount;
    u8 pad6E4[0x134];
    SummaryTableEntry *entries;
} SummaryTableWork;

extern void GF_AssertFail(void);
extern int sub_02087E1C(void *);
extern const u8 _02103754[];
extern const SummaryTableEntry _021037B8[];
extern const u8 _0210357C[];
extern const u8 _02102DC0[];

void *sub_02087FD4(int);
const void *sub_02087FF8(void *, int);
void sub_02088030(SummaryTableWork *);

#endif
