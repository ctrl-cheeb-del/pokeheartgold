#ifndef PRIVATE_H
#define PRIVATE_H

#include "global.h"

typedef struct Ov34State {
    u8 raw[0x400];
} Ov34State;

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))

void CopyToBgTilemapRect(void *, int, int, int, int, int, void *, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void ScheduleWindowCopyToVram(void *);
int ov34_0225DC0C(int, int);
int ov34_0225DC00(void *, int);
void ov34_0225E560(Ov34State *);
void *GetBgTilemapBuffer(void *, int);
void DC_FlushRange(const void *, u32);
void BgCopyOrUncompressTilemapBufferRangeToVram(void *, int, void *, u32, int);
void ov34_0225DC18(Ov34State *, int, void *);
void ov34_0225DD04(Ov34State *);

#endif
