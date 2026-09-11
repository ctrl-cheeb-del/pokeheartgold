#ifndef SOL40_OV49_RES41_PRIVATE_H
#define SOL40_OV49_RES41_PRIVATE_H
#include "global.h"
typedef struct VecS16Sol {
    s16 x, y, z;
} VecS16Sol;
typedef struct Ov49DState {
    u16 unk0;
    u16 index;
    u8 object[0x78];
    u8 slots[3][0x14];
    u8 active[3];
    u8 padBB;
    u8 type[3];
    u8 padBF;
    u32 resource[3];
    u8 modulus;
    u8 random[3];
    u32 value[3];
} Ov49DState;
typedef struct Ov49DParent {
    u8 pad[0x3bc];
    void *available[18][3];
} Ov49DParent;
extern void ov49_02258800();
extern void ov49_02258814();
extern void sub_020182A8();
extern void sub_020182B0();
extern void sub_020181D4();
extern void sub_020181E0();
extern u32 sub_020181A4();
extern void sub_02018198();
extern u32 MTRandom();
extern u32 _u32_div_f();
extern void GF_AssertFail();
#endif
