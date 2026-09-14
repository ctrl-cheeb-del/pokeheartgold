#ifndef POKEHEARTGOLD_OVERLAY_40_RESIDUAL_8_RENDERER_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY_40_RESIDUAL_8_RENDERER_PRIVATE_H

#include "global.h"

#define OV40_PTR(p, off) (*(void **)((u8 *)(p) + (off)))

typedef struct Ov40WinCoords {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
} Ov40WinCoords;

typedef struct Ov40WinCoordsTable {
    Ov40WinCoords coords[10];
} Ov40WinCoordsTable;

typedef struct Ov40MsgIdTable {
    u32 ids[12];
} Ov40MsgIdTable;

typedef struct Ov40MailBuf {
    u32 v[2];
} Ov40MailBuf;

extern const Ov40WinCoordsTable ov40_02244F40;
extern const Ov40MsgIdTable ov40_02244F10;

void *NewString_ReadMsgData(void *msgData, int msgId);
void *String_New(u32 size, u32 heapId);
void String_Delete(void *str);
void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 palette, u16 baseTile);
void FillWindowPixelBuffer(void *window, u8 fillValue);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void ScheduleWindowCopyToVram(void *window);
int ov40_022306C0(void *window, void *str);
void *ov40_0222DAB0(u32 heapId);
void ov40_02230DCC(void *owner, void *value);
void BufferString(void *fmt, u32 idx, void *str, u32 a3, u32 a4, u32 a5);
void BufferMonthNameAbbr(void *fmt, u32 idx, u32 month);
void BufferCountryName(void *fmt, u32 idx, u32 country);
void BufferCityName(void *fmt, u32 idx, u32 country, u32 city);
void StringExpandPlaceholders(void *fmt, void *dst, void *src);
void MessageFormat_ResetBuffers(void *fmt);
void MessageFormat_Delete(void *fmt);
void *sub_020315B8(void *save, u32 heapId);
u32 sub_02031620(void *save);
u32 sub_0203162C(void *save);
void *sub_0203164C(void *save, void *mail, u32 heapId);
u32 sub_020316F0(void *save);
void *MailMsg_GetExpandedString(void *mail, u32 heapId);

void ov40_0222E09C(void *windowData, void *owner);

#endif
