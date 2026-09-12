#ifndef POKEHEARTGOLD_OVERLAY14_SPRITE_MANAGER_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_SPRITE_MANAGER_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))

typedef struct R50Counts {
    u32 word[6];
} R50Counts;

typedef struct R50Transfer {
    u32 word[8];
} R50Transfer;

typedef struct R50Oam {
    u32 word[5];
} R50Oam;

extern const R50Counts ov14_021F80D4;
extern const R50Transfer ov14_021F80EC;
extern const R50Oam ov14_021F80A8;

extern void ManagedSprite_SetDrawPriority(void *, u32);
extern void ManagedSprite_SetOamMode(void *, u32);
extern void *SpriteSystem_Alloc(u32);
extern void *SpriteManager_New(void *);
extern void SpriteSystem_Init(void *, const R50Transfer *, const R50Oam *, u32);
extern void SpriteSystem_InitSprites(void *, void *, u32);
extern void SpriteSystem_InitManagerWithCapacities(void *, void *, const R50Counts *);
extern void *SpriteSystem_GetRenderer(void *);
extern void G2dRenderer_SetSubSurfaceCoords(void *, s32, s32);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern void Sprite_DeleteAndFreeResources(void *);

extern void ov14_021F41E4(void *);
extern void ov14_021F42EC(void *);
extern void ov14_021F2C84(void *);
extern void ov14_021F3DE8(void *);
extern void ov14_021F3714(void *);
extern void ov14_021F34EC(void *);
extern void ov14_021F3C08(void *);
extern void ov14_021F4278(void *);
extern void ov14_021F4380(void *);
extern void ov14_021F2D1C(void *);
extern void ov14_021F3E70(void *);
extern void ov14_021F37F4(void *);
extern void ov14_021F35BC(void *);
extern void ov14_021F3CB4(void *);

void ov14_021F2A74(void *, u32, u32);
void ov14_021F2A9C(void *, u32, u32);
void ov14_021F2AC8(void *);
void ov14_021F2B68(void *);
void ov14_021F2B88(void *);
void ov14_021F2BB8(void *);
void ov14_021F2BE8(void *, u32);

#endif
