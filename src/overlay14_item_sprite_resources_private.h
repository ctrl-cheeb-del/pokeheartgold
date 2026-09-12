#ifndef TO37_SOL_R11_OVERLAY14_R53_PRIVATE_H
#define TO37_SOL_R11_OVERLAY14_R53_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct R53Dims {
    s32 x;
    s32 y;
    s32 w;
    s32 h;
} R53Dims;

typedef struct R53PokepicTemplate {
    u16 narcID;
    u16 charDataID;
    u16 palDataID;
    u16 species;
    u8 isAnimated;
    u8 filler[3];
    u32 personality;
} R53PokepicTemplate;

extern void *Heap_AllocAtEnd(u32, u32);
extern void Heap_Free(void *);
extern void SpriteSystem_LoadCharResObj(void *, void *, u32, u32, u32, u32, u32);
extern void SpriteSystem_LoadPlttResObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void SpriteSystem_LoadCellResObj(void *, void *, u32, u32, u32, u32);
extern void SpriteSystem_LoadAnimResObj(void *, void *, u32, u32, u32, u32);
extern void *SpriteSystem_NewSprite(void *, void *, const void *);
extern void *SpriteSystem_NewSpriteWithYOffset(void *, void *, const void *, s32);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void ManagedSprite_SetAffineOverwriteMode(void *, u32);
extern void ManagedSprite_SetAffineTranslation(void *, s32, s32);
extern void *Sprite_GetImageProxy(void *);
extern void *Sprite_GetPaletteProxy(void *);
extern u32 GetItemIndexMapping(u32, u32);
extern void *GfGfxLoader_GetCharData(u32, s32, u32, void **, u32);
extern void GfGfxLoader_GXLoadPal(u32, s32, u32, u32, u32, u32);
extern void GetBoxmonSpriteCharAndPlttNarcIds(R53PokepicTemplate *, void *, u32, u32);
extern void sub_02014510(u32, s32, u32, R53Dims *, void *, u32, u32, u32, u32);
extern void ov14_021F2C1C(void *, u32, void *, u32);
extern void ov14_021F2C50(void *, u32, void *, u32);

extern const u8 ov14_021F8098[];
extern const u8 ov14_021F8210[];
extern const u8 ov14_021F8244[];
extern const u8 ov14_021F83E4[];
extern const u8 ov14_021F8418[];

void ov14_021F34EC(void *);
void ov14_021F35BC(void *);
void ov14_021F3614(void *, void *, u32);
void ov14_021F36DC(void *, void *, u32);
void ov14_021F3714(void *);
void ov14_021F37F4(void *);
void ov14_021F3844(void *, u32);
void ov14_021F38B0(void *, u32);
void ov14_021F391C(void *, u32);

#endif
