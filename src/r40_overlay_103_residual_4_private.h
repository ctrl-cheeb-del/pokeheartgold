#ifndef R40_OV103_R4_PRIVATE_H
#define R40_OV103_R4_PRIVATE_H
#include "global.h"
typedef struct R40Ov103Work4 {
    u8 pad[0xC];
    u8 *ctx;
} R40Ov103Work4;
extern void *sub_0201956C(void *, u32, u32, u32);
extern void sub_020195F4(void *, u32, u32, u32, u32);
extern void sub_02019688(void *, u32, u32, u32, u32);
extern void *sub_02019B08(void *, u32);
extern void sub_020196E8(void *, u32, s32, s32);
void ov103_021ECD68(R40Ov103Work4 *);
#endif
