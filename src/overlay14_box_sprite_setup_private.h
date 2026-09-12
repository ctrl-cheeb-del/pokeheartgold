#ifndef TO37_SOL_R10_OVERLAY14_RESIDUAL54_PRIVATE_H
#define TO37_SOL_R10_OVERLAY14_RESIDUAL54_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct SpriteTemplate {
    s16 x;
    s16 y;
    s16 z;
    u16 animation;
    s32 drawPriority;
    s32 pal;
    s32 vram;
    s32 resIdList[6];
    s32 bgPriority;
    s32 vramTransfer;
} SpriteTemplate;

extern void ov14_021F2F88(u32, s16 *, s16 *, u32);
extern void ov14_021F395C(void *, s32, s32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F2A74(void *, u32, u32);
extern void ov14_021F2C50(void *, u32, void *, u32);

extern void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
extern void ManagedSprite_SetPositionXY(void *, s16, s16);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void ManagedSprite_SetPriority(void *, u32);
extern u32 ManagedSprite_GetPriority(void *);
extern u32 ManagedSprite_GetDrawPriority(void *);
extern u32 ManagedSprite_GetPaletteOverrideOffset(void *);
extern void ManagedSprite_SetPaletteOverride(void *, u32);
extern void *SpriteSystem_NewSprite(void *, void *, const void *);
extern void *SpriteSystem_NewSpriteWithYOffset(void *, void *, const void *, s32);
extern void SpriteSystem_LoadCharResObj(void *, void *, u32, u32, u32, u32, u32);
extern void SpriteSystem_LoadPlttResObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void SpriteSystem_LoadCellResObj(void *, void *, u32, u32, u32, u32);
extern void SpriteSystem_LoadAnimResObj(void *, void *, u32, u32, u32, u32);
extern void *Sprite_GetImageProxy(void *);
extern void Sprite_SetImageProxy(void *, void *);

extern void sub_02019B1C(void *, u32, s8 *, s8 *);
extern void *sub_020776B4(void *);
extern u32 sub_02077678(void *);
extern u32 sub_0207769C(void *);
extern void *GfGfxLoader_GetCharData(void *, u32, u32, void **, u32);
extern void Heap_Free(void *);

extern const s8 ov14_021F8070[];
extern const s8 ov14_021F8078[];
extern const u8 ov14_021F810C[];
extern const u8 ov14_021F81A8[];
extern const u8 ov14_021F81DC[];
extern const u8 ov14_021F8278[];
extern const u8 ov14_021F82AC[];
extern const u8 ov14_021F82E0[];
extern const u8 ov14_021F8314[];
extern const u8 ov14_021F8348[];
extern const u8 ov14_021F837C[];
extern const u8 ov14_021F83B0[];
extern const u8 ov14_021F83E4[];
extern const u8 ov14_021F844C[];
extern const u8 ov14_021F8480[];

void ov14_021F396C(void *, u32, u32);
void ov14_021F39A0(void *, u32, u32);
void ov14_021F39D0(void *);
void ov14_021F3B3C(void *);
void ov14_021F3B5C(void *);
void ov14_021F3BC0(void *);
void ov14_021F3C08(void *);
void ov14_021F3CB4(void *);
void ov14_021F3D0C(void *, u32, u32, u32);
void ov14_021F3D70(void *, void *);
void ov14_021F3DE8(void *);
void ov14_021F3E70(void *);
void ov14_021F3F6C(void *);

#endif
