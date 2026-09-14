#ifndef POKEHEARTGOLD_OVERLAY18_POKEDEX_SEARCH_CONTROLS_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY18_POKEDEX_SEARCH_CONTROLS_PRIVATE_H

#include "global.h"

#include "menu_input_state.h"
#include "sprite_system.h"
#include "system.h"
#include "unk_02005D10.h"
#include "unk_02019BA4.h"
#include "unk_02020A0C.h"

typedef struct Ov18MenuState {
    u8 raw[0x18a0];
} Ov18MenuState;

extern const TouchscreenHitbox ov18_021FB9A8[];
extern const DpadMenuBox ov18_021FBB0C[];
extern const GridCallbacks ov18_021FB658[];
extern const u8 ov18_021FBD28[];

void ov18_021F11C0(Ov18MenuState *, int, int);
void ov18_021F118C(Ov18MenuState *, int, int);
void ov18_021F77C0(Ov18MenuState *, int);
void ov18_021F7748(Ov18MenuState *);
int ov18_021F7790(Ov18MenuState *);
void ov18_021F7800(Ov18MenuState *, int, int);

#endif
