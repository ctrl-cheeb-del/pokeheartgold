#ifndef UNK_02059820_PRIVATE_H
#define UNK_02059820_PRIVATE_H

#include "global.h"

#include "system.h"

extern void PlaySE(u16 seqNo);
extern void FillWindowPixelRect(void *window, int fill, int x, int y, int width, int height);
extern void ListMenuUpdateCursorObj(void *cursor, void *window, int x, int y);
extern void CopyWindowPixelsToVram_TextMode(void *window);
extern int WindowIsInUse(const void *window);
extern void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, int baseTile);
extern void LoadUserFrameGfx1(void *bgConfig, int bgId, int baseTile, int palette, int frame, int heapId);
extern void FillWindowPixelBuffer(void *window, int value);
extern void ReadMsgDataIntoString(void *msgData, int msgNo, void *string);
extern int AddTextPrinterParameterized(void *window, int font, void *string, int x, int y, int speed, void *callback);
extern void DrawFrameAndWindow1(void *window, int copy, int baseTile, int palette);
extern void *NewMsgDataFromNarc(int type, int narc, int fileId, int heapId);
extern void DestroyMsgData(void *msgData);
extern u32 sub_02070D90(void);
extern u32 GetMonData(void *mon, int attr, void *dst);
int sub_02059A08(void *arg);
void sub_0205993C(void *arg, int cursor);
void sub_02059820(void *arg, int cursor);

#endif
