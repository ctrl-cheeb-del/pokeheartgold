#ifndef POKEHEARTGOLD_OVERLAY115_PALETTE_BLEND_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY115_PALETTE_BLEND_PRIVATE_H

#include "global.h"

void *Heap_Alloc(int heapID, int size);
void *GfGfxLoader_GetPlttData(int narcId, void *narc, void **paletteData, int heapID);
void BlendPalette(const u16 *src, u16 *dest, int count, u8 amount, u16 color);
void *Sprite_GetPaletteProxy(void *sprite);
void GX_LoadOBJPltt(const void *src, u32 destSlotAddr, u32 szByte);
void Heap_Free(void *ptr);

void ov115_02260254(void *sprite, int heapID, void *narc, u8 amount, u16 color);

#endif
