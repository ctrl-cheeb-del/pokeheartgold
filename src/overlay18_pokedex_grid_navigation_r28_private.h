#ifndef POKEHEARTGOLD_OVERLAY18_POKEDEX_GRID_NAVIGATION_R28_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY18_POKEDEX_GRID_NAVIGATION_R28_PRIVATE_H

#include "global.h"

#include "constants/heap.h"
#include "constants/sndseq.h"

#include "application/pokedex/pokedex_internal.h"

#include "menu_input_state.h"
#include "system.h"
#include "unk_02020A0C.h"

extern const TouchscreenHitbox ov18_021FBA40[];
extern const DpadMenuBox ov18_021FBB94[];
extern const GridCallbacks ov18_021FB638[];
extern const u8 ov18_021FBD3C[];

void PlaySE(u32 seqNo);

void ov18_021F719C(PokedexAppData *pokedexApp, int index);
void ov18_021F71DC(PokedexAppData *pokedexApp, int currentInput, int lastInput);

#endif // POKEHEARTGOLD_OVERLAY18_POKEDEX_GRID_NAVIGATION_R28_PRIVATE_H
