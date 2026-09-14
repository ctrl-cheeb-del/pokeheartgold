#ifndef POKEHEARTGOLD_OVERLAY49_SCENE_SETUP_R26_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_SCENE_SETUP_R26_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

void *NARC_New(u32, u32);

#endif
