#ifndef PRIVATE_UNK_02058D4C_H
#define PRIVATE_UNK_02058D4C_H
#include "global.h"
BOOL WindowIsInUse(void *);
void DialogBox_AddWindowToLayer3(void *, void *, int);
void *Save_PlayerData_GetOptionsAddr(void *);
void DialogBox_LoadFrame(void *, void *);
void DialogBox_Clear(void *);
u8 DialogBox_PrintMessage(void *, void *, void *, int);
void ClearFrameAndWindow2(void *, int);
void ClearWindowTilemapAndCopyToVram(void *);
void RemoveWindow(void *);
void InitWindow(void *);
void *Heap_AllocAtEnd(int, u32);
void *MessageFormat_New(int);
void *NewMsgDataFromNarc(int, int, int, int);
void *String_New(u32, int);
void *ListMenuCursorNew(int);
u8 sub_0203993C(void);
u16 sub_0203769C(void);
void *sub_02034818(int);
u32 sub_02059B08(void);
void *SaveArray_Party_Alloc(int);
void Party_InitWithMaxSize(void *, int);
void FieldSystem_CreateTask(void *, BOOL (*)(void *), void *);
BOOL sub_02058D4C(void *);
u8 sub_02059478(void *, void *);
void sub_020594C8(void *, BOOL);
void sub_02059538(void *, void *);
#endif
