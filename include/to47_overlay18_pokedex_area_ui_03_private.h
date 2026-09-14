#ifndef TO47_SOL_R4_OVERLAY18_POKEDEX_AREA_03_PRIVATE_H
#define TO47_SOL_R4_OVERLAY18_POKEDEX_AREA_03_PRIVATE_H

#include "global.h"

#include "gf_gfx_loader.h"
#include "overlay18_pokedex_area_ui_private.h"
#include "pokemon.h"
#include "sprite_system.h"

typedef struct Ov18AreaFlagsR3 {
    u8 low : 4;
    u8 toggle : 4;
} Ov18AreaFlagsR3;

u32 ov18_021F967C(u32 index);
u8 ov18_021F9688(u32 index);
void ov18_021F1FDC(void *p, int idx);
void ov18_021F209C(void *p, u32 species, int index, int spriteIdx);
void ov18_021F21FC(void *p, int idx, u32 resource);
void ov18_021F2270(void *p);

#endif
