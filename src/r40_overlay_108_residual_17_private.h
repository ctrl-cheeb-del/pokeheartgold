#ifndef R40_OV108_R17_PRIVATE_H
#define R40_OV108_R17_PRIVATE_H
#include "global.h"
typedef struct R40Ov108ResObjList {
    void **objects;
    u32 count;
} R40Ov108ResObjList;
typedef struct R40Ov108Sub17 {
    u32 heapId;
    u8 pad004[8];
    u16 spriteCount;
    u8 pad00e[2];
    void *spriteList;
    u8 pad014[4];
    u8 renderer[0x12c];
    void *managers[4];
    R40Ov108ResObjList *lists[4];
} R40Ov108Sub17;
typedef struct R40Ov108Counts {
    u8 value[4];
} R40Ov108Counts;
extern const R40Ov108Counts ov108_021EA978;
void *G2dRenderer_Init(int, void *, int);
void *Create2DGfxResObjMan(int, int, int);
R40Ov108ResObjList *Create2DGfxResObjList(int, int);
void ov108_021E8758(R40Ov108Sub17 *);
void ov108_021E867C(R40Ov108Sub17 *);
#endif
