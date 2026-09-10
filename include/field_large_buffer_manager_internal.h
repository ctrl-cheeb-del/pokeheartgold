#include "global.h"

typedef struct OverlayBuffersPrivate {
    void *primary[4];
    void *secondary[4];
} OverlayBuffersPrivate;

extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void MI_CpuFill8(void *, u8, u32);
extern u8 ov01_02209B70[];

OverlayBuffersPrivate *ov01_021FAC44(BOOL);
void ov01_021FACB4(OverlayBuffersPrivate *);
void ov01_021FACE4(u32, OverlayBuffersPrivate *, void **);
void ov01_021FACEC(u32, OverlayBuffersPrivate *, void **);
void ov01_021FACF8(u32, u32, u32, OverlayBuffersPrivate *);
