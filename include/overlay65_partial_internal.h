#ifndef OVERLAY_65_PRIVATE_H
#define OVERLAY_65_PRIVATE_H
#include "global.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
extern int sub_02036FD8(u32, void *, u32);
extern int sub_02037030(u32, void *, u32);
extern void *Save_SpecialRibbons_Get(void *);
extern int sub_02037B38(u32);
extern void ov65_0221DE24(void *, u32, u32);
extern void PlaySE(u32);
extern void Sprite_SetMatrix(void *, void *);
extern int ov65_0221DFB8(void *);
extern void ov65_0221DF1C(void *);
extern void ov65_0221DC34(void *);
extern void sub_0200F450(void *);
extern void *WaitingIcon_New(void *, u32);
extern void *GetBgTilemapBuffer(void *, u32);
extern void BgCopyOrUncompressTilemapBufferRangeToVram(void *, u32, void *, u32, u32);
extern void ov65_0221FB90(void *, u32, u32, u32, void *);
extern void TouchscreenListMenu_Destroy(void *);
extern void TouchscreenListMenuSpawner_Destroy(void *);
extern u32 sub_020373B4(u16);
extern void *Party_GetMonByIndex(void *, u32);
extern u32 GetMonData(void *, u32, void *);
extern void sub_02039AD8(u32);
extern u32 sub_0203769C(void);
extern void BgSetPosTextAndCommit(void *, u32, u32, u32);
extern u32 Party_GetCount(void *);
extern void *Mon_GetBoxMon(void *);
extern void BufferBoxMonNickname(void *, u32, void *);
extern void FreeBgTilemapBuffer(void *, u32);
extern int ov65_0221E858(void *);
extern int ov65_0221E270(void *);
extern int ov65_0221EC34(void *);
extern u8 gSystem[];
extern void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);
extern void ov65_0221E194(void);
extern void ov65_0221E2C0(void);
extern void ov65_0221F2A8(void);
extern u32 GetMonIconPaletteEx(u32, u32, u32);
extern void Sprite_SetPalOffset(void *, u32);
#endif
