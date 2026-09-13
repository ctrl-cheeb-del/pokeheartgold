#ifndef OVERLAY_68_RESIDUAL_8_R40_PRIVATE_H
#define OVERLAY_68_RESIDUAL_8_R40_PRIVATE_H

#include "overlay68_helpers_internal.h"

void BufferIntegerAsString(void *fmt, u32 field, s32 value, u32 digits, u32 mode, u32 charset);
void StringExpandPlaceholders(void *fmt, void *dest, const void *src);
u32 FontID_String_GetWidth(u32 fontId, void *str, u32 spacing);
u32 GetWindowWidth(void *window);
u8 AddTextPrinterParameterizedWithColor(void *window, u32 fontId, void *str, u32 x, u32 y, u32 speed, u32 color, void *callback);
void ov68_021E6234(MoveRelearner *d, u32 windowNo, u32 fontId, u32 color, u32 align, u8 y);
void ov68_021E62D4(MoveRelearner *d, u32 msgId, s32 value, u32 digits, u8 mode);

#endif
