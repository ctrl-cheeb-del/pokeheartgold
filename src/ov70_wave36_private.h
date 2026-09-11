#ifndef OV70_R14_H
#define OV70_R14_H
#include "global.h"
typedef u8 R14Work;
#define P(w,o) (*(void **)((w)+(o)))
#define U32(w,o) (*(u32 *)((w)+(o)))
#define S32(w,o) (*(s32 *)((w)+(o)))
extern void BeginNormalPaletteFade(u32,u32,u32,u32,u32,u32,u32);
extern void *ov70_02238C14(void *,int,int,int,int);
extern void Sprite_SetDrawFlag(void *,int);
extern BOOL TextPrinterCheckActive(u8);
extern int ov70_02238C8C(R14Work *);
extern void YesNoPrompt_Destroy(void *);
extern void ClearFrameAndWindow2(void *,BOOL);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void ToggleBgLayer(int,BOOL);
extern void Sprite_SetAnimActiveFlag(void *,BOOL);
extern void ov70_02238E50(R14Work *,int,int);
extern void ReadMsgDataIntoString(void *,u32,void *);
extern void FillWindowPixelBuffer(void *,u8);
extern void DrawFrameAndWindow2(void *,BOOL,u16,u8);
extern u8 AddTextPrinterParameterized(void *,int,void *,u32,u32,u32,void *);
extern void *NewString_ReadMsgData(void *,u32);
extern u8 AddTextPrinterParameterizedWithColor(void *,int,void *,u32,u32,u32,u32,void *);
extern void String_Delete(void *);
extern void ov70_0223A0C4(R14Work *);extern void ov70_0223A224(R14Work *);extern void ov70_0223A1A0(R14Work *);extern void ov70_02239F78(void *);extern void ov70_02238E58(R14Work *);
extern void ov70_022392BC(void *);extern void FreeBgTilemapBuffer(void *,int);
extern int (*ov70_022464A8[])(R14Work *);
int ov70_02239990(R14Work *);int ov70_022399D8(R14Work *);int ov70_02239AAC(R14Work *);int ov70_02239ACC(R14Work *);int ov70_02239A10(R14Work *);void ov70_02239B84(R14Work *,u32,u32);void ov70_02239BDC(R14Work *,u32,u32);void ov70_02239C34(void *,void *,u32,u32);int ov70_02239E68(R14Work *);BOOL ov70_02239E7C(R14Work *);void ov70_02239F78(void *);
#endif
