#ifndef SOL_R40_FOLLOWUP_UNK0202B614_PRIVATE_H
#define SOL_R40_FOLLOWUP_UNK0202B614_PRIVATE_H
#include "global.h"
typedef struct Unk0202BCACCoords {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
} Unk0202BCACCoords;
typedef struct Unk0202BCACRoot {
    void *owner;
    u8 pad04[0x38];
    u32 flags;
    u8 pad40[8];
    u32 entries[10];
} Unk0202BCACRoot;
typedef struct Unk0202BCACDesc {
    u32 id;
    void *object;
} Unk0202BCACDesc;
u32 sub_02015FCC(void *);
int sub_02015FF8(void *);
BOOL sub_0202B614(void *);
void sub_0202B770(u32 *, u8, u8, u8, u8);
void sub_0202BCAC(Unk0202BCACRoot *, const Unk0202BCACDesc *, int);
#endif
