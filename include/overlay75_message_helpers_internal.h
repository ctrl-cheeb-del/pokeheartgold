#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
typedef struct W {
    u8 p0[0x20];
    void *fmt;
    u8 p24[0xc];
    void *msg;
    void *narc;
    void *expanded;
    u8 pad3c[4];
    void *str40;
    u32 printer;
    u8 win48[0x20];
    u8 win68[0x28];
    u32 state90;
    u32 state94;
} W;
void *NewString_ReadMsgData(void *, u32);
void StringExpandPlaceholders(void *, void *, void *);
void String_Delete(void *);
void FillWindowPixelBuffer(void *, u32);
void DrawFrameAndWindow2(void *, u32, u32, u32);
u32 AddTextPrinterParameterized(void *, u32, void *, u32, u32, u32, u32);
BOOL TextPrinterCheckActive(u8);
u32 FontID_String_GetWidth(u32, void *, u32);
void *String_New(u32, u32);
void ReadMsgDataIntoString(void *, u32, void *);
void DrawFrameAndWindow1(void *, u32, u32, u32);
void AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, u32);
void ClearFrameAndWindow2(void *, u32);
void BufferIntegerAsString(void *, u32, s32, u32, u32, u32);
void ov75_022496B8(W *, u32);
void ov75_0224971C(W *, s32, s32);
s32 ov75_0224964C(void *, u32, s32, u32, u32, void *);
BOOL ov75_02249534(u32);
void ov75_022494CC(W *, void *, u32, u32);
#endif
