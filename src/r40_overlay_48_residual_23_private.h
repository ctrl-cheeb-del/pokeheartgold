#ifndef OVERLAY_48_RESIDUAL_23_PRIVATE_H
#define OVERLAY_48_RESIDUAL_23_PRIVATE_H

#include "global.h"

#define U8AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define S16AT(p, n) (*(s16 *)((u8 *)(p) + (n)))
#define U32AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTRAT(p, n) (*(void **)((u8 *)(p) + (n)))
#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))

void ov48_0225A680(void *unused, void *scroll);
void ov48_0225A6DC(void *p, void *context);
void ov48_0225A768(void *p);
void ov48_0225A790(void *p, u32 index, void *record, void *strings);

extern void AddWindowParameterized(void *, void *, u32, u32, u32, u32, u32, u32, u32);
extern void FillWindowPixelBuffer(void *, u32);
extern void CopyWindowToVram(void *);
extern void RemoveWindow(void *);
extern void GF_AssertFail(void);
extern u8 ov48_0225B038(u32 value);
extern void *ov48_0225B0C4(void *strings, s32 messageId);
extern void *ov48_0225B0E0(void *strings, u32 country);
extern void *ov48_0225B108(void *strings, u32 country, u32 city);
extern u8 AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, void *);
extern u32 ov48_0225B1D8[];

#endif
