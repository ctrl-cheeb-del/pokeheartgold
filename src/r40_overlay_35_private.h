#ifndef SOL_R40_FOLLOWUP_OV35_PRIVATE_H
#define SOL_R40_FOLLOWUP_OV35_PRIVATE_H
#include "global.h"
typedef void (*Ov35Callback)(void *);
typedef struct Ov35State {
    u8 pad00[2];
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 pad05[0x3f];
    Ov35Callback callback;
    void *callbackArg;
} Ov35State;
void ov35_02259D80(Ov35State *, u32);
u8 ov35_02259DB8(Ov35State *);
#endif
