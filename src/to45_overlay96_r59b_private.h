#ifndef TO45_OVERLAY96_R59B_PRIVATE_H
#define TO45_OVERLAY96_R59B_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"

#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern const GraphicsModes ov96_0221C100;
extern const BgTemplate ov96_0221C124;
extern const BgTemplate ov96_0221C140;
extern const BgTemplate ov96_0221C15C;
extern const BgTemplate ov96_0221C178;
extern const BgTemplate ov96_0221C194;
extern const BgTemplate ov96_0221C1B0;

void *PokeathlonCourse_GetHeapAllocPtr4(void *);
void PokeathlonCourse_SetStateTransitionType(void *, u32);
void PokeathlonCourse_SetStateField07(void *, u32);
u32 ov96_021E637C(void *);
u32 ov96_021E667C(void *);
u32 IsPaletteFadeFinished(void);
void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
void ov96_021F5B60(void *);
void ov96_021F5BA0(void *);
u32 ov96_021F5A88(void *);

u32 ov96_021F5650(void *, u8 *);
void ov96_021F584C(BgConfig *);
void ov96_021F5980(void *);

#endif
