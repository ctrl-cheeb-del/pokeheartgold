#ifndef OV00_THUMB_PRIVATE_H
#define OV00_THUMB_PRIVATE_H

#include "global.h"

typedef struct Ov00Sys {
    u8 unk_0000[0xFA4];
    u32 unk_0FA4;
    u32 unk_0FA8;
    u32 unk_0FAC;
    u32 unk_0FB0;
    u32 unk_0FB4;
    u32 unk_0FB8;
    u32 unk_0FBC;
    u32 unk_0FC0;
    u8 unk_0FC4[0x1044 - 0x0FC4];
    u8 unk_1044[0x1064 - 0x1044];
    u32 unk_1064;
    u32 unk_1068;
    u32 unk_106C;
    u32 unk_1070;
    u32 unk_1074;
    u32 unk_1078;
    u32 unk_107C;
    u32 unk_1080;
    u32 unk_1084;
    u32 unk_1088;
    u32 unk_108C;
    u32 unk_1090;
    u32 unk_1094;
    u32 unk_1098;
    u32 unk_109C;
    u32 unk_10A0;
    u32 unk_10A4;
    u32 unk_10A8;
    u32 unk_10AC[8];
    u8 unk_10CC[0x10D6 - 0x10CC];
    u16 unk_10D6;
    u8 unk_10D8[0x10E0 - 0x10D8];
    u8 unk_10E0;
    u8 unk_10E1[0x10E5 - 0x10E1];
    u8 unk_10E5;
    u8 unk_10E6;
    u8 unk_10E7[0x1108 - 0x10E7];
} Ov00Sys;

typedef struct Ov00Vct {
    u8 unk_0000[0x198C];
    u32 unk_198C;
    u8 unk_1990[0x19F0 - 0x1990];
    u32 unk_19F0;
} Ov00Vct;

typedef struct Ov00VctBlock {
    Ov00Vct *unk_00;
    u32 unk_04;
    u32 unk_08;
} Ov00VctBlock;

void ov00_021E7A1C(u32 a0);
void ov00_021E7ACC(void);
void ov00_021E7AE0(void);
void ov00_021E5AE8(void);
void ov00_021E6388(u32 a0);
void ov00_021E7234(u32 a0);
void ov00_021E7A30(void);
void ov00_021EC8D8(void);
void ov00_021ED9B4(void);

void ov00_021E5C84(u32 a0, u32 a1);
void ov00_021E5CA0(u32 a0, u32 a1);
void ov00_021E5CBC(u32 a0);
void ov00_021E5CD0(u32 a0, u32 a1);
void ov00_021E5E34(void);
void ov00_021E6274(u32 a0);
void ov00_021E6298(void);
void ov00_021E62D4(void);
void ov00_021E62D8(void);
u32 ov00_021E6424(void);
void ov00_021E6428(u32 a0, s32 a1);
void ov00_021E6994(void);
void ov00_021E6A4C(void);
void ov00_021E6CA4(u32 a0);
void ov00_021E6CB8(void);
void ov00_021E6CCC(u32 a0, u32 a1);
u8 ov00_021E6D68(u32 a0);
s32 ov00_021E6EBC(void);
void ov00_021E6FBC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 ov00_021E7080(void);
u32 ov00_021E709C(void);
void ov00_021E70B8(u32 a0);
void ov00_021E70CC(u16 a0);
void ov00_021E70E0(void);
void ov00_021E7130(void);
void ov00_021E7220(u8 a0);
void ov00_021E7300(void);
u8 ov00_021E7314(void);
void ov00_021E7328(void);
void ov00_021E73E4(void);

#endif
