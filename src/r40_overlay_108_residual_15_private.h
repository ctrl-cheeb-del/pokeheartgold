#ifndef R40_OV108_R15_PRIVATE_H
#define R40_OV108_R15_PRIVATE_H
#include "global.h"
typedef struct R40Ov108ResObjList {
    void **objects;
    u32 count;
} R40Ov108ResObjList;
typedef struct R40Ov108Sub15 {
    u32 heapId;
    u8 pad004[0x144 - 4];
    void *managers[4];
    R40Ov108ResObjList *lists[4];
} R40Ov108Sub15;
void ReplaceCharResObjFromNarc(void *, void *, int, int, int, int);
void SpriteTransfer_ReplaceCharData(void *);
void ov108_021E84F8(R40Ov108Sub15 *, int, int);
#endif
