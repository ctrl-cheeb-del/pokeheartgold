#ifndef POKEHEARTGOLD_OVERLAY14_BOX_SPRITE_CONTROLS_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY14_BOX_SPRITE_CONTROLS_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
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

extern void Heap_Free(void *);
extern void *Heap_AllocAtEnd(u32, u32);
extern void *AllocAtEndAndReadWholeNarcMemberByIdPair(u32, u32, u32);
extern u32 PCStorage_IsBonusWallpaperUnlocked(void *, u32);
extern void sub_020136B4(void *, s32, s32);
extern void TextOBJ_SetSpritesDrawFlag(void *, u32);

extern void ManagedSprite_SetPositionXY(void *, s16, s16);
extern void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void ManagedSprite_SetPriority(void *, u32);
extern u32 ManagedSprite_GetPriority(void *);
extern u32 ManagedSprite_GetDrawPriority(void *);

extern void SpriteSystem_LoadCharResObj(void *, void *, u32, u32, u32, u32, u32);
extern void SpriteSystem_LoadPlttResObj(void *, void *, u32, u32, u32, u32, u32, u32);
extern void SpriteSystem_LoadCellResObj(void *, void *, u32, u32, u32, u32);
extern void SpriteSystem_LoadAnimResObj(void *, void *, u32, u32, u32, u32);
extern void *SpriteSystem_NewSprite(void *, void *, const SpriteTemplate *);

extern u32 ov14_021E7930(void *, u32);
extern void ov14_021F29E4(void *, u32, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void ov14_021F2A74(void *, u32, u32);
extern void ov14_021F2C1C(void *, u32, void *, u32);
extern void ov14_021F49E0(void *);

extern const s8 ov14_021F8070[];
extern const s8 ov14_021F8078[];
extern const u8 ov14_021F8068[];
extern const SpriteTemplate ov14_021F8140;
extern const SpriteTemplate ov14_021F8174;

void ov14_021F40E8(void *p, u32 a1);
void ov14_021F4174(void *p);
void ov14_021F41E4(void *p);
void ov14_021F4278(void *p);
void ov14_021F42EC(void *p);
void ov14_021F4380(void *p);
void ov14_021F43F4(void *p, u32 a1);
void ov14_021F4410(void *q);
void ov14_021F4428(void *p);
void ov14_021F44B4(void *q, s32 dy);
void ov14_021F4530(void *p);
void ov14_021F459C(void *p);
void ov14_021F462C(void *p);
void ov14_021F46B0(void *p, u8 *buf, u32 wallpaper, u32 match, u32 size);
void ov14_021F46F4(void *q);
void ov14_021F4720(void *p);
void ov14_021F47B8(void *p, s32 dy);
void ov14_021F4848(void *p);
void ov14_021F48B4(void *p);

#endif
