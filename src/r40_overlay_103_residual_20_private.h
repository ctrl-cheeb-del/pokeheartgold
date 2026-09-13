#ifndef R40_OV103_R20_PRIVATE_H
#define R40_OV103_R20_PRIVATE_H
#include "global.h"
typedef struct R40Ov103Work20 {
    u8 pad[0xC];
    u8 *ctx;
    u8 pad10[0xC];
    u16 row;
} R40Ov103Work20;
extern void FillWindowPixelBuffer(void *, u8);
extern void ReadMsgDataIntoString(void *, u32, void *);
extern void ov103_021EE3E4(void *, void *, u32, u32, u32, u32, u32);
extern u32 FontID_String_GetWidth(u32, void *, u32);
extern void BufferIntegerAsString(void *, int, u32, u32, u32, u32);
extern void *NewString_ReadMsgData(void *, u32);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void String_Delete(void *);
extern void ScheduleWindowCopyToVram(void *);
void ov103_021EE644(R40Ov103Work20 *);
#endif
