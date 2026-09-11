#ifndef TO40_OVERLAY_39_THUMB_RESIDUAL_18_PRIVATE_H
#define TO40_OVERLAY_39_THUMB_RESIDUAL_18_PRIVATE_H
#include "global.h"
extern int FontID_String_GetWidth(void *, void *, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void *String_New(u32, u32);
extern void String_Delete(void *);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void FillWindowPixelBuffer(void *, int);
extern void DrawFrameAndWindow1(void *, int, int, int);
extern void AddTextPrinterParameterized(void *, int, void *, int, int, int, void *);
extern void BufferIntegerAsString(void *, int, int, int, int, int);
extern void ClearFrameAndWindow2(void *, int);
int ov39_02228964(u8 *, void *, int, int, int, void *);
void ov39_0222899C(void *, void *, int, int, int, u32);
void ov39_022289D0(u8 *, int);
void ov39_02228A34(u8 *, int, int);
#endif
