#ifndef TO45_OVERLAY_73_RESIDUAL_20_PRIVATE_H
#define TO45_OVERLAY_73_RESIDUAL_20_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void GX_LoadBGPltt(const void *, u32, u32);
void GXS_LoadBGPltt(const void *, u32, u32);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void ov73_021EA088(void *, void *, int, int, int, u32);
void RemoveWindow(void *);
void *String_New(u32, int);
void *NewString_ReadMsgData(void *, int);
void String_Delete(void *);

#endif
