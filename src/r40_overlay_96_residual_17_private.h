#ifndef OV96_R17_PRIVATE_H
#define OV96_R17_PRIVATE_H

#include "global.h"

typedef struct Ov96R17Record {
    u8 pad_00[0x10];
    void *string34;
    void *string38;
} Ov96R17Record;

typedef struct Ov96R17Work {
    s32 count;
    u32 unk_04;
    s32 next;
    u32 unk_0C;
    u32 unk_10;
    u8 pad_14[0x24 - 0x14];
    Ov96R17Record records[12];
    void *ordered[12];
    u8 pad_174[0x214 - 0x174];
} Ov96R17Work;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void MI_CpuFill8(void *ptr, u8 value, u32 size);
void *String_New(u32 size, u32 heapId);
void String_Delete(void *string);
void GF_AssertFail(void);

#endif
