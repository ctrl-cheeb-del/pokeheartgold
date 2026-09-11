#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
void ClearWindowTilemapAndCopyToVram(void *);void RemoveWindow(void *);void DestroyMsgData(void *);void MessageFormat_Delete(void *);void String_Delete(void *);void ov85_021E7350(void *);void FillWindowPixelBuffer(void *,int);void DrawFrameAndWindow2(void *,int,int,int);void ReadMsgDataIntoString(void *,int,void *);void AddTextPrinterParameterized(void *,int,void *,int,int,int,int);void ScheduleWindowCopyToVram(void *);void BufferItemName(void *,int,int);void *String_New(int,u32);void StringExpandPlaceholders(void *,void *,void *);void ClearFrameAndWindow2(void *,int);void AddWindow(void *,void *,const void *);void DrawFrameAndWindow1(void *,int,int,int);s32 FontID_String_GetCenterAlignmentX(int,void *,int,int);void AddTextPrinterParameterizedWithColor(void *,int,void *,int,int,int,u32,int);u32 sub_0203769C(void);extern u8 ov85_021EA5AC[];
void BufferPlayersName(void *,int,int);int sub_02034818(u32);
void ov85_021E7148(void *);void ov85_021E7194(void *,int);void ov85_021E71EC(void *,int,int);void ov85_021E7274(void *,int,int);void ov85_021E72E8(void *);void ov85_021E730C(void *,int);void ov85_021E7350(void *);void ov85_021E7380(void *,void *,int,u32);void ov85_021E73D4(void *,void *,void *,int);
#endif
