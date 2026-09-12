#ifndef POKEHEARTGOLD_OVERLAY40_WINDOW_LIST_R12_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY40_WINDOW_LIST_R12_PRIVATE_H

#include "global.h"

#define OV40_PTR(p, off) (*(void **)((u8 *)(p) + (off)))
#define OV40_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define OV40_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))

u32 sub_02031620(void *p);
u32 sub_0203162C(void *p);
void *NewString_ReadMsgData(void *msgData, int msgId);
void *ov40_0222DAB0(u32 heapId);
void *String_New(u32 size, u32 heapId);
void BufferCityName(void *fmt, u32 idx, u32 country, u32 city);
void BufferCountryName(void *fmt, u32 idx, u32 country);
void StringExpandPlaceholders(void *fmt, void *dst, void *src);
void String_Delete(void *str);
void MessageFormat_Delete(void *fmt);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void ScheduleWindowCopyToVram(void *window);
void PlaySE(u16 seq);
void ov40_0222F878(void *p);

void ov40_0222E7F0(void *windowData, void *owner);
void ov40_0222F6D0(void *p, s16 value);

#endif
