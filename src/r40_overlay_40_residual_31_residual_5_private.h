#ifndef OVERLAY_40_RESIDUAL_31_RESIDUAL_5_R40_PRIVATE_H
#define OVERLAY_40_RESIDUAL_31_RESIDUAL_5_R40_PRIVATE_H
#include "global.h"
#define U32_AT(p, o)  (*(u32 *)((u8 *)(p) + (o)))
#define VU32_AT(p, o) (*(volatile u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o)  (*(void **)((u8 *)(p) + (o)))
typedef struct Ov40R31Work {
    u8 pad00[0x2f64];
    u32 flag;
} Ov40R31Work;
void ov40_02238304(void *);
void ov40_02237C74(void *);
void ov40_02237D6C(void *);
void ov40_02230964(void *, u32);
void ov40_0222FA24(void *);
void ov40_0222F720(void *);
void ov40_0222F920(void *, void *);
void ov40_0222E7B8(void *, void *);
void ov40_022361B0(void *);
void ov40_02236EB4(void *);
void ov40_0223707C(void *, u32);
void sub_020879E0(void *, u32);
void sub_020878B0(void *, u32);
void sub_02087A08(void *, u32, u32);
void GfGfx_EngineATogglePlanes(u32, u32);
void GfGfx_EngineBTogglePlanes(u32, u32);
void BgClearTilemapBufferAndCommit(void *, u32);
u32 ov40_0222DA00(void *, void *, u32, u32);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
void ov40_0222C710(void *, u32);
void ov40_02237030(void *, u32);
void ov40_02236F38(void *);
void ov40_0222BF80(void *, u32);
u32 ov40_022383C8(void *);
u32 ov40_0223854C(void *);
#endif
