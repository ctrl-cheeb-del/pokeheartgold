#ifndef POKEHEARTGOLD_PALETTE_FADE_STATE_INTERNAL_H
#define POKEHEARTGOLD_PALETTE_FADE_STATE_INTERNAL_H
#include "global.h"

typedef struct FadeStatus {
    u8 pad[0xc];
    u16 active;
    u8 mainDone;
    u8 subDone;
    u16 color;
    u8 tail[2];
} FadeStatus;

extern u8 _021D0EF4[4];
extern u8 _021D0EF8[4];
extern u8 _021D0EFC[12];
extern u8 _021D0F08[48];
extern u8 _021D0F38[48];
extern u8 _021D0F68[24];
extern u8 _021D0F80[180];
extern FadeStatus _021D1034;

void FadeFunc_00(void);
void FadeFunc_01(void);
void FadeFunc_02(void);
void FadeFunc_03(void);
void FadeFunc_04(void);
void FadeFunc_05(void);
void FadeFunc_06(void);
void FadeFunc_07(void);
void FadeFunc_08(void);
void FadeFunc_09(void);
void FadeFunc_10(void);
void FadeFunc_11(void);
void FadeFunc_12(void);
void FadeFunc_13(void);
void FadeFunc_14(void);
void FadeFunc_15(void);
void FadeFunc_16(void);
void FadeFunc_17(void);
void FadeFunc_18(void);
void FadeFunc_19(void);
void FadeFunc_20(void);
void FadeFunc_21(void);
void FadeFunc_22(void);
void FadeFunc_23(void);
void FadeFunc_24(void);
void FadeFunc_25(void);
void FadeFunc_26(void);
void FadeFunc_27(void);
void FadeFunc_28(void);
void FadeFunc_29(void);
void FadeFunc_30(void);
void FadeFunc_31(void);
void FadeFunc_32(void);
void FadeFunc_33(void);
void FadeFunc_34(void);
void FadeFunc_35(void);
void FadeFunc_36(void);
void FadeFunc_37(void);
void FadeFunc_38(void);
void FadeFunc_39(void);
void FadeFunc_40(void);
void FadeFunc_41(void);
void FadeFunc_42(void);
void GF_AssertFail(void);
BOOL DoFadeUpdateFrame(void *, void *, void *);
void FadeWork_UpdateFrame(void *, void *);
void sub_020100C4(void *);
void sub_0200FF5C(void *, int);
void sub_020131F4(int, int);
void GXx_SetMasterBrightness_(vu16 *, int);
u16 sub_0201002C(void *);
void sub_02010094(void *);
void sub_02013424(void *, int, int);
void sub_02013440(void *, int, int, int, int);
void sub_02013488(void *, int, int, int, int, int, int);
void sub_02013468(void *, int, int, int);
void sub_0200FE14(u32, void *);
void sub_0200FEB0(void *);
u32 sub_02010018(void *, u32);
void sub_02010064(void *);
void sub_0200FE84(void *, u32, u32, u32, u32, u32, u32, void *, void *, u32, u32);

void HandleFadeUpdateFrame(void);
BOOL IsPaletteFadeFinished(void);
void sub_0200FB70(void);
void ResetVisibleHardwareWindows(int);
void SetMasterBrightnessNeutral(int);
void sub_0200FBF4(int, u16);
void sub_0200FC20(u16);
void sub_0200FCDC(u16);
void sub_0200FC60(int, u16);
void SetMasterBrightness(int, int);
void HandleEndFade(void *);
void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
#endif
