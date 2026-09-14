#ifndef TO46_OVERLAY_57_STATE_ENTRY_PRIVATE_H
#define TO46_OVERLAY_57_STATE_ENTRY_PRIVATE_H

#include "global.h"

#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov57Part1Work {
    u8 pad_000[0x404];
    s32 state;
    s32 result;
    s32 touchMode;
    s32 delay;
    u8 pad_414[0x20];
    void *sprites[3];
} Ov57Part1Work;

BOOL IsPaletteFadeFinished(void);
void GfGfx_EngineATogglePlanes(u32, BOOL);
void GfGfx_EngineBTogglePlanes(u32, BOOL);
void SetBgPriority(u32, u32);
void ManagedSprite_SetAnimationFrame(void *, u16);
void ManagedSprite_SetDrawFlag(void *, BOOL);
void ClearWindowTilemapAndCopyToVram(void *);
void CopyWindowToVram(void *);
void sub_0200E5D4(void *, BOOL);
void ov57_0223A034(void *, BOOL);
void ov57_02239240(void *, BOOL);
void ov57_022387C0(void *, BOOL);
void ov57_02238AF0(void *, s32);
void ov57_02239728(void *, u32, u32, u32);
void ov57_022398C4(void *);
void ov57_022399F8(void *);
void ov57_02239B0C(void *);
void ov57_02239BAC(void);
void ov57_02239BCC(void);
BOOL ov57_0223B940(void);
void ov57_0223B948(void *, BOOL);
void ov57_0223B75C(void *);
void ov57_0223B78C(void *);
void ov57_0223B828(void *, u32, u32, u32);
void ov57_0223866C(void *, BOOL);
int ov57_0223A6B8(void *);
BOOL ov57_0223A7DC(void *);

#endif // TO46_OVERLAY_57_STATE_ENTRY_PRIVATE_H
