#ifndef OV96_POKEATHLON_SHOP_UI_PRIVATE_H
#define OV96_POKEATHLON_SHOP_UI_PRIVATE_H

#include <nitro/fx/fx_vec.h>
#include <nitro/mi/memory.h>

#include "global.h"

#include "gf_gfx_planes.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern void GF_AssertFail(void);

extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *PokeathlonCourse_GetGraphicsSystem(void *);
extern u16 PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
extern void PokeathlonCourse_SetStateTransitionType(void *, u32);
extern void PokeathlonCourse_SetStateField07(void *, u32);

extern void ov96_021E9510(void *);
extern void ov96_021E95F8(void *, void *, u32, u32, u8, u8, u32);
extern void ov96_021E93B4(void *, u32);
extern void ov96_021E952C(void *);
extern void ov96_021E9570(void *, u32);
extern void ov96_0221A56C(void *, u32);
extern void ov96_021EAF78(void *, u32, u32, fx32 *, fx32 *, s32 *);

extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern u32 IsPaletteFadeFinished(void);

extern const GraphicsBanks ov96_0221BDAC;
extern fx32 VEC_DotProduct(const VecFx32 *, const VecFx32 *);
extern u8 _0221DCA0[];

u32 ov96_021F08F4(void *course);
void ov96_021F0A5C(void);
u32 ov96_021F0A7C(void *course, u8 *state);
void ov96_021F208C(int x, int y, const VecFx32 *p, fx32 thresh, VecFx32 *out);
u32 ov96_021F218C(void *a, void *b);
u32 ov96_021F22FC(void *unused, void *b, u32 group, const VecFx32 *dir);
u8 ov96_021F2780(void *p, u8 v);

#endif
