#ifndef OV80_022310C4_PRIVATE_H
#define OV80_022310C4_PRIVATE_H

#include "global.h"

#include "heap.h"

// 0xD98-byte trainer-house / frontier run state. Pointed to by ov80_0223DD44.
typedef struct TrHouse {
    u32 heapId;                      // 0x000
    u8 kind;                         // 0x004
    u8 idx;                          // 0x005
    u8 unk6;                         // 0x006
    u8 unk7;                         // 0x007
    u16 unk8;                        // 0x008
    u16 unkA;                        // 0x00A
    u32 unkC;                        // 0x00C
    u32 unk10;                       // 0x010
    u8 pad14[0x018 - 0x014];         // 0x014
    u16 unk18[0x14];                 // 0x018
    u8 pad40[0x260 - 0x040];         // 0x040
    u8 unk260[4];                    // 0x260
    void *party;                     // 0x264
    u16 unk268[0x14];                // 0x268
    u8 pad290[0x6F2 - 0x290];        // 0x290
    u16 unk6F2;                      // 0x6F2
    u8 unk6F4;                       // 0x6F4
    u8 unk6F5;                       // 0x6F5
    u8 pad6F6[2];                    // 0x6F6
    void *unk6F8;                    // 0x6F8
    void *save;                      // 0x6FC
    u8 pad700[4];                    // 0x700
    u8 unk704[4][9];                 // 0x704
    u16 unk728[(0xD8C - 0x728) / 2]; // 0x728
    void *unkD8C;                    // 0xD8C
    u8 padD90[0xD98 - 0xD90];        // 0xD90
} TrHouse;

typedef struct TrHouseSrc {
    u8 pad0[6]; // 0x00
    u16 unk6;   // 0x06
} TrHouseSrc;

typedef struct TrHouseWork {
    u32 unk0;             // 0x00
    u16 unk4;             // 0x04
    u16 unk6;             // 0x06
    u8 pad8[0x30 - 0x08]; // 0x08
} TrHouseWork;

extern const u8 ov80_0223BDFC[];
extern const u8 ov80_0223BE10[];

void *Save_Frontier_GetStatic(void *save);
u32 FrontierSave_GetStat(void *frontier, u32 stat, u32 substat);

u32 sub_02030BD0(u8 index, u8 *bits);
void sub_02030BF4(u8 index, u8 *bits, u32 value);
void sub_02030C34(u8 *bits);
u32 sub_0205C0A0(u32 a, u32 b);
u32 sub_0205C268(u32 a);

void *ov80_02229F04(TrHouseWork *work, u32 a, u32 heapId, u32 c);
void ov80_0222A30C(u8 a);
void ov80_0222AF10(void *a);
void ov80_0222AF54(void *a);
void ov80_0222AFB8(void *a);
void ov80_0222B024(void *a, u8 b);
void ov80_0222B070(void *a);
u8 ov80_02237920(u8 a);
u32 ov80_022379C8(TrHouse *s);
u32 ov80_02237A40(u32 a);

void ov80_022313C0(TrHouse *s);
void ov80_022313C8(TrHouse *s);
void ov80_022314A0(TrHouse *s);
void ov80_022314DC(TrHouse *s, TrHouseSrc *src);
u16 ov80_02231518(TrHouseSrc *src, u32 unused);
void ov80_0223157C(TrHouse *s, u32 mode);
u8 ov80_022317C0(TrHouse *s);
u8 ov80_022317CC(TrHouse *s);
void ov80_022317D0(TrHouse *s, u32 a);
void ov80_02231804(TrHouse *s);
void ov80_02231828(TrHouse *s);
void ov80_02231844(void *a, u32 kind, u32 c);
u8 ov80_02231888(TrHouse *s);
u16 ov80_022318D0(void *save, u32 a, s32 b, u16 *out1, u16 *out2);
void ov80_022319B0(TrHouse *s);
void ov80_02231A04(TrHouse *s);


/* Generated integration prototypes. */
void ov80_022313C0(TrHouse *s);
void ov80_022314A0(TrHouse *s);
void ov80_022314DC(TrHouse *s, TrHouseSrc *src);
u16 ov80_02231518(TrHouseSrc *src, u32 unused);
u8 ov80_022317C0(TrHouse *s);
u8 ov80_022317CC(TrHouse *s);
void ov80_022317D0(TrHouse *s, u32 a);
void ov80_02231804(TrHouse *s);
void ov80_02231828(TrHouse *s);
void ov80_02231844(void *a, u32 kind, u32 c);
u8 ov80_02231888(TrHouse *s);
u16 ov80_022318D0(void *save, u32 a, s32 b, u16 *out1, u16 *out2);
void ov80_022319B0(TrHouse *s);
void ov80_02231A04(TrHouse *s);
#endif
