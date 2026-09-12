#ifndef OVERLAY59_APRICORN_UI_R18_PRIVATE_H
#define OVERLAY59_APRICORN_UI_R18_PRIVATE_H

#include "global.h"

extern u8 gSystem[];
extern u16 ov59_0223C6C4[];
extern u16 ov59_0223C6C6[];
extern u32 _0223CB80[];
extern u8 ov59_0223C624[];

int ov59_0223858C(u8 *);
int ov59_022385AC(u8 *);
void ov59_02238624(void);
void ov59_02238674(u8 *);
void ov59_022386A8(u8 *);
void ov59_02238768(u8 *);
void ov59_022387D0(u8 *, int);
void ov59_022386D0(u8 *);
void ov59_02238834(u8 *, int, int);
void ov59_022388C4(u8 *);
void ov59_0223891C(u8 *, int);
void ov59_0223892C(u8 *, u8);
void ov59_02238A04(u8 *, int);
void ov59_02238AB0(u8 *, int);
void ov59_02238D74(u8 *);
void ov59_02238C24(u8 *);
void ov59_02239428(u8 *);
void ov59_02239604(u8 *);
void ov59_02239704(u8 *);
void ov59_022397E4(u8 *);
void ov59_022398CC(u8 *);
void ov59_022399F0(u8 *);
void ov59_022393D4(void *);
void ov59_02239A08(u8 *);
void ov59_02239918(u8 *);
void ov59_022398A0(u8 *);
void ov59_0223978C(u8 *);
void ov59_022396E4(u8 *);
void ov59_022395B8(u8 *);
int ov59_02239EA8(u8 *);
void ov59_02238C7C(u8 *);

int TextPrinterCheckActive(u8);
int System_GetTouchNew(void);
void PlaySE(int);
void TextFlags_SetCanTouchSpeedUpPrint(int);
void Main_SetVBlankIntrCB(void *, void *);
void HBlankInterruptDisable(void);
void GfGfx_DisableEngineAPlanes(void);
void GfGfx_DisableEngineBPlanes(void);
void sub_0200FBF4(int, int);
void ResetVisibleHardwareWindows(int);
int sub_02031C08(void *);
int sub_02031CE8(void *);
void sub_02031CEC();
int sub_02031FE8(void *);
int sub_02031D80(void *);
void sub_02031DA0(void *, void *);
int sub_02031CA0(void *);
int ApricornBox_CountApricorn(void *, int);
void Sprite_SetPositionXY(void *, s16, s16);
void Sprite_SetAnimActiveFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_ResetAnimCtrlState(void *);
void FillWindowPixelBuffer(void *, int);
u32 FontID_String_GetWidth(int, void *, int);
void AddTextPrinterParameterizedWithColor();
void ScheduleWindowCopyToVram(void *);
void ReadMsgDataIntoString(void *, int, void *);
void ov59_0223892C(u8 *, u8);
void ov59_02238C40(u8 *, int);
void Sprite_SetDrawFlag(void *, int);
void ClearWindowTilemapAndScheduleTransfer(void *);
void BufferIntegerAsString(void *, int, int, int, int, int);
void StringExpandPlaceholders(void *, void *, void *);
void GfGfxLoader_LoadScrnDataFromOpenNarc();
void FillBgTilemapRect();
void ScheduleBgTilemapBufferTransfer(void *, int);

#define R18_U8(p, offset)  (*(u8 *)((u8 *)(p) + (offset)))
#define R18_U16(p, offset) (*(u16 *)((u8 *)(p) + (offset)))
#define R18_U32(p, offset) (*(u32 *)((u8 *)(p) + (offset)))
#define R18_PTR(p, offset) (*(void **)((u8 *)(p) + (offset)))

#endif
