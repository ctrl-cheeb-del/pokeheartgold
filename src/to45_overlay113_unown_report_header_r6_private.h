#ifndef TO45_OVERLAY113_UNOWN_REPORT_HEADER_R6_PRIVATE_H
#define TO45_OVERLAY113_UNOWN_REPORT_HEADER_R6_PRIVATE_H

#include "global.h"

typedef struct To45Ov113State {
    u8 raw[0x200];
} To45Ov113State;

#define TO45_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void ov113_021E6238(To45Ov113State *state, void *screen, u32 bg);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL flag);
void ReadMsgDataIntoString(void *msgData, s32 id, void *string);
void ov113_021E629C(void *window, void *string, int x, u16 y);
u32 FontID_String_GetWidth(u32 fontId, void *string, u32 letterSpacing);
void BufferIntegerAsString(void *format, u32 index, s32 value, u32 digits, u32 mode, BOOL charset);
void StringExpandPlaceholders(void *format, void *dest, void *source);
void ov113_021E5FC0(To45Ov113State *state);

#endif
