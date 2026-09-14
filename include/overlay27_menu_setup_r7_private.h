#ifndef POKEHEARTGOLD_OVERLAY27_MENU_SETUP_R7_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY27_MENU_SETUP_R7_PRIVATE_H

#include "global.h"

typedef struct Sprite Sprite;
typedef struct Window {
    u8 raw[0x10];
} Window;

typedef struct Ov27IconEntryR7 {
    u16 sprite;
    u16 anim;
    u8 window;
    u8 pad;
} Ov27IconEntryR7;

typedef struct Ov27WindowPosR7 {
    u32 x;
    u32 y;
} Ov27WindowPosR7;

typedef struct Ov27ResourceSetR7 {
    u32 member;
    u32 unused[2];
} Ov27ResourceSetR7;

typedef struct Ov27PaletteDataR7 {
    u8 pad[0xC];
    void *raw;
} Ov27PaletteDataR7;

typedef struct Ov27WorkR7 {
    u8 raw[0x520];
} Ov27WorkR7;

typedef struct Ov27WorkManagersR7 {
    u8 pad[0x144];
    void *managers[4];
} Ov27WorkManagersR7;

void Sprite_SetDrawFlag(Sprite *sprite, int draw);
void Sprite_SetAnimCtrlSeq(Sprite *sprite, int seq);
void CopyWindowToVram(Window *window);
BOOL FieldSystem_ShouldDrawStartMenuIcon(void *fieldSystem, int icon);
BOOL ov27_0225BDC8(Ov27WorkR7 *work);
void ov27_0225AA7C(Ov27WorkR7 *work);
u8 ov27_0225AA60(const u8 *values, int count);
int ov27_0225C1AC(Ov27WorkR7 *work, int selection);
void ov27_0225C1EC(Ov27WorkR7 *work);
void ov27_0225AAD4(Ov27WorkR7 *work);

extern const Ov27IconEntryR7 ov27_0225CF10[];
extern const Ov27ResourceSetR7 ov27_0225CEEC[];
extern const Ov27ResourceSetR7 ov27_0225CEF0[];
extern const Ov27ResourceSetR7 ov27_0225CEF4[];
extern const Ov27WindowPosR7 ov27_0225D074[];

u32 GfGfxLoader_LoadCharData(u32 narc, s32 member, void *bg, u32 layer, u32 start, u32 size, BOOL compressed, u32 heap);
void GfGfxLoader_LoadScrnData(u32 narc, s32 member, void *bg, u32 layer, u32 start, u32 size, BOOL compressed, u32 heap);
void GfGfxLoader_GXLoadPal(u32 narc, s32 member, u32 location, u32 offset, u32 size, u32 heap);
void AddWindowParameterized(void *bg, Window *window, u32 bgId, u32 x, u32 y, u32 width, u32 height, u32 palette, u32 baseTile);
void FillWindowPixelBuffer(Window *window, u8 value);
void ov27_0225AC00(void *bg, int variant, Window *top, Window *bottom, Window *icons);
void ov27_0225AD0C(Ov27WorkR7 *work);
void *G2dRenderer_Init(u32 count, void *renderer, u32 heap);
void G2dRenderer_SetSubSurfaceCoords(void *renderer, int x, int y);
void *Create2DGfxResObjMan(u32 count, int type, u32 heap);
void *Save_PlayerData_GetProfile(void *save);
int PlayerProfile_GetTrainerGender(void *profile);
void *Save_Bag_Get(void *save);
void ov27_0225AEA8(void *fieldSystem, void **managers, void *resources, int index, int resourceId, int gender, void *bag, int mode);
void *AddCellOrAnimResObjFromNarc(void *manager, u32 narc, s32 member, BOOL compressed, int resourceId, int type, u32 heap);
void *GfGfxLoader_GetPlttData(u32 narc, s32 member, Ov27PaletteDataR7 **data, u32 heap);
void Heap_Free(void *ptr);

#endif
