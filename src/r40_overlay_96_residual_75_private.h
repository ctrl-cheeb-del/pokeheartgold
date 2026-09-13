#ifndef OV96_RESIDUAL75_PRIVATE_H
#define OV96_RESIDUAL75_PRIVATE_H

#include "global.h"

typedef struct Ov96R75Template {
    void *spriteList;
    void *header;
    s32 x;
    s32 y;
    s32 z;
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    u16 rotation;
    u16 pad22;
    u32 affine;
    u32 priority;
    u32 heapId;
} Ov96R75Template;

typedef struct Ov96R75Entry {
    u32 unk00;
    void *handle;
} Ov96R75Entry;

typedef struct Ov96R75Row {
    Ov96R75Entry entries[5];
    u32 pad28;
} Ov96R75Row;

typedef struct Ov96R75Work {
    u32 heapId;
    void *spriteList;
    u8 renderer[0x128];
    void *managers[6];
    void *resources[4];
    u8 header[0x30];
} Ov96R75Work;

void ov96_021FC404(u8 *work);
void ov96_021FC320(Ov96R75Work *work);
void ov96_021FC5E0(Ov96R75Template *out, u8 *work, void *unused, u32 priority);
void *ov96_021FC618(u32 heapId);
void ov96_021FC630(Ov96R75Row *out, void *a1, int a2);

#endif
