#ifndef OVERLAY96_SHOP_TRANSITION_PRIVATE_H
#define OVERLAY96_SHOP_TRANSITION_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"

void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
void PokeathlonCourse_SetStateField07(void *course, u32 state);
u32 ov96_021E637C(void *course);
u32 ov96_021E667C(void *course);
void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
void ov96_021F1170(void *course);
u32 ov96_021F107C(void *course);

extern const GraphicsModes ov96_0221BC7C;
extern const BgTemplate ov96_0221BCE8;
extern const BgTemplate ov96_0221BD04;
extern const BgTemplate ov96_0221BD3C;
extern const BgTemplate ov96_0221BD58;
extern const BgTemplate ov96_0221BD74;
extern const BgTemplate ov96_0221BD90;
extern const BgTemplate ov96_0221BCCC;
extern const BgTemplate ov96_0221BD20;

u32 ov96_021F0AE0(void *course, u8 *state);
void ov96_021F0BD4(BgConfig *bgConfig);

#endif
