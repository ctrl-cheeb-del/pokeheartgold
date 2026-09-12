#ifndef POKEHEARTGOLD_OVERLAY43_TOUCH_MENU_R15_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY43_TOUCH_MENU_R15_PRIVATE_H

#include "global.h"

#define S16_AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern void ov43_0222C378(void *, void *, void *, int, int, int, int);
extern void ov43_0222C844(void *, void *, int);
extern void ov43_0222AD20(void *, int);
extern void ov43_0222AD00(void *, int);
extern void ov43_0222AD40(void *, int, int);
extern void ov43_0222C890(void *, void *, int, int);
extern void SetBlendBrightness(int, int, int);
extern void PlaySE(int);
extern int ov43_0222C5D8(void *);
extern int TouchscreenListMenu_HandleInput(void *);
extern u8 TouchscreenListMenu_WasLastInputTouch(void *);
extern void TouchscreenListMenu_Destroy(void *);
extern void ov43_0222C600(void *);
extern int ov43_0222C620(void *);
extern void ov43_0222AB20(void *, void *, int, void *);
extern void ov43_0222C550(void *, void *, int, void *);
extern void *sub_0202C6F4(void *);
extern void *sub_0202C23C(void *, int);
extern u64 DWC_GetFriendKey(void *);
extern void ov43_0222AAA4(void *, u32, u32);
extern int TouchscreenHitbox_FindHitboxAtTouchNew(const void *);
extern const u8 ov43_0222EF60[];

int ov43_0222BC78(u8 *, u8 *, void *, int);
int ov43_0222BEEC(u8 *, void *, void *, int *);
void ov43_0222BFD4(u8 *, void *, void *, int);
int ov43_0222C228(u8 *, u32 *, void *);
int ov43_0222C2B0(u8 *, u8 *, void *, void *);
void ov43_0222C32C(u8 *, u8 *, void *, void *);

#endif
