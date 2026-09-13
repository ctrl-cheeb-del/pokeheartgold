#ifndef R40_OV103_R13_PRIVATE_H
#define R40_OV103_R13_PRIVATE_H
#include "global.h"
typedef struct R40Cfg13 {
    u8 bit0 : 1;
    u8 bits1 : 7;
    u8 lo : 4;
    u8 hi : 4;
    u8 zero2, zero3;
    s8 y, x;
    u8 h, w;
} R40Cfg13;
typedef struct R40Ov103Work13 {
    u8 pad00[0xC];
    u8 *ctx;
    u8 pad10[0x18];
    u32 out28;
} R40Ov103Work13;
extern void sub_02019B1C(void *, u32, s8 *, s8 *);
extern void sub_02019B44(void *, u32, u16 *, u16 *);
u32 ov103_021EDA98(R40Ov103Work13 *, u32, u32);
#endif
