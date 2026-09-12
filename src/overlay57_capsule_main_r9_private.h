#ifndef POKEHEARTGOLD_OVERLAY57_CAPSULE_MAIN_R9_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY57_CAPSULE_MAIN_R9_PRIVATE_H
#include "global.h"
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
extern void Sprite_DeleteAndFreeResources(void *);
extern void *CapsuleGetSealI(void *, int);
extern int SealOnCapsuleGetID(void *);
extern void SpriteSystem_DrawSprites(void *);
extern void *(*ov57_0223BEB8[])(void *);
void ov57_0223A05C(void *);
BOOL ov57_0223A07C(void *);
int ov57_0223A0A8(void *, int);
void *ov57_0223A0E0(void *);
extern void ov57_0223BC4C(void *, void *);
extern void ov57_02239728(void *, int, int, int);
extern void ov57_0223B12C(void);
extern u8 gSystem[];
extern BOOL System_GetTouchNew(void);
extern void ov57_0223B828(void *, int, int, int);
extern void sub_0200E5D4(void *, int);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void ov57_0223866C(void *, int);
extern void ov57_02238FC4(void *);
extern void ov57_02239558(void *);
BOOL ov57_0223A504(void *);
extern void ManagedSprite_SetDrawPriority(void *, int);
extern void ManagedSprite_SetAnim(void *, int);
extern void ManagedSprite_SetDrawFlag(void *, int);
extern int ov57_0223B308(void *);
BOOL ov57_0223A5AC(void *);
#endif
