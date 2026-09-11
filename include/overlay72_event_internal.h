#ifndef LOCAL_OV72_R22_H
#define LOCAL_OV72_R22_H
#include "global.h"

#include "system.h"
extern void sub_0203A914(void *);
extern void sub_0203946C(void);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern int ov72_02238668(void *);
extern void sub_0200E5D4(void *, int);
extern BOOL TextPrinterCheckActive(u8);
extern void *NewString_ReadMsgData(void *, int);
extern void StringExpandPlaceholders(void *, void *, const void *);
extern void String_Delete(void *);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void FillWindowPixelBuffer(void *, int);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern u8 AddTextPrinterParameterized(void *, int, const void *, int, int, int, void *);
extern int FontID_String_GetWidth(int, const void *, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, const void *, int, int, int, u32, void *);
extern void ov72_0223AF1C(void *);
typedef struct Ov72Cfg {
    u32 source;
    u32 value;
    u8 pad08[0x20];
    u32 kind;
    u8 b28;
    u8 pad29;
    u8 b2A;
    u8 b2B;
    u8 b2C;
    u8 b2D;
    u8 b2E;
    u8 pad2F;
    u32 final;
} Ov72Cfg;
typedef struct Ov72Work {
    u8 pad0000[0x136C];
    Ov72Cfg cfg;
} Ov72Work;
int ov72_0223A200(Ov72Work *);
extern void *ov00_021E6A70(int, int);
extern void ov72_0223A4DC(void *, void *, int);
extern void ov72_0223A444(void *);
extern void ov72_02238680(void *, int, int);
int ov72_0223A06C(void *);
int ov72_0223A014(void *);
int ov72_0223A044(void *);
int ov72_0223A1AC(void *);
int ov72_0223A1CC(void *);
void ov72_0223A280(void *, void *, int, int);
int ov72_0223A2E8(void *);
int ov72_0223A314(void *);
void ov72_0223A350(void *, void *, int, int, int);
int ov72_0223A3A8(const u8 *, const void *, int, int, int, int);
void ov72_0223A3E0(void *, const void *, int, int, int, u32);
#endif
