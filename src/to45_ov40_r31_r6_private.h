#ifndef TO45_OV40_R31_R6_PRIVATE_H
#define TO45_OV40_R31_R6_PRIVATE_H

#include "global.h"

#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S16_AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov40R31R6Work {
    u8 pad0000[0x1A4];
    u32 fadeA;
    u32 fadeB;
    u8 pad01AC[0x2C60];
    u8 strings[0xA0];
    u8 pad02EAC[0x2C];
    u8 panel[0x8C];
    u32 flag;
} Ov40R31R6Work;

void ov40_0222D980(void *, void *, u32, u32, u32, u32, u32);
u32 ov40_0222DA00(void *, void *, u32, u32);
void ov40_02230964(void *, u32);
void ov40_02237564(void *);
void ov40_02237410(void *);
void ov40_022371A0(void *);
void ov40_02237008(void *);
void ov40_02237C54(void *);
void ov40_02237C9C(void *);
void ov40_02237AC0(void *);
void ov40_02237D6C(void *);
void ov40_02236184(void *, void *);
void ov40_022361B0(void *);
void ov40_0222FA24(void *);
void ov40_0222F720(void *);
void ov40_0222F920(void *, void *);
void ov40_0222E79C(void *, void *);
void ov40_0222E7B8(void *, void *);
void ov40_0222E7DC(void *, u32);
void ov40_0222F9E0(void *, void *, u32);
void ov40_0222EED0(void *, void *, void *, void *);
void ov40_0222FA5C(void *, void *);
void ov40_0222F740(void *, void *, u32);
void ov40_0222F858(void *, u32, u32);
void ov40_0223077C(void *, void *, u32, s16);
void ov40_0222FA88(void *);
void ov40_0222F5EC(void *, s16);
void ov40_0222EFD8(void *, void *, void *);
void ov40_02237B7C(void *, u32);
void ov40_0222BF80(void *, u32);
void BgClearTilemapBufferAndCommit(void *, u32);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
void GfGfx_EngineATogglePlanes(u32, u32);
void GfGfx_EngineBTogglePlanes(u32, u32);
void sub_020879E0(void *, u32);
void sub_02087A08(void *, u32, u32);
void sub_020878EC(void *, u32, s16);
u32 ov40_02238838(void *);
u32 ov40_02238A50(void *);
u32 ov40_02238BB0(void *);

#endif
