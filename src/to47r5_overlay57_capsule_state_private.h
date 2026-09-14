#ifndef POKEHEARTGOLD_OVERLAY_57_RESIDUAL_9_PART1_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY_57_RESIDUAL_9_PART1_PRIVATE_H

#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef BOOL (*Ov57ListCallback)(void *);

void *NARC_New(u32, u32);
void NARC_Delete(void *);
BOOL IsPaletteFadeFinished(void);
void *TouchscreenListMenu_HandleInput(void *);
void *Save_GameStats_Get(void *);
void GameStats_AddScore(void *, int);
void *SealCase_GetCapsuleI(void *, int);
void SetMonData(void *, int, void *);
BOOL System_GetTouchHeldCoords(u32 *, u32 *);
void ManagedSprite_SetPositionXY(void *, s16, s16);
u8 sub_0209106C(u8);
BOOL GiveOrTakeSeal2(void *, int, s16);
void PlaySE(u16);
void TouchHitboxController_IsTriggered(void *);

void ov57_02237EB8(u32, void *, int);
void ov57_02237F14(void *);
void ov57_02237F3C(void *);
void ov57_022383D0(void *, BOOL);
BOOL ov57_022383F8(void *, int);
void ov57_02238438(void *, int);
void ov57_0223848C(void *, int);
BOOL ov57_022384C0(void *);
void ov57_02238508(void *, int);
void ov57_0223853C(void *);
void ov57_022385DC(void *);
void ov57_0223864C(void *);
void ov57_0223866C(void *, BOOL);
void ov57_02238794(void *);
void ov57_022387C0(void *, BOOL);
void ov57_022388E4(void *, u32);
void ov57_02238958(void *);
void ov57_02238A00(void *);
void ov57_02238AC0(void *);
void ov57_02238DD0(void *);
void ov57_02238E48(void *);
void ov57_02238F48(void *);
void ov57_02238FC4(void *);
void ov57_02238FEC(void *);
void ov57_02239014(void *);
void ov57_02239114(void *, void *);
void ov57_02239184(void *);
void ov57_0223921C(void *);
void ov57_02239240(void *, BOOL);
void ov57_02239260(void *);
void ov57_022392F4(void *, void *);
void ov57_022394AC(void *);
void ov57_02239558(void *);
void ov57_02239588(void *);
void ov57_02239728(void *, u32, u32, u32);
void ov57_022399F8(void *);
void ov57_02239B2C(void *, u32);
void ov57_02239B94(void);
void ov57_02239BAC(void);
void ov57_02239BCC(void);
void ov57_02239BEC(void *, void *);
void ov57_02239C88(void *, void *);
void ov57_02239CE8(void *, void *);
void ov57_02239D48(void *, void *);
void ov57_02239EB4(void *);
void ov57_0223A034(void *, BOOL);
void ov57_0223A058(void *);
void ov57_0223A05C(void *);
int ov57_0223A6B8(void *);
BOOL ov57_0223A7DC(void *);
int ov57_0223A8FC(void *);
int ov57_0223AB58(void *);
int ov57_0223B180(void *);
int ov57_0223B620(void *);
void ov57_0223B700(void *);
void ov57_0223B75C(void *);
void ov57_0223B78C(void *);
void ov57_0223B948(void *, BOOL);

BOOL ov57_0223A104(void *);
BOOL ov57_0223A31C(void *);

#endif
