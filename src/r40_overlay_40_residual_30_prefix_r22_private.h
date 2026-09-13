#ifndef SOL_R40_FOLLOWUP_OV40_30_PREFIX_PRIVATE_H
#define SOL_R40_FOLLOWUP_OV40_30_PREFIX_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
void FillWindowPixelBuffer(void *, int);
void ScheduleWindowCopyToVram(void *);
void *String_New(int, int);
int ov40_022371D4(void *, u32);
void GetSpeciesNameIntoArray(int, int, u16 *);
void CopyU16ArrayToString(void *, u16 *);
int ov40_022306C0(void *, void *);
u8 AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, void *);
void String_Delete(void *);
#endif
