#ifndef POKEHEARTGOLD_OVERLAY99_RECORD_SCREEN_RESOURCES_R11_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY99_RECORD_SCREEN_RESOURCES_R11_PRIVATE_H
#include "global.h"
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define P(p, o)   (*(void **)((u8 *)(p) + (o)))
extern void ov98_0221EC08(void *, u32, u32, u32, u32);
extern void ov98_0221EBEC(void *, u32, u32, u32, u32, u32);
extern void *ov98_0221E5C0(void *);
extern void *ov98_0221E5D0(void *);
extern void SpriteSystem_LoadCharResObjFromOpenNarc(void *, void *, void *, u32, u32, u32, u32);
extern void SpriteSystem_LoadPlttResObjFromOpenNarc(void *, void *, void *, u32, u32, u32, u32, u32);
extern void SpriteSystem_LoadCellResObjFromOpenNarc(void *, void *, void *, u32, u32, u32);
extern void SpriteSystem_LoadAnimResObjFromOpenNarc(void *, void *, void *, u32, u32, u32);
extern void ov98_0221E8A8(void *, const void *, u32, u32, u32);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void ov99_021E8F50(void *);
extern const u32 ov99_021EA384[];
extern const u32 ov99_021EA38C[];
extern const u8 ov99_021EA364[];
void ov99_021E89A4(void *);
void ov99_021E8C50(void *);
void ov99_021E8C88(void *);
#endif
