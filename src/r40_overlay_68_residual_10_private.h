#ifndef OVERLAY_68_RESIDUAL_10_R40_PRIVATE_H
#define OVERLAY_68_RESIDUAL_10_R40_PRIVATE_H

#include "overlay68_helpers_internal.h"

extern u32 ov68_021E7DA4[][11];

void *Mon_GetBoxMon(void *mon);
void BufferBoxMonNickname(void *fmt, u32 field, void *boxMon);
void BufferMoveName(void *fmt, u32 field, u32 move);
void BufferPlayersName(void *fmt, u32 field, void *profile);
void StringExpandPlaceholders(void *fmt, void *dest, const void *src);
void FillWindowPixelBuffer(void *window, u32 fill);
void ScheduleWindowCopyToVram(void *window);
void ClearWindowTilemapAndScheduleTransfer(void *window);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
u32 GetMoveAttr(u32 move, u32 attr);
void ReadMsgDataIntoString(void *msgData, u32 msgId, void *dest);
void ov68_021E6234(MoveRelearner *d, u32 windowNo, u32 fontId, u32 color, u32 align, u8 y);
void ov68_021E62D4(MoveRelearner *d, u32 msgId, s32 value, u32 digits, u8 mode);
void ov68_021E68D4(MoveRelearner *d, s32 move);
void ov68_021E7124(MoveRelearner *d, u16 move);
void ov68_021E6A2C(MoveRelearner *d, u32 msgNo);

#endif
