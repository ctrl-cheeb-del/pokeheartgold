#ifndef OV40_R12_PRIVATE_H
#define OV40_R12_PRIVATE_H

#include "global.h"

#define PTR(p, off)   (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off)  (*(u32 *)((u8 *)(p) + (off)))
#define SWORD(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define SHALF(p, off) (*(s16 *)((u8 *)(p) + (off)))

void GF_AssertFail(void);
void PlaySE(u16 seq);
void ov40_0222F8C0(void *p);
void ov40_0222F878(void *p);
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
void FillWindowPixelBuffer(void *window, u8 value);
void InitWindow(void *window);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void CopyWindowToVram(void *window);
BOOL TouchscreenHitbox_TouchNewIsIn(const void *hitbox);
void ov40_02230944(void *p);
void ov40_0222E7F0(void *windowData, void *owner);
void ov40_0222E8C4(void *, void *, void *);
void ov40_0222EED0(void *, void *, void *, void **);
int ov40_0222EFD8(void *p, void *owner, void **items);
void *ov40_0222F38C(void *p, void *owner);
void ov40_0222F5EC(void *p, s16 value);
void ov40_0222F6D0(void *p, s16 value);

#endif
