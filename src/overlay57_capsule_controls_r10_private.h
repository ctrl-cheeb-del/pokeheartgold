#ifndef POKEHEARTGOLD_OVERLAY57_RESIDUAL10_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY57_RESIDUAL10_PRIVATE_H
#include "global.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov57Residual10Work {
    u8 pad_000[0x31c];
    void *sprites[2];
    u8 pad_324[0xc8];
    int values[2];
} Ov57Residual10Work;

typedef struct Ov57SelectionFields {
    u8 pad_000[0x3ec];
    int current;
    int previous;
} Ov57SelectionFields;

extern u8 gSystem[];
extern BOOL System_GetTouchHeld(void);
extern BOOL System_GetTouchNew(void);
extern void PlaySE(u32);
extern void ov57_02237E88(void *, int);
extern void ov57_02237F14(void *);
extern void ov57_02237F3C(void *);
extern void ov57_02238134(void);
extern void ov57_022383AC(void *);
extern void ov57_022383D0(void *, int);
extern void ov57_0223853C(void *);
extern void ov57_02238C30(void *, void *, int, void *, int);
extern void ov57_02238DAC(int, s16 *, s16 *);
extern void ov57_022394AC(void *);
extern void ov57_022394D8(void *, int);
extern void ov57_02239728(void *, int, int, int);
extern int ov57_0223B12C(void *);
extern void ov57_0223B180(void *);
extern int ov57_0223B1A4(void *, int);
extern int ov57_0223B288(void *);
extern int ov57_0223B2EC(void *);
extern int ov57_0223B308(void *);
extern int ov57_0223B32C(void *, int);
extern int ov57_0223B3A4(void *, int);
extern int ov57_0223B3F8(void *);
extern int ov57_0223B45C(void *);
extern BOOL ov57_0223B478(int *);
extern void ov57_0223B504(void *, int, int);
extern int ov57_0223B578(void *);
extern int ov57_0223B620(void *);
extern void ov57_0223B90C(void *, int);
extern void ov57_0223B948(void *, int);
extern void ManagedSprite_SetAnim(void *, int);
extern void ManagedSprite_SetDrawFlag(void *, int);
extern void ManagedSprite_SetPositionXY(void *, s16, s16);
extern BOOL TouchscreenHitbox_TouchNewIsIn(void *);
extern int TouchscreenHitbox_FindRectAtTouchNew(void *);
extern BOOL DoesPixelAtScreenXYMatchPtrVal(void *, int, int, int, void *);
extern const u8 ov57_0223BEB0[];

#endif
