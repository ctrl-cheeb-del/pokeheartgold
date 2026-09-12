#ifndef OVERLAY40_CURRENCY_DISPLAY_R38_PRIVATE_H
#define OVERLAY40_CURRENCY_DISPLAY_R38_PRIVATE_H

#include "global.h"

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void *String_New(u32 size, u32 heapId);
void String_Delete(void *str);
void GF_AssertFail(void);
void *ov40_0222DAB0(u32 heapId);
void *NewString_ReadMsgData(void *msgData, u32 messageId);
void String16_FormatInteger(void *str, int value, u32 digits, int mode, BOOL charset);
void BufferString(void *format, u32 index, void *str, u32 a3, u32 a4, u32 a5);
void StringExpandPlaceholders(void *format, void *dst, void *src);
void FillWindowPixelBuffer(void *window, u8 fillValue);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void ScheduleWindowCopyToVram(void *window);
void MessageFormat_ResetBuffers(void *format);
void MessageFormat_Delete(void *format);

void ov40_02242E4C(u8 *work, u8 *context);
void *ov40_02242FAC(u32 heapId, u32 stringLength, const u32 *values, u32 finalValue);
void ov40_02242FF8(u8 *work);
void ov40_0224301C(u8 *work, u32 value);

#endif
