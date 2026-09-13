#ifndef SOL_R40_FOLLOWUP_UNK02011130R2_PRIVATE_H
#define SOL_R40_FOLLOWUP_UNK02011130R2_PRIVATE_H
#include "global.h"
typedef struct Unk020117A0Config {
    u8 a0;
    u8 a1;
    u8 a2;
    u8 a3;
    u8 data4[4];
    u8 a8;
    u8 a9;
    u8 aA;
    u8 aB;
} Unk020117A0Config;
typedef struct Unk020117A0Dest {
    u8 data00[0x10];
    u8 data10[0x10];
    u8 data20[0x10];
    u32 field30;
    u32 field34;
    u32 field38;
    u32 field3C;
    u32 field40;
    u32 field44;
    u32 field48;
} Unk020117A0Dest;
void sub_02010AB0(Unk020117A0Dest *, void *, void *, const Unk020117A0Config *, const void *, u32);
void sub_02010F84(u32, u8, u8, u8, u32, u8, u8, u8, u8, u32);
void sub_020117A0(Unk020117A0Dest *, const Unk020117A0Config *, u32, u32, u32, u32);
#endif
