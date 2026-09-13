#ifndef TO45_OVERLAY18_SCROLL_MATH_PRIVATE_H
#define TO45_OVERLAY18_SCROLL_MATH_PRIVATE_H

#include "global.h"

#include "sprite_system.h"

typedef struct PokedexAppData PokedexAppData;

u32 ov18_021F2C98(PokedexAppData *pokedexApp, int index);
int ov18_021F2CB4(PokedexAppData *pokedexApp, int index);
int ov18_021F2CC0(PokedexAppData *pokedexApp, int index);
u32 ov18_021F8950(PokedexAppData *pokedexApp, int mode);
BOOL ov18_021F2CD0(PokedexAppData *pokedexApp, int index, u32 x, u32 y);
BOOL ov18_021F2D24(PokedexAppData *pokedexApp, int index, u32 unused, u32 y, int mode);
int ov18_021F2DD4(PokedexAppData *pokedexApp, int page, int index, int mode);
u32 ov18_021F2E14(PokedexAppData *pokedexApp, int index, u32 position, u32 divisor);
void ov18_021F2E4C(PokedexAppData *pokedexApp, int index, int delta);
void ov18_021F2E80(PokedexAppData *pokedexApp, int index, int mode);

#define POKEDEX_SPRITE(app, index) (((ManagedSprite **)((u8 *)(app) + 0x670))[index])
#define POKEDEX_PAGE(app)          (*(u8 *)((u8 *)(app) + 0x1859))

#endif
