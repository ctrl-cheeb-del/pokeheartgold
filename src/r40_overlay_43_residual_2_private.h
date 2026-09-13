#ifndef SOL_R40_NIGHT_OVERLAY43_RESIDUAL2_PRIVATE_H
#define SOL_R40_NIGHT_OVERLAY43_RESIDUAL2_PRIVATE_H
#include "global.h"
void ov43_0222A48C(void *, void *, int);
void ov43_0222B0A0(void *, void *, void *, int);
void ov43_0222B944(void *, void *, void *, int);
void ov43_0222CD3C(void *, void *, void *, int);
void ov43_0222CE48(void *, void *, void *, int);
void ov43_0222D584(void *, void *, void *, int);
void Main_SetVBlankIntrCB(void (*)(void *), void *);
void HBlankInterruptDisable(void);
void ov43_0222A148(void *);
void ov43_0222B1D8(void *, void *, void *);
void ov43_0222BAB8(void *, void *, void *);
void ov43_0222CD40(void *, void *, void *);
void ov43_0222D008(void *, void *, void *);
void ov43_0222D610(void *, void *, void *);
void ov43_0222A520(void *);
void InitWindow(void *);
void AddWindowParameterized(void *, void *, u8, u8, u8, u8, u8, u8, u16);
void FillWindowPixelBuffer(void *, u8);
void *String_New(u32, int);
int MenuInputStateMgr_GetState(void *);
void *Save_PlayerData_GetOptionsAddr(void *);
u8 Options_GetTextFrameDelay(void *);
u8 Options_GetFrame(void *);
int Options_GetButtonMode(void *);
void TextFlags_SetCanABSpeedUpPrint(BOOL);
void TextFlags_SetCanTouchSpeedUpPrint(BOOL);
void ov43_0222A154(void *, int);
void ov43_0222A1DC(void *);
void ov43_0222A24C(void *, void *, u8, u8, u8, u8, u8, u8, u16, u8);
void ov43_0222A290(void *, void *, int);
#endif
