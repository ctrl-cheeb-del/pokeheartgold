#ifndef POKEHEARTGOLD_OVERLAY83_SUMMARY_DISPLAY_R20_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY83_SUMMARY_DISPLAY_R20_PRIVATE_H

#include "global.h"

#include "overlay83_sol_partial_internal.h"

void *NewString_ReadMsgData(void *msgData, int msgNo);
void StringExpandPlaceholders(void *format, void *dest, void *src);
void String_Delete(void *string);
void FillWindowPixelBuffer(void *window, int fillValue);
void CopyWindowPixelsToVram_TextMode(void *window);
void ov83_02247998(void *window, void *string, int x, int y, int color, int a, int b);
void ov83_022479E4(void *window, void *msgData, int msgNo, int x, int y, int a, int color, int b);
void ov83_02241E18(void *work);
void ov83_022421E0(void *work, int value);
void ov83_02247668(void *a, void *b, u16 c, void *d);

void ov83_02241DD8(u8 *work, void *window, void *msgData, int msgNo, int x, int y, int color, int a, int b);
void ov83_02241FF0(u8 *work);
void ov83_02242814(u8 *work, int value);

int ov80_02237B24(int value, int mode);
void *Party_GetMonByIndex(void *party, int index);
u32 GetMonData(void *mon, int field, void *dest);
u32 ov80_0222A43C(u16 a, u16 b);
void ScheduleWindowCopyToVram(void *window);
void ClearWindowTilemapAndScheduleTransfer(void *window);

void ov83_02241B30(u8 *work);
void ov83_02242844(u8 *work, int value);

#endif
