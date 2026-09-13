#ifndef OV15_R16_PRIVATE_H
#define OV15_R16_PRIVATE_H

#include "global.h"

extern u8 gSystem[];

BOOL TextPrinterCheckActive(u8);
void ClearFrameAndWindow2(void *, BOOL);
void ClearWindowTilemapAndScheduleTransfer(void *);
void FillWindowPixelBuffer(void *, u32);
void sub_0200E5D4(void *, BOOL);
void *NewString_ReadMsgData(void *, u32);
void BufferIntegerAsString(void *, u32, s32, u32, u32, BOOL);
void StringExpandPlaceholders(void *, void *, void *);
void String_Delete(void *);
void ScheduleWindowCopyToVram(void *);

s32 ov15_021FA074(void *);
void ov15_021FB518(void *);
void ov15_021FD574(void *, u32, u32, u32);
void ov15_021FD788(void *, u32);
void ov15_021FE868(void *);
void ov15_021FED3C(void *);
s32 ov15_021FEF48(void *, u32);
void ov15_021FF29C(void *, u32);
void ov15_021FF364(void *, s32, s32, s32);
void ov15_021FF7FC(void *);
void ov15_021FF834(void *);
void ov15_021FFF24(void *);
void ov15_021FFFDC(void *, u32);
void ov15_02200140(void *, void *, s32, u32);
void ov15_02200300(void *, u32, u32);
void ov15_02200428(void *);
void ov15_02200458(void *, u32);
void ov15_022004DC(void *, u32);

s32 ov15_021FC784(void *);
s32 ov15_021FCD80(void *);
s32 ov15_021FCFC8(void *);
s32 ov15_021FD058(void *);

#endif
