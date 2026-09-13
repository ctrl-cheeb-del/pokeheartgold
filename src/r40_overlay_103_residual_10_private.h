#ifndef R40_OV103_R10_PRIVATE_H
#define R40_OV103_R10_PRIVATE_H
#include "global.h"

#include "system.h"
typedef struct R40Ov103Work {
    u8 pad00[0xC];
    u8 *ctx;
    u8 pad10[0xC];
    u16 row;
    u8 col;
    u8 value;
} R40Ov103Work;
extern u32 ov103_021EEA24(void *);
extern u32 ov103_021EDB18(void *, u32, u32);
extern u32 ov103_021EDA98(void *, u32, u32);
extern int GridInputHandler_HandleInput_NoHold(void *);
extern int GridInputHandler_GetNextInput(void *);
extern void PlaySE(u16);
u32 ov103_021ED5B4(R40Ov103Work *work);
#endif
