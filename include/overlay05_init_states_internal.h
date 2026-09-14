#ifndef OV05_RESIDUAL_2_PRIVATE_H
#define OV05_RESIDUAL_2_PRIVATE_H

#include "global.h"

typedef u8 Ov05Work;

#define OV05_U8(w, off)  (*(u8 *)((w) + (off)))
#define OV05_U32(w, off) (*(u32 *)((w) + (off)))
#define OV05_PTR(w, off) (*(void **)((w) + (off)))

extern void Main_SetVBlankIntrCB(void (*callback)(void *), void *arg);
extern void HBlankInterruptDisable(void);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void *BgConfig_Alloc(u32 heapId);
extern void *PaletteData_Init(u32 heapId);
extern void PaletteData_AllocBuffers(void *data, u32 bufferId, u32 size, u32 heapId);
extern void BG_SetMaskColor(u32 bgId, u32 color);
extern void sub_0203A880(void);
extern void sub_020880CC(u32, u32);
extern BOOL sub_02034818(u32);
extern u32 PlayerProfile_GetVersion(void *);
extern void sub_0202FD28(void *, u32, void *, u32);
extern void *NewMsgDataFromNarc(u32, u32, u32, u32);
extern void *MessageFormat_New(u32);
extern void *String_New(u32, u32);

extern void ov05_0221BB00(void);
extern void ov05_0221DB94(Ov05Work *);
extern void ov05_0221DC60(Ov05Work *);
extern void ov05_0221E07C(Ov05Work *);
extern void ov05_0221E274(Ov05Work *);
extern void ov05_0221DD08(Ov05Work *);
extern void ov05_0221E5E4(Ov05Work *);
extern void ov05_0221E944(Ov05Work *);
extern void ov05_0221DE38(Ov05Work *);
extern void ov05_0221CE88(Ov05Work *);
extern void ov05_0221CEB8(Ov05Work *, s32, s32);
extern void ov05_0221D094(Ov05Work *);
extern void ov05_0221D228(void);
extern void ov05_0221D6C4(Ov05Work *, s32, s32);
extern void ov05_0221D240(Ov05Work *);
extern void ov05_0221D9F0(Ov05Work *);
extern void ov05_0221D140(Ov05Work *);
extern void ov05_0221D7AC(Ov05Work *);
extern BOOL ov05_0221E9F8(Ov05Work *);
extern void ov05_0221E9C4(Ov05Work *);
extern void ReadMsgDataIntoString(void *, u32, void *);
extern u8 AddTextPrinterParameterized(void *, u32, void *, u32, u32, u32, void *);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void FillWindowPixelRect(void *, u32, u32, u32, u32, u32);
extern void DrawFrameAndWindow2(void *, u32, u32, u32);
extern void *CreateYesNoMenu(void *, const void *, u32, u32, u32, u32);
extern int Handle2dMenuInput_DeleteOnFinish(void *, u32);
extern void Clear2dMenuWindowAndDelete(void *, u32);
extern void ClearFrameAndWindow2(void *, u32);
extern u8 gSystem[];

extern const u8 ov05_0221EAC0[];
extern const u8 ov05_0221EA98[];
extern const u8 ov05_0221EC28[];
extern const u8 ov05_0221EC98[];
extern const u8 ov05_0221EA58[];

void ov05_0221BB30(Ov05Work *work);
int ov05_0221BD28(Ov05Work *work);
int ov05_0221BE04(Ov05Work *work);
int ov05_0221BE80(Ov05Work *work);
int ov05_0221BF08(Ov05Work *work);

#endif
