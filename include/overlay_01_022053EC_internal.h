#ifndef PRIVATE_OVERLAY_01_022053EC_H
#define PRIVATE_OVERLAY_01_022053EC_H
#include "global.h"

typedef struct Overlay01AngleTable {
    u32 values[3][16];
} Overlay01AngleTable;

extern const Overlay01AngleTable ov01_02209750;

u8 ov01_02205584(void *obj);
u32 sub_020659A8(void *obj);
s32 sub_0206599C(void *obj);
void GF_AssertFail(void);

u32 ov01_022054E0(void *obj);
#endif
