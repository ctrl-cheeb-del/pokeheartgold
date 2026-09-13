#ifndef OV70_R40_PRIVATE_H
#define OV70_R40_PRIVATE_H
#include "global.h"
typedef struct Ov70State {
    u8 raw[0x1000];
} Ov70State;
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
void *String_New(int, int);
void ReadMsgDataIntoString(void *, int, void *);
void StringExpandPlaceholders(void *, void *, void *);
void FillWindowPixelBuffer(void *, int);
void DrawFrameAndWindow1(void *, int, int, int);
u32 AddTextPrinterParameterized(void *, int, void *, int, int, int, void *);
void String_Delete(void *);
void BufferIntegerAsString(void *, int, int, int, int, int);
void ClearFrameAndWindow2(void *, int);
void ov70_0224512C(Ov70State *, int);
void ov70_022451A8(Ov70State *, int, int);
#endif
