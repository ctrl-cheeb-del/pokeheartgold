#ifndef SOL_R40_OVERLAY40_UNMATCHED4_PRIVATE_H
#define SOL_R40_OVERLAY40_UNMATCHED4_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

void *ov40_0222DAB0(u32 heapId);
void *String_New(u32 size, u32 heapId);
void *sub_020315B8(u32 value, u32 heapId);
void ov40_02230DCC(void *work, void *string);
void *NewString_ReadMsgData(void *msgData, int msgId);
void BufferString(void *format, u32 index, void *string, int a3, int a4, int a5);
void StringExpandPlaceholders(void *format, void *dest, void *src);
void String_Delete(void *string);
void MessageFormat_Delete(void *format);
void FillWindowPixelBuffer(void *window, int fill);
u8 AddTextPrinterParameterizedWithColor(void *window, int fontId, void *string, u32 x, u32 y, u32 speed, u32 color, void *callback);
void ScheduleWindowCopyToVram(void *window);
void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, int baseTile);
int ov40_022306C0(void *window, void *string);
void ov40_022442F0(void *p, int msgId, int idx);
void ov40_022443B4(void *p);

#endif
