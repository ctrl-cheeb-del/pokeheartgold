#ifndef TO47_R4_OV40_WINDOW_LIST_MIDDLE_PRIVATE_H
#define TO47_R4_OV40_WINDOW_LIST_MIDDLE_PRIVATE_H

#include "global.h"

#define PTR(p, off)   (*(void **)((u8 *)(p) + (off)))
#define SWORD(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define SHALF(p, off) (*(s16 *)((u8 *)(p) + (off)))

void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void CopyWindowToVram(void *);
void FillWindowPixelBuffer(void *, u8);
void GF_AssertFail(void);
void PlaySE(u16);
void ov40_0222F8C0(void *);
int ov40_0222EFD8(void *, void *, void **);
void ov40_0222F5EC(void *, s16);

#endif
