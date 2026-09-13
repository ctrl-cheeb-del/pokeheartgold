#ifndef SOL_R40_FOLLOWUP_UNK0205704C_PRIVATE_H
#define SOL_R40_FOLLOWUP_UNK0205704C_PRIVATE_H
#include "global.h"
typedef struct Unk0205704CParams {
    u16 value0;
    u16 value1;
    s8 signed4;
    u8 value5;
    u8 pad6;
    u8 flag7;
} Unk0205704CParams;
void sub_02037108(int, const void *, int);
void sub_0205704C(int, const Unk0205704CParams *);
#endif
