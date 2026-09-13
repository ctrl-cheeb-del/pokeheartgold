#ifndef OVERLAY_40_RESIDUAL_14_R40_PRIVATE_H
#define OVERLAY_40_RESIDUAL_14_R40_PRIVATE_H
#include "global.h"
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct Ov40SpritePairR14 {
    u8 pad00[4];
    s32 limit;
    s16 pad08;
    u8 pad0a[6];
    s32 count;
    u8 pad14[0x18];
    void *sprite1;
    void *sprite2;
} Ov40SpritePairR14;
typedef struct ManagedSpriteTemplateR14 {
    s16 x, y, z;
    u16 animation;
    int drawPriority;
    int pal;
    int vram;
    int resIdList[6];
    int bgPriority;
    int vramTransfer;
} ManagedSpriteTemplateR14;
void ManagedSprite_SetDrawFlag(void *, BOOL);
void ManagedSprite_TickTwoFrames(void *);
void SpriteManager_UnloadCharObjById(void *, u32);
void SpriteManager_UnloadCellObjById(void *, u32);
void SpriteManager_UnloadAnimObjById(void *, u32);
void Sprite_DeleteAndFreeResources(void *);
void *SpriteSystem_NewSprite(void *, void *, const ManagedSpriteTemplateR14 *);
void ManagedSprite_SetPaletteOverride(void *, u32);
void ManagedSprite_SetAnim(void *, u32);
void ManagedSprite_TickFrame(void *);
void ov40_0222F878(Ov40SpritePairR14 *);
void ov40_0222F8C0(Ov40SpritePairR14 *);
void ov40_0222F920(Ov40SpritePairR14 *, void *);
void *ov40_0222F950(void *, void *, u32, u32);
#endif
