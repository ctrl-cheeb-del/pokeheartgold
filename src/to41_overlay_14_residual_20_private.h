#ifndef TO40_OPUS_R2_OV14_R20_PRIVATE_H
#define TO40_OPUS_R2_OV14_R20_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8_AT(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16_AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern u32 sub_02019978(void *, u32);
extern void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void ManagedSprite_GetPositionXY(void *, s32 *, s32 *);

extern void ov14_021F44B4(void *, u32);
extern void ov14_021E85BC(void *);
extern void ov14_021E8620(void *);
extern u32 ov14_021E8514(void *);
extern u32 ov14_021E813C(void *);

extern u32 IsPaletteFadeFinished(void);
extern u32 ov14_021E9F20(void *);
extern u32 ov14_021E9434(void *);
extern u32 ov14_021F2A04(void *, u32);
extern void ov14_021E7AD4(void *, u32, u32, u32);
extern u32 ov14_021E7B8C(void *);
extern void ov14_021F29E4(void *, u32, u32);
extern void ManagedSprite_SetPositionXY(void *, s32, s32);
extern void ov14_021F3190(void *, u32, u32);
extern void ov14_021E6CF8(void *, u32, u32);
extern u32 ov14_021E70B0(void *, u32);
extern u32 ov14_021E65C4(void *);
extern void ov14_021E7148(void *, void *);
extern u32 ov14_021E80A8(void *);
extern void ov14_021E7FEC(void *);
extern void ov14_021F3488(void *, u32, u32);
extern void ov14_021E6048(void *);
extern void SysTask_Destroy(void *);
extern void ov14_021F6B10(void *);
extern void ov14_021E5EE8(void *);
extern void ov14_021E7D7C(void *);
extern void ov14_021F29AC(void *);
extern void ov14_021F4F00(void *);
extern void ov14_021E5DB8(void *);
extern void ov14_021E5E94(void *);
extern void ov14_021E5C00(void *);
extern void NARC_Delete(void *);
extern void sub_02021238(void);
extern void GfGfx_EngineASetPlanes(u32);
extern void GfGfx_EngineBSetPlanes(u32);
extern void Heap_Free(void *);
extern void Heap_Destroy(u32);
extern void ov14_021F391C(void *, u32);
extern void ov14_021F2A18(void *, u32, u32);
extern void PlaySE(u16);
u32 ov14_021EA928(void *);

extern void ov14_021F3B3C(void *);
extern void ov14_021E7AE4(void *, u32, u32);
extern u32 ov14_021E7B98(void *);

typedef u32 (*Ov14StateFunc)(void *);
extern Ov14StateFunc const ov14_021F7D9C[];

#endif
