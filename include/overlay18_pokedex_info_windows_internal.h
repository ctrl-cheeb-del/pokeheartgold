#ifndef POKEHEARTGOLD_OVERLAY18_POKEDEX_INFO_WINDOWS_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY18_POKEDEX_INFO_WINDOWS_INTERNAL_H
#include "global.h"

#include "unk_0201956C.h"

#define PTR(p, off) (*(void **)((u8 *)(p) + (off)))

void ov18_021EE388(void *);
void ov18_021EE35C(void *, const void *, u32);
void ov18_021F9648(void *, void *, u32, u32, u32, u32, u32, u32);
void ov18_021F0928(void *);
u32 ov18_021E8AE0(void *, int);
u32 MapHeader_GetMapSec(u32);
void BufferLandmarkName(void *, int, u32);

extern const u8 ov18_021F9DB0[];
extern const u8 ov18_021F9E4C[];
extern const u8 ov18_021F9EBC[];

void ov18_021F014C(void *);
void ov18_021F0168(void *);
void ov18_021F018C(void *);
void ov18_021F01D4(void *);
void ov18_021F03C0(void *);
void ov18_021F03E0(void *);
u32 ov18_021F04C0(void *, int);
void ov18_021F0838(void *);
void ov18_021F0858(void *);
void ov18_021F08E0(void *);
void ov18_021F0900(void *);
#endif
