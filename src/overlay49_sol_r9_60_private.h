#ifndef SOL_R9_OV49_RESIDUAL_60_PRIVATE_H
#define SOL_R9_OV49_RESIDUAL_60_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

typedef struct Ov49Residual60Work {
    u8 pad00[4];
    u8 state4;
    s8 timer5;
    u8 value6;
    u8 pad07[3];
    u16 counterA;
    u8 pad0C[0xC];
    u32 copied18[4];
    u16 count28;
    u16 limit2A;
    u8 pad2C[0xC];
    u32 count38;
} Ov49Residual60Work;

typedef struct Ov49Residual60CopyBlock {
    u32 word[8];
} Ov49Residual60CopyBlock;

extern u32 ov49_02269DFC[8];
extern u8 ov49_02269B78[];
extern u8 ov49_02269B58[];
extern u8 ov49_02269B40[];
extern u8 gSystem[];

u32 ov49_0225EF88(void *);
void *ov49_0225EF84(void *);
void *ov49_0225EF40(void *, u32);
void ov49_0225EF68(void *);
void ov49_0225EF90(void *);
void ov49_0225EF8C(void *, u32);
void ov49_0225A018(void *, u32);
u8 ov49_0225A040(void *);
void ov49_0225A37C(void *, u32, u32);
void *ov49_0225A30C(void *, u32, u32);
void ov49_0225A08C(void *, void *);
void ov49_0225A0FC(void *, void *);
void ov49_0225A0EC(void *);
void ov49_0225A10C(void *, u32);
void ov49_0225A144(void *, void *, u32);
void *ov49_0225A154(void *);
u32 sub_020392A0(void);
void sub_020398D4(u32, u32);
void sub_020343E4(void);
void sub_0203986C(void);
void GF_AssertFail(void);
void ov49_02262D70(void *, void *, u32, u32, u32);
void ov49_02262E04(void *, void *, u32);
void ov49_02262DB8(void *, void *);
void *ov49_02259FF0(void *);
u32 ov49_02258DAC(void *);
void ov49_02258EEC(void *, u32, u32);
void *ov49_02258D70(void *, u32);
u8 ov49_02258F38(void *);
void ov49_02258D54(void *);
void *ov49_0225A010(void *);
void ov49_0225EF98(void *, u32, const void *, u32);
void *ov49_02259FE8(void *);
BOOL ov45_0222A230(void *, u32);
BOOL ov45_0222A550(void *, u32);
void *ov45_0222A578(void *, u32);
BOOL ov45_0222AADC(void);
void *ov45_0222AA5C(void *);
BOOL ov49_02258CB8(void *, u32, void *);
void ov49_022591C0(void *, u32);
u8 ov45_0222A920(void);
BOOL ov49_02261DBC(void *, void *, void *, void *, u32, u32);
void ov49_0225A06C(void *, u32, u32);
void ov49_0225A04C(void *, u32, u32);
void ov49_02259130(void *, u32);
void ov49_0225EFC4(void *, u32, const void *, void *);
BOOL ov49_022589D8(void *, void *, u16 *, u16 *, u32);
BOOL ov49_02258F7C(void *, u16, u16);

#endif
