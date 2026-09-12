#ifndef SOL37_OV70_R44_PRIVATE_H
#define SOL37_OV70_R44_PRIVATE_H

#include "global.h"

typedef u8 Ov70Work;

#define PTR(w, o) (*(void **)((w) + (o)))
#define U32(w, o) (*(u32 *)((w) + (o)))
#define S32(w, o) (*(s32 *)((w) + (o)))
#define S16(w, o) (*(s16 *)((w) + (o)))

extern u8 gSystem[];
extern const u32 ov70_0224600C[];

int ov00_021E6A70(int, int);
int ov00_021ECDC8(void);
int ov00_021EC11C(int *, int *);
void ov00_021EC210(void);
int ov00_021EC8D8(void);
void ov00_021FA0D8(void);
void ov00_021ED9B4(void);
void sub_020399EC(void);
void ov70_022382C0(Ov70Work *);
BOOL ov70_02237F38(void);
int ov70_02237F58(void);
void sub_0203189C(void *, void *);
void ov70_02238304(void *, void *);
u32 sub_0202C08C(void *);
u32 Save_SysInfo_GetDwcProfileId(void *);
void Save_SysInfo_SetDwcProfileId(void *, u32);
u64 DWC_CreateFriendKey(u32);
void ov70_022378C0(u32, u32, u32);
void ov70_022451A8(Ov70Work *, int, int);
void sub_0200E5D4(void *, int);
void sub_0203A914(void);
void ov70_02238F80(Ov70Work *);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
int ov70_02238C8C(Ov70Work *);
void YesNoPrompt_Destroy(void *);
void ov70_02238E50(Ov70Work *, int, int);
BOOL TextPrinterCheckActive(u8);
void sub_0203946C(void);
void *ov70_02238C14(void *, int, int, int, int);
void *NewString_ReadMsgData(void *, int);
void StringExpandPlaceholders(void *, void *, void *);
void String_Delete(void *);
void FillWindowPixelBuffer(void *, int);
void DrawFrameAndWindow2(void *, int, int, int);
u8 AddTextPrinterParameterized(void *, int, void *, int, int, int, void *);
int FontID_String_GetWidth(int, void *, int);
u8 AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, void *);

int ov70_02244CA8(Ov70Work *);
int ov70_02244954(Ov70Work *);
int ov70_02244A04(Ov70Work *);
int ov70_02244A4C(Ov70Work *);
int ov70_02244A68(Ov70Work *);
int ov70_02244B20(Ov70Work *);
int ov70_02244B54(Ov70Work *);
int ov70_02244CCC(Ov70Work *);
int ov70_02244D08(Ov70Work *);
int ov70_02244D44(Ov70Work *);
int ov70_02244D80(Ov70Work *);
int ov70_02244E44(Ov70Work *);
void ov70_02238D84(Ov70Work *, int, int);
int ov70_02244F14(Ov70Work *);
int ov70_02244F34(Ov70Work *);
int ov70_02244F68(Ov70Work *);
void ov70_02244FA4(Ov70Work *, void *, int, int, int);
int ov70_02245018(void *, void *, int, int, int, int);
void ov70_02245050(void *, void *, int, int, int, int);
void ov70_02245084(void *, void *, int, int, int, int);
void ov70_022450B8(void *, void *, int, int, int, int);
void ov70_022450EC(void *, void *, int);

#endif
