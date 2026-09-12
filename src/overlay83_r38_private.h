#ifndef SOL40_R38_OV83_11_PRIVATE_H
#define SOL40_R38_OV83_11_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S16_AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

void FillWindowPixelBuffer(void *, u8);
int GetWindowWidth(void *);
void ScheduleWindowCopyToVram(void *);
void ov83_022479E4(void *, void *, int, int, int, int, u32, int);
void ov83_02241DD8(void *, void *, void *, int, int, int, int, u32, int);
void ov83_02240C48(void *, int, int, int, int);
int ov83_02240F48(void *, int, u8);
void ov83_02247264(void *, int, int);
void ov83_022472A0(void *, int, int);
void ov83_0224755C(void *, int);
void ov83_02242894(int, u16 *, u16 *);
void ov83_02247568(void *, u16, u16);

#endif
