#ifndef LOCAL_OV73_R36_H
#define LOCAL_OV73_R36_H
#include "global.h"

#include "system.h"
extern void *ov73_021E6A70(int, int);
extern void ov73_021EA218(void *, void *, int);
extern void sub_0200E5D4(void *, int);
extern int FontID_String_GetWidth(int, const void *, int);
extern void *NewString_ReadMsgData(void *, int);
extern void StringExpandPlaceholders(void *, void *, const void *);
extern void String_Delete(void *);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern u8 AddTextPrinterParameterized(void *, int, const void *, int, int, int, void *);
void ov73_021E9F34(void *, void *, int, int);
void ov73_021E9FF8(void *, void *, int, int);
int ov73_021E9F9C(void *);
int ov73_021E9FC8(void *);
int ov73_021EA050(const u8 *, const void *, int, int, int, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, const void *, int, int, int, u32, void *);
void ov73_021EA088(void *, const void *, int, int, int, u32);
void ov73_021EA0BC(void *, const void *, int, int, int, u32);
extern void FillWindowPixelBuffer(void *, int);
extern void String16_FormatInteger(void *, int, u32, int, int);
void ov73_021EA0F0(void *, void *, int, int);
#endif
