#ifndef SOL_R40_UNK_0207527C_PRIVATE_H
#define SOL_R40_UNK_0207527C_PRIVATE_H

#include "global.h"

typedef struct LinkWork7527C {
    void *setup;
    u8 pad04[0xC];
    void *friends[4];
    u8 buffer[0x1000];
} LinkWork7527C;

int sub_02037190(void);
int sub_0203769C(void);
void sub_02075554(void *profile, void *friends, void *out);
void *Heap_Alloc(u32 heapId, u32 size);
BOOL sub_0207527C(LinkWork7527C *work);

#endif
