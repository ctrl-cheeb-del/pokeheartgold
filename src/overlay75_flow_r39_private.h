#ifndef SOL40_R39_OV75_9_PRIVATE_H
#define SOL40_R39_OV75_9_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
void FillWindowPixelBuffer(void *, int);
void *NewString_ReadMsgData(void *, int);
int String_GetLength(void *);
void *String_New(int, int);
void String_GetLineN(void *, void *, int);
void AddTextPrinterParameterized(void *, int, void *, int, int, int, int);
void String_Delete(void *);
void CopyWindowToVram(void *);
int ov75_02249534(int);
int YesNoPrompt_HandleInput(void *);
void YesNoPrompt_Destroy(void *);
void ov75_022494CC(void *, void *, int, int, int);
int ov75_022480B8(void *);
void ov75_02247854(void *, int, int);
void *ov75_02247890(void *, int, int);
#endif
