#ifndef POKEHEARTGOLD_OVERLAY18_MON_INTRO_SETUP_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY18_MON_INTRO_SETUP_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "palette.h"
#include "pokemon.h"
#include "sound_02004A44.h"
#include "sprite.h"
#include "unk_02005D10.h"

typedef struct Ov18State {
    u8 raw[0x258];
} Ov18State;

extern const BgTemplate ov18_021FBD60;
extern const BgTemplate ov18_021FBD7C;
extern const BgTemplate ov18_021FBD98;

void ov18_021F89F8(void *, Ov18State *);
void ov18_021F8AB8(Ov18State *);
void ov18_021F8B10(Ov18State *);
void ov18_021F8CCC(Ov18State *);
void ov18_021F8FA0(Ov18State *);
void ov18_021F95CC(Ov18State *);
void ov18_021F8C0C(Ov18State *);
BOOL ov18_021F8C48(Ov18State *);
void ov18_021F8C68(Ov18State *);

#endif
