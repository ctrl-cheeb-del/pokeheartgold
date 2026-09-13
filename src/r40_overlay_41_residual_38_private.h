#ifndef R40_OV41_R38_H
#define R40_OV41_R38_H
#include "global.h"
typedef struct Ov41Ref {
    u8 *base;
    u32 x;
    u32 index;
} Ov41Ref;
typedef struct Ov41Ctx {
    u32 selected;
    u32 pad4;
    u32 pad8;
    Ov41Ref refs[1];
} Ov41Ctx;
void Heap_Free(void *);
void ov41_02248A6C(u8 *);
void *ov41_02248A94(Ov41Ctx *);
void *ov41_02248ABC(Ov41Ctx *, int, int);
#endif
