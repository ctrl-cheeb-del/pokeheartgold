#ifndef TO40_OVERLAY_69_RESIDUAL_6_PRIVATE_H
#define TO40_OVERLAY_69_RESIDUAL_6_PRIVATE_H
#include "global.h"
typedef struct Window Window;
typedef struct WindowTemplate WindowTemplate;
extern void *String_New(u32, u32);
extern void String_Delete(void *);
extern void AddWindow(void *, void *, const void *);
extern void FillWindowPixelRect(void *, int, int, int, int, int);
extern void DrawFrameAndWindow1(void *, int, int, int);
extern void BufferCountryName(void *, int, int);
extern void BufferCityName(void *, int, int, int);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void AddTextPrinterParameterized(void *, int, void *, int, int, int, void *);
extern void CopyWindowToVram(void *);
extern void ov69_021E7520(void *, int, void *, void *, int);
extern const u8 ov69_021E764C[];
void ov69_021E6A8C(u8 *work);
void ov69_021E6B5C(u8 *work, void *arg, int kind);
#endif
