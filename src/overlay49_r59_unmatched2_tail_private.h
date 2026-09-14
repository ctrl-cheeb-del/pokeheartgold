#ifndef TO46_OV49_R59_U2_PRIVATE_H
#define TO46_OV49_R59_U2_PRIVATE_H

#include "global.h"

#include "overlay_42.h"

typedef struct Ov49Result {
    s16 x;
    s16 y;
    u16 value;
    u16 kind;
    u16 zero;
} Ov49Result;

u32 ov49_0225EF88(void *);
u16 *ov49_0225EF40(void *, int);
void *ov49_0225EF84(void *);
void ov49_0225EF8C(void *, int);
void ov49_0225EF90(void *);
void ov49_0225EF68(void *);
void ov49_0225EF98(void *, u32, const void *, int);
void *ov49_02259FF0(void *);
void *ov49_02259FE8(void *);
void *ov49_02259FEC(void *);
void *ov49_0225A010(void *);
void ov49_0225A034(void *, int);
void ov49_0225A038(void *, u8);
u32 ov49_0225A30C(void *, int, int);
void ov49_0225A08C(void *, u32);
u32 ov49_0225A0AC(void *);
void ov49_0225A0EC(void *);
void *ov49_02258DAC(void *);
u32 ov49_02258E34(void *);
u32 ov49_02258E60(void *, int);
void ov49_02258EAC(void *, void *, int, int);
void ov49_02258EEC(void *, void *, int);
void ov45_0222A5E8(void *, int);
u32 ov45_0222A330(void *);
u32 ov45_0222A3A0(void *);
u32 ov45_0222A2E0(void *);
void ov45_0222A310(void *);
void ov45_0222A704(void *, int, int);
void GF_AssertFail(void);
extern const u8 ov49_02269B38[];
BOOL ov49_02260A68(void *, void *, u32);

#endif
