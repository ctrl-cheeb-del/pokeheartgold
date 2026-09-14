#ifndef TO47_OVERLAY14_BOX_MESSAGE_ACTIONS_PRIVATE_H
#define TO47_OVERLAY14_BOX_MESSAGE_ACTIONS_PRIVATE_H

#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

extern void *ov14_021E60C0(void *, u32, u32);
extern void ov14_021F6698(void *, u32, u32);
extern void *ov14_021F6628(void);

extern void BufferBoxMonNickname(void *, u32, void *);
extern void BufferItemName(void *, u32, u32);

extern void *NewString_ReadMsgData(void *, u32);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void String_Delete(void *);
extern void DestroyMsgData(void *);

extern void FillWindowPixelBuffer(void *, u32);
extern void AddTextPrinterParameterizedWithColor(void *, u32, void *, s32, s32, u32, u32, void *);

void ov14_021F685C(void *, u32, u32, u32);
void ov14_021F68C0(void *, u32, u32);
void ov14_021F6928(void *, u32, u32);

#endif
