#ifndef TO45_OVERLAY_18_R20_PRIVATE_H
#define TO45_OVERLAY_18_R20_PRIVATE_H

#include "global.h"

#include "application/pokedex/pokedex_internal.h"

#pragma require_prototypes off

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

void ov18_021F1294(PokedexAppData *, int, int, int, int);
void ov18_021F12C8(PokedexAppData *, int, s16 *, s16 *, int);
void *ov18_021F11EC(PokedexAppData *, const void *);
void ov18_021F4A6C(PokedexAppData *);
void ov18_021F4D64(PokedexAppData *);
void ov18_021F4DDC(PokedexAppData *);
void ov18_021F4E28(PokedexAppData *);

extern u8 ov18_021FA3B0[];
typedef struct Ov18SpriteTemplate {
    u8 raw[0x34];
} Ov18SpriteTemplate;

extern Ov18SpriteTemplate ov18_021FA7B0[];

#endif
