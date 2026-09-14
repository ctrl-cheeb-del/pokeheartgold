#ifndef TO45_OV80_E5B0_PRIVATE_H
#define TO45_OV80_E5B0_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

typedef struct String String;
typedef struct SysTask SysTask;

void *FrontierSystem_GetFrontierMap(void *);
String *String_New(u32, u32);
void ReadMsgDataIntoString(void *, u32, String *);
void StringExpandPlaceholders(void *, String *, String *);
void String_Delete(String *);
u32 FontID_String_GetWidth(u32, String *, u32);
BOOL IsPaletteFadeFinished(void);
void *Handle2dMenuInput(void *);
BOOL System_GetTouchNew(void);
u32 Get2dMenuSelection(void *);
void ov80_0222E8FC(void *);
void ov80_0222EE14(void *, u16, u32);
void PlaySE(u32);
void Delete2dMenu(void *, u32);
void sub_0200E5D4(void *, u32);
void RemoveWindow(void *);
void DestroyMsgData(void *);
void SysTask_Destroy(SysTask *);
void Heap_Free(void *);
void ov80_0222E690(void *, u32, u16, void *);
u32 ov80_0222E714(void *);
void ov80_0222E754(void *);
void ov80_0222E88C(void *);

#endif
