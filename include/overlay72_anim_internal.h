#ifndef LOCAL_OV72_R28_H
#define LOCAL_OV72_R28_H
#include "global.h"
extern void *NewString_ReadMsgData(void *, int);
extern void FillWindowPixelBuffer(void *, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void CopyWindowToVram(void *);
extern void String_Delete(void *);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void BgTilemapRectChangePalette(void *, int, int, int, int, int, int);
extern void ScheduleBgTilemapBufferTransfer(void *, int);
extern void ov72_0223B0C4(void *);
extern void ov72_0223B1C8(void *);
extern void ov72_0223B2E4(void *);
extern int (*ov72_0223B7FC[])(void *);
void ov72_0223AED0(void *, u8, u8, u8);
void ov72_0223AD20(void *, void *, int);
void ov72_0223AD64(void *);
void ov72_0223AE20(void *, int);
int ov72_0223AE6C(void *);
void ov72_0223AF1C(void *);
int ov72_0223AF48(void *);
#endif
