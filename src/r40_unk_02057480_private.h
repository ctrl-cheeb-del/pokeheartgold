#ifndef SOL_R40_UNK_02057480_PRIVATE_H
#define SOL_R40_UNK_02057480_PRIVATE_H

#include "global.h"

typedef struct CommState57480 {
    u8 raw[0xF4];
} CommState57480;

typedef struct ObjectEvent57480 {
    u8 pad00[0x18];
    u16 x;
    u16 z;
    u8 pad1C[4];
} ObjectEvent57480;

extern CommState57480 *_021D41C4;
int Field_GetNumObjectEvents(void *fieldSystem);
ObjectEvent57480 *Field_GetObjectEvents(void *fieldSystem);
BOOL sub_02057480(int x, int z);

#endif
