#ifndef TO40_SOL_R22_PRIVATE_H
#define TO40_SOL_R22_PRIVATE_H
#include "global.h"
extern u8 ov43_0222F0C0[];extern void *GfGfxLoader_GetScrnDataFromOpenNarc(void*,int,int,void*,int);
extern void YesNoPrompt_Destroy(void*);extern void TouchscreenListMenuSpawner_Destroy(void*);extern void String_Delete(void*);extern void RemoveWindow(void*);extern void Heap_Free(void*);
extern int TextPrinterCheckActive(u8);extern void TextFlags_SetCanTouchSpeedUpPrint(int);extern void RemoveTextPrinter(u8);extern void ClearWindowTilemapAndScheduleTransfer(void*);
extern void *sub_0202C6F4(void*);extern void *PlayerProfile_New(int);extern void *sub_0202C254(void*,int);extern void *sub_0202C298(void*,int);extern void Save_Profile_PlayerName_Set(void*,void*);extern void BufferPlayersName(void*,int,void*);
void ov43_0222A998(void*,int);
void ov43_0222A960(void*);void ov43_0222A9D8(void*);void ov43_0222AA70(void*);void ov43_0222AB20(void*,void*,int,int);void ov43_0222AB5C(void*,void*,int,int);
#endif
