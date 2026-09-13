#ifndef OVERLAY34_INPUT_R40_PRIVATE_H
#define OVERLAY34_INPUT_R40_PRIVATE_H
#include "global.h"
typedef struct Ov34State {
    u8 raw[0x400];
} Ov34State;
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
extern const u8 ov34_0225E6AC[];
extern const u8 ov34_0225E730[];
extern u8 gSystem[];
void Sprite_SetDrawFlag(void *, BOOL);
void ov34_0225DDB8(void *, int);
void *ov34_0225E5E4(Ov34State *);
void ov34_0225E5DC(Ov34State *, void *);
int TouchscreenHitbox_FindRectAtTouchHeld(const void *);
void System_GetTouchHeldCoords(u32 *, u32 *);
void ov34_0225DE04(Ov34State *);
int ov34_0225DE94(Ov34State *);
int ov34_0225E5D4(Ov34State *);
void ov34_0225E5EC(Ov34State *, int);
int ov34_0225DC0C(int, int);
int ov01_021F6B10(void *);
void *sub_02035754(int);
void *sub_02035784(void);
u32 PlayerProfile_GetTrainerID(void *);
void PlaySE(int);
int ov34_0225E020(Ov34State *);
#endif
