#ifndef TO40_R40_OVERLAY72_PRIVATE_H
#define TO40_R40_OVERLAY72_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8_AT(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov72SelectionTail {
    u8 state;
    u8 pad_01;
    s8 cursor;
    s8 page;
    s8 result;
    u8 pad_05[0x4d];
    u16 delay;
    u16 enabled;
} Ov72SelectionTail;

extern int (*const ov72_0223B744[])(void *);
extern void BufferIntegerAsString(void *, int, int, int, int, int);
extern void ClearFrameAndWindow2(void *, int);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern void Sprite_SetDrawFlag(void *, int);
extern void ov72_022386F4(void *);
extern void ov72_02238750(void *, int, u32);
extern void *String_New(u32, int);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void StringExpandPlaceholders(void *, void *, const void *);
extern void FillWindowPixelBuffer(void *, int);
extern void DrawFrameAndWindow1(void *, int, int, int);
extern u8 AddTextPrinterParameterized(void *, int, const void *, int, int, int, void *);
extern void String_Delete(void *);
extern int IsPaletteFadeFinished(void);
extern void ov72_02238730(void *, int, u32);
extern void ov72_02238B18(void *, int);
extern void ov72_0223ACA8(void *);
extern void ov72_0223AD20(void *, void *, int);
extern void ToggleBgLayer(int, int);

void ov72_0223A460(void *work, int message);
void ov72_0223A4DC(void *work, int message, int unused);
int ov72_0223A520(void *work, u8 kind, u8 value);
int ov72_0223A588(void *work);
int ov72_0223A5B4(void *work);
int ov72_0223A5E0(void *work);
void ov72_0223A680(void *work);

#endif
