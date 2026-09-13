#ifndef OVERLAY_68_RESIDUAL_9_R40_PRIVATE_H
#define OVERLAY_68_RESIDUAL_9_R40_PRIVATE_H

#include "overlay68_helpers_internal.h"

typedef struct Ov68TileSourceR9 {
    u16 width;
    u16 height;
    u8 pad04[8];
    u8 data[];
} Ov68TileSourceR9;

void CopyToBgTilemapRect(void *bgConfig, u32 bgId, u32 x, u32 y, u32 width, u32 height, const void *src, u32 srcX, u32 srcY, u32 srcWidth, u32 srcHeight);
void ScheduleBgTilemapBufferTransfer(void *bgConfig, u32 bgId);
void FillWindowPixelBuffer(void *window, u32 fill);
void ScheduleWindowCopyToVram(void *window);
u8 AddTextPrinterParameterizedWithColor(void *window, u32 fontId, void *str, u32 x, u32 y, u32 speed, u32 color, void *callback);
u32 GetMoveMaxPP(u16 move, u32 ppUps);
void BufferIntegerAsString(void *fmt, u32 field, s32 value, u32 digits, u32 mode, u32 charset);
void StringExpandPlaceholders(void *fmt, void *dest, const void *src);
void *ListMenuItems_New(u32 count, u32 heapId);
void ListMenuItems_AppendFromMsgData(void *items, void *msgData, s32 msgId, s32 value);
void ov68_021E66A0(MoveRelearner *d, u32 x, u32 y, u32 width, u8 height, u8 srcX, u8 srcY);
void ov68_021E66F0(MoveRelearner *d, s32 offset, s32 row);
void ov68_021E67E0(MoveRelearner *d);
void ov68_021E6820(MoveRelearner *d);

#endif
