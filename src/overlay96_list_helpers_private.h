#ifndef OV96_R97_H
#define OV96_R97_H
#include "global.h"
#include <nitro/mi/memory.h>
typedef struct R97Item { u32 w[5]; union { u32 raw; struct { u32 lo:8; u32 count:8; u32 mid:14; u32 state:2; } b; } v5; u32 w6; u32 w7; u32 w8; } R97Item;
typedef struct R97List { u32 w0; void *ctx; R97Item item[3]; u32 count; } R97List;
extern void GF_AssertFail(void);
extern u32 ov96_0220CA28(R97Item *);
extern void ov96_0220CF50(R97Item *,u32,void *);
extern void ov96_0220D200(void *,u32);
extern void ov96_0220CD84(R97Item *,u32);
extern void ov96_0220D0F8(R97Item *);
extern u32 MTRandom(void);
extern u32 _u32_div_f(u32,u32);
extern const u32 ov96_0221CE5C[];
extern const s32 ov96_0221CE08[];
void ov96_0220C9A0(R97List *);
void ov96_0220C9CC(R97List *);
void ov96_0220C9F4(R97Item *,u32,u32);
u32 ov96_0220CBC0(R97Item *);
u32 ov96_0220CBEC(R97Item *);
u32 ov96_0220CC18(R97Item *);
s32 ov96_0220D33C(s32,u32);
u32 ov96_0220CCBC(R97Item *);
extern const u32 ov96_0221CE34[],ov96_0221CE48[],ov96_0221CE14[],ov96_0221CE24[];
extern const u16 ov96_0221CDF4[],ov96_0221CDE8[];
extern const s16 ov96_0221CDFE[],ov96_0221CDEE[];
u32 ov96_0220CC38(R97Item *);
u32 ov96_0220CD00(R97Item *);
#endif
