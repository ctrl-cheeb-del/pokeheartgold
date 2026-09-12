#ifndef POKEHEARTGOLD_OVERLAY14_BOX_TILEMAP_LOADER_R7_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_BOX_TILEMAP_LOADER_R7_PRIVATE_H

#include "global.h"

#define S8_AT(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct GfxCharData {
    u8 pad[0x10];
    u32 size;
    void *raw;
} GfxCharData;

typedef struct GfxScreenData {
    u8 pad[0xc];
    u16 raw[1];
} GfxScreenData;

extern void *GfGfxLoader_GetCharData(u32, s32, u32, GfxCharData **, u32);
extern void GfGfxLoader_GXLoadPal(u32, s32, u32, u32, u32, u32);
extern void *GfGfxLoader_GetScrnData(u32, s32, u32, GfxScreenData **, u32);
extern void BG_LoadCharTilesData(void *, u32, void *, u32, u32);
extern void Heap_Free(void *);
extern void ov14_021F5718(void *, void *, u32, u32, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void PaletteData_LoadNarc(void *, u32, s32, u32, u32, u32, u32);
extern void LoadRectToBgTilemapRect(void *, u32, const void *, u32, u32, u32, u32);
extern void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);

void ov14_021E76D0(void *, s32, u32, u32);
void ov14_021E7720(void *, s32, u32);
void ov14_021E7740(void *, s32, u32, u32, u32);
void ov14_021E7808(void *, s32, u32, u32, u32);
void ov14_021E783C(void *, s32, u32);
void ov14_021E78AC(void *, s32);

#endif
