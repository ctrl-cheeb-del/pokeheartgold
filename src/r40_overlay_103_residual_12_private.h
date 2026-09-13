#ifndef R40_OV103_R12_PRIVATE_H
#define R40_OV103_R12_PRIVATE_H
#include "global.h"
typedef struct R40Ov103Work12 {
    u8 pad00[0x18];
    u32 state18;
    u8 pad1c[5];
    u8 flags21_low : 7;
    u8 flags21_high : 1;
    u16 value22;
    u32 ptr24;
    u32 next28;
} R40Ov103Work12;
extern void ov103_021EDC68(R40Ov103Work12 *, u32, u16, u8);
u32 ov103_021ED9AC(R40Ov103Work12 *);
#endif
