#ifndef R40_OV103_R15_PRIVATE_H
#define R40_OV103_R15_PRIVATE_H
#include "global.h"
typedef struct R40Ov103Work15 {
    u8 pad00[0xC];
    u8 *ctx;
    u8 pad10[0xC];
    u16 flag1c;
    u8 pad1e[3];
    u8 flags21_0 : 7;
    u8 flag21_7 : 1;
} R40Ov103Work15;
extern const u8 ov103_021EED58[];
extern void ov103_021EE8A8(R40Ov103Work15 *, u32);
extern void ov103_021EDA70(R40Ov103Work15 *, u32, u32);
extern void GfGfx_EngineATogglePlanes(u32, u32);
extern void GfGfx_EngineBTogglePlanes(u32, u32);
extern void ov103_021EE13C(void *);
extern void ov103_021EDF88(void *);
extern void ov103_021EE2E0(void *);
extern void ov103_021EE160(void *);
extern void *ov103_021EE048(void *, const void *);
extern void ov103_021EE0CC(void *, u32, u32);
void ov103_021EDE7C(R40Ov103Work15 *);
void ov103_021EDEA8(R40Ov103Work15 *);
#endif
