#ifndef POKEHEARTGOLD_RENDER_WINDOW_H
#define POKEHEARTGOLD_RENDER_WINDOW_H

#include "bg_window.h"
#include "pokemon_types_def.h"

typedef struct WaitingIcon WaitingIcon; // todo: copy from pokediamond
struct PokepicManager;

void LoadUserFrameGfx1(BgConfig *bgConfig, enum GFBgLayer layer, u16 baseTile, u8 paletteNum, u8 frame, enum HeapID heapId);
void DrawFrameAndWindow1(Window *window, BOOL dont_copy_to_vram, u16 baseTile, u8 palette_num);
void LoadUserFrameGfx2(BgConfig *bgConfig, u32 layer, u16 baseTile, u8 paletteNum, u8 frame, enum HeapID heapId);
void DrawFrameAndWindow2(Window *window, BOOL dont_copy_to_vram, u16 baseTile, u8 palette_num);
void ClearFrameAndWindow2(Window *window, BOOL dont_copy_to_vram);
void DrawFrameAndWindow3(Window *window, BOOL dont_copy_to_vram, u16 baseTile, u8 palette_num, u8 type);
void EraseFrameAndWindow1(Window *window, BOOL dont_copy_to_vram);
void LoadMapSignpostFrameAndGraphic(BgConfig *bgConfig, u8 bgId, u16 baseTile, u8 plttNum, u8 type, u16 map, enum HeapID heapId);
WaitingIcon *WaitingIcon_New(Window *window, u16 tileNum);
void WaitingIcon_Delete(WaitingIcon *waitingIcon);
struct PokepicManager *DrawPokemonPicFromSpecies(BgConfig *bgConfig, GFBgLayer layer, int x, int y, u8 paletteNum, u16 baseTile, u16 species, u8 gender, enum HeapID heapID);
struct PokepicManager *DrawPokemonPicFromMon(BgConfig *bgConfig, GFBgLayer layer, int x, int y, u8 paletteNum, u16 baseTile, Pokemon *mon, enum HeapID heapID);
void LoadUserFrameGfx1Tiles(BgConfig *bgConfig, u32 layer, u32 baseTile, BOOL frame, enum HeapID heapId);
u32 GetUserFrameGfx1PaletteMember(void);
void LoadDownArrowTiles(Window *window, int baseTile);
void WaitingIcon_DeleteWithoutRestore(WaitingIcon *);

#endif // POKEHEARTGOLD_RENDER_WINDOW_H
