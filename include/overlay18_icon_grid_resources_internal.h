#ifndef POKEHEARTGOLD_OVERLAY18_ICON_GRID_RESOURCES_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY18_ICON_GRID_RESOURCES_INTERNAL_H

#include "global.h"

#include "gf_gfx_loader.h"
#include "pokedex.h"
#include "pokemon_icon_idx.h"
#include "sprite_system.h"

#define PTR(p, off, T) (*(T **)((u8 *)(p) + (off)))
#define SPR(p, i)      (*(ManagedSprite **)((u8 *)(p) + 0x670 + (i) * 4))

void Heap_Free(void *p);
void ov18_021F111C(void *p, int idx, void *data, int size, int kind);
void ov18_021F1160(void *p, int idx, int draw);
void ov18_021F13DC(void *p, u32 count);
void *ov18_021F148C(void *p, u32 species, u32 form, NNSG2dCharacterData **out);
void ov18_021F14B4(void *p, void *data, int idx, int palette);
void ov18_021F14FC(void *p, u32 species, u32 form, int idx);
void ov18_021F1534(void *p, u32 species, u32 form, int idx);
void ov18_021F17FC(void *p);
void ov18_021F18E0(void *p);
void ov18_021F193C(void *p);
void ov18_021F19EC(void *p);
void ov18_021F1324(void *p, u32 count);
void ov18_021F1424(void *p, int first);
void ov18_021F1A30(void *p, int idx);
void ov18_021F1598(void *p, int entry, int spriteIdx);
void ov18_021F1620(void *p, int base);
extern const ManagedSpriteTemplate ov18_021FA3E8;
extern const ManagedSpriteTemplate ov18_021FABC0;
extern const ManagedSpriteTemplate ov18_021FABF4;

#endif
