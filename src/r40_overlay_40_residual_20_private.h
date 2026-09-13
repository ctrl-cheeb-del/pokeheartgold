#ifndef OVERLAY_40_RESIDUAL_20_R40_PRIVATE_H
#define OVERLAY_40_RESIDUAL_20_R40_PRIVATE_H
#include "global.h"
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct ManagedSpriteTemplateR20 {
    s16 x, y, z;
    u16 animation;
    int drawPriority;
    int pal;
    int vram;
    int resIdList[6];
    int bgPriority;
    int vramTransfer;
} ManagedSpriteTemplateR20;
u32 GetMonIconNaixEx(u32, u32, u32);
u32 GetMonIconPaletteEx(u32, u32, u32);
void SpriteSystem_LoadCharResObjFromOpenNarcWithHardwareMappingType(void *, void *, void *, u32, u32, u32, u32);
void *SpriteSystem_NewSprite(void *, void *, const ManagedSpriteTemplateR20 *);
void ManagedSprite_SetPaletteOverrideOffset(void *, u32);
void ManagedSprite_SetAnim(void *, u32);
void ManagedSprite_TickFrame(void *);
void SpriteManager_UnloadCharObjById(void *, u32);
void Sprite_DeleteAndFreeResources(void *);
void *ov40_0222FEA0(void *, void *, u32, u32, u32, u32);
void ov40_0222FF48(void *, u32, void *);
#endif
