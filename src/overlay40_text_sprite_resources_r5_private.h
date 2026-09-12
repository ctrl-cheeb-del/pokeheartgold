#ifndef POKEHEARTGOLD_OVERLAY40_TEXT_SPRITE_RESOURCES_R5_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY40_TEXT_SPRITE_RESOURCES_R5_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct ManagedSpriteTemplateR19 {
    s16 x;
    s16 y;
    s16 z;
    u16 animation;
    int drawPriority;
    int pal;
    int vram;
    int resIdList[6];
    int bgPriority;
    int vramTransfer;
} ManagedSpriteTemplateR19;

typedef struct TextObjCreateR19 {
    void *charData;
    void *window;
    void *spriteList;
    void *paletteProxy;
    void *resource;
    void *font;
    int y;
    int x;
    int priority;
    int palette;
    int variant;
    int heapId;
} TextObjCreateR19;

extern void sub_02013938(void *);
extern void TextOBJ_Destroy(void *);
extern void sub_02021B5C(void *);
extern void SpriteSystem_LoadCharResObjFromOpenNarc(void *, void *, void *, int, int, int, int);
extern void SpriteSystem_LoadCellResObjFromOpenNarc(void *, void *, void *, int, int, int);
extern void SpriteSystem_LoadAnimResObjFromOpenNarc(void *, void *, void *, int, int, int);
extern void SpriteManager_UnloadCharObjById(void *, int);
extern void SpriteManager_UnloadCellObjById(void *, int);
extern void SpriteManager_UnloadAnimObjById(void *, int);
extern void *SpriteSystem_NewSprite(void *, void *, const ManagedSpriteTemplateR19 *);
extern void ManagedSprite_SetPaletteOverride(void *, int);
extern void ManagedSprite_SetAnim(void *, int);
extern void ManagedSprite_TickFrame(void *);
extern void *NewString_ReadMsgData(void *, int);
extern void InitWindow(void *);
extern void AddTextWindowTopLeftCorner(void *, void *, int, int, int, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
extern void TextOBJ_CopyFromBGWindow(void *, void *, void *, int);
extern void String_Delete(void *);
extern void RemoveWindow(void *);
extern void *sub_02013910(void *, int);
extern void *sub_02013688(void *, int, int);
extern void sub_02021AC8(void *, int, int, void *);
extern void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
extern void *SpriteManager_GetSpriteList(void *);
extern void *SpriteManager_FindPlttResourceProxy(void *, int);
extern void *TextOBJ_Create(const TextObjCreateR19 *, void *);
extern void sub_020138E0(void *, int);
extern void TextOBJ_SetSpritesDrawFlag(void *, int);

void ov40_0222D55C(u8 *);
void ov40_0222D66C(u8 *, u8 *, int);
void ov40_0222D5AC(u8 *, u8 *, int);
void ov40_0222D6D0(u8 *);
void ov40_0222D6EC(u8 *, int);
void ov40_0222D73C(u8 *, int);
void ov40_0222D78C(u8 *, int);
void ov40_0222D7DC(u8 *);
void *ov40_0222D800(u8 *, int);

#endif
