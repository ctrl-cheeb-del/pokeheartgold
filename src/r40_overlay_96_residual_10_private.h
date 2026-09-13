#ifndef OV96_R40_RESIDUAL10_PRIVATE_H
#define OV96_R40_RESIDUAL10_PRIVATE_H
#include "global.h"
typedef struct Ov96R10Dispatch {
    u16 mode;
    u16 check;
    void *data;
} Ov96R10Dispatch;
void GF_AssertFail(void);
void sub_02037030(void *, void *, s32);
void ov96_021E8914(void *, void *, void *, s32);
void sub_02036FD8(void *, void *, void *);
void ov96_021E8988(void *, void *, void *, void *);
void ov96_021E88FC(void *);
void Heap_Free(void *);
void ov96_021E87B4(void *, void *, s32, Ov96R10Dispatch *);
void ov96_021E87EC(void *, void *, void *, Ov96R10Dispatch *);
void ov96_021E8810(Ov96R10Dispatch *);
#endif
