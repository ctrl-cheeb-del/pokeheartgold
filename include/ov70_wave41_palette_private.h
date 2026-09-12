#ifndef OV70_WAVE41_PALETTE_PRIVATE_H
#define OV70_WAVE41_PALETTE_PRIVATE_H
#include "global.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void ov70_02245050(void *, void *, int, int, int, int);
void RemoveWindow(void *);
void *String_New(int, int);
void *NewString_ReadMsgData(void *, int);
void ov70_022444E4(void *, void *);
void ov70_0224458C(void *);
void ov70_02244644(void *);
void ov70_02244670(void *);
#endif
