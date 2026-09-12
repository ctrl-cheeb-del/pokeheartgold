#ifndef POKEHEARTGOLD_OVERLAY18_FILTER_INPUT_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY18_FILTER_INPUT_INTERNAL_H

#include "global.h"

#include "dex_mon_measures.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "pokedex.h"
#include "system.h"
#include "touchscreen.h"

extern const TouchscreenHitbox ov18_021FB704[];
extern const TouchscreenHitbox ov18_021FB934[];
extern const TouchscreenHitbox ov18_021FB804[];
extern const TouchscreenHitbox ov18_021FB7E0[];
extern const TouchscreenHitbox ov18_021FB630[];
extern const int ov18_021FB698[];
extern const int ov18_021FB904[];
extern const int ov18_021FB760[];
extern const int ov18_021FB7C0[];

int ov18_021F7B94(void *work, int *touched);
int ov18_021F7C14(void *work, int *touched);
int ov18_021F7D00(void *work, int *touched);
int ov18_021F7D30(void *work, int *touched);
int ov18_021F7DCC(void *work, int *touched);
int ov18_021F7E70(void *work, int *touched);
void *ov18_021F8168(u32 index, u32 *count);
void ov18_021F8198(u16 *dst, u32 *count, const Pokedex *pokedex, const u16 *src, u32 length);
void ov18_021F81D8(void *dst, const Pokedex *pokedex, const u16 *src, u32 count);
void ov18_021F822C(u32 index, u16 *dst, u32 *dstCount, const u16 *filter, u32 filterCount, const Pokedex *pokedex);
void ov18_021F82CC(u32 index, u16 *dst, u32 *dstCount, const u16 *filter, u32 filterCount, const Pokedex *pokedex);
void ov18_021F831C(void *work, u16 *dst, u32 *dstCount, const u16 *filter, u32 filterCount, const Pokedex *pokedex);
void ov18_021F8468(u32 index, u16 *dst, u32 *dstCount, const u16 *filter, u32 filterCount, const Pokedex *pokedex);
void ov18_021F8584(void *work, u32 flags, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void ov18_021F8640(void *work, u16 lowerIndex, u16 upperIndex, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void ov18_021F86D0(void *work, u16 lowerIndex, u16 upperIndex, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex);
void ov18_021F8764(u16 *dst, u32 *dstCount, const u16 *filter, u32 filterCount, const u16 *src, u32 srcCount, BOOL seenOnly, const Pokedex *pokedex);
int ov18_021F8970(void *work);

#endif
